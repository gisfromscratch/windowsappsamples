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
#include "Scenario5_StylingNavButtons.xaml.h"
#include "SampleDataSource.h"

using namespace SDKSample::FlipViewCPP;
using namespace SDKSample::FlipViewData;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

Scenario5::Scenario5():bHorizontal(true)
{
    InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void Scenario5::OnNavigatedTo(NavigationEventArgs^ e)
{
    // A pointer back to the main page.  This is needed if you want to call methods in MainPage such
    // as NotifyUser()
    rootPage = MainPage::Current;

	auto sampleData = ref new FlipViewData::SampleDataSource();
	FlipView5Horizontal->ItemsSource = sampleData->Items;
	FlipView5Vertical->ItemsSource = sampleData->Items;
}

