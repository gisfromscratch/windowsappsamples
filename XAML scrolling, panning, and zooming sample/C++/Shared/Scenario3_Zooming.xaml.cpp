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
#include "Scenario3_Zooming.xaml.h"

using namespace SDKSample::ScrollViewerCPP;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

Scenario3::Scenario3()
{
    InitializeComponent();
}


// Invoked when this page is about to be displayed in a Frame.
void Scenario3::OnNavigatedTo(NavigationEventArgs^ e)
{
    rootPage = MainPage::Current;
}