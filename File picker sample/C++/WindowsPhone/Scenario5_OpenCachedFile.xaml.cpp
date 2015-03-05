﻿//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// Scenario5.xaml.cpp
// Implementation of the Scenario5 class
//

#include "pch.h"
#include "Scenario5_OpenCachedFile.xaml.h"

using namespace SDKSample::FilePicker;

using namespace concurrency;
using namespace Platform;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Storage;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Provider;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Globalization::DateTimeFormatting;

Scenario5::Scenario5()
{
    InitializeComponent();
    rootPage = MainPage::Current;
    PickFileButton->Click += ref new RoutedEventHandler(this, &Scenario5::PickFileButton_Click);
    OutputFileButton->Click += ref new RoutedEventHandler(this, &Scenario5::OutputFileButton_Click);
}

/// <summary>
/// Handle the returned files from file picker
/// This method is triggered by ContinuationManager based on ActivationKind
/// </summary>
/// <param name="args">File open picker continuation activation argment. It cantains the list of files user selected with file open picker </param>
void Scenario5::PickFileButton_Click(Object^ sender, RoutedEventArgs^ e)
{
    // Clear previous returned file name, if it exists, between iterations of this scenario
    OutputFileName->Text = "";
    OutputFileContent->Text = "";
    rootPage->NotifyUser("", NotifyType::StatusMessage);

    FileOpenPicker^ openPicker = ref new FileOpenPicker();
    openPicker->FileTypeFilter->Append(".txt");

    openPicker->PickSingleFileAndContinue();
}

void Scenario5::ContinueFileOpenPicker(FileOpenPickerContinuationEventArgs^ args)
{
    if (args->Files->Size > 0)
    {
        auto file = args->Files->GetAt(0);
        fileToken = AccessCache::StorageApplicationPermissions::FutureAccessList->Add(file);
        OutputFileButton->IsEnabled = true;
        OutputFileAsync(file);
    }
    else
    {
        rootPage->NotifyUser("Operation cancelled.", NotifyType::StatusMessage);
    }
}

void Scenario5::OutputFileButton_Click(Object^ sender, RoutedEventArgs^ e)
{
    if (fileToken != nullptr)
    {
        rootPage->NotifyUser("", NotifyType::StatusMessage);

        // Windows will call the server app to update the local version of the file
        create_task(AccessCache::StorageApplicationPermissions::FutureAccessList->GetFileAsync(fileToken)).then([this](task<StorageFile^> taskResult)
        {
            try
            {
                StorageFile^ file = taskResult.get();
                OutputFileAsync(file);
            }
            catch(AccessDeniedException^)
            {
                rootPage->NotifyUser("Access is denied.", NotifyType::ErrorMessage);
            }
        });
    }
}

void Scenario5::OutputFileAsync(StorageFile^ file)
{
    create_task(FileIO::ReadTextAsync(file)).then([this, file](String^ fileContent)
    {
        OutputFileName->Text = L"Received file: " + file->Name;
        OutputFileContent->Text = L"File content:\n" + fileContent;
    });
}
