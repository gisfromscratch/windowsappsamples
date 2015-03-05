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
// Scenario3.xaml.cpp
// Implementation of the Scenario3 class
//

#include "pch.h"
#include "Scenario3_SingleFolder.xaml.h"

using namespace SDKSample::FilePicker;

using namespace concurrency;
using namespace Platform;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Storage;
using namespace Windows::Storage::Pickers;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

Scenario3::Scenario3()
{
    InitializeComponent();
    rootPage = MainPage::Current;
    PickFolderButton->Click += ref new RoutedEventHandler(this, &Scenario3::PickFolderButton_Click);
}

/// <summary>
/// Handle the returned folder from folder picker
/// This method is triggered by ContinuationManager based on ActivationKind
/// </summary>
/// <param name="args">Folder picker continuation activation argment. It cantains the folder user selected with folder picker </param>
void Scenario3::PickFolderButton_Click(Object^ sender, RoutedEventArgs^ e)
{
    // Clear previous returned folder name, if it exists, between iterations of this scenario
    OutputTextBlock->Text = "";

    FolderPicker^ folderPicker = ref new FolderPicker();
    folderPicker->SuggestedStartLocation = PickerLocationId::Desktop;

    // Users expect to have a filtered view of their folders depending on the scenario.
    // For example, when choosing a documents folder, restrict the filetypes to documents for your application.
    folderPicker->FileTypeFilter->Append(".docx");
    folderPicker->FileTypeFilter->Append(".xlsx");
    folderPicker->FileTypeFilter->Append(".pptx");

    folderPicker->PickFolderAndContinue();
}

void Scenario3::ContinueFolderPicker(FolderPickerContinuationEventArgs^ args)
{
    auto folder = args->Folder;
    if (folder)
    {
        OutputTextBlock->Text = "Picked folder: " + folder->Name;
    }
    else
    {
        OutputTextBlock->Text = "Operation cancelled.";
    }
}
