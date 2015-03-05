﻿//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#include "pch.h"
#include "MainPage.xaml.h"
#include "SampleConfiguration.h"

using namespace SDKSample;

Platform::Array<Scenario>^ MainPage::scenariosInner = ref new Platform::Array<Scenario>  
{
    // The format here is the following:
    //     { "Description for the sample", "Fully quaified name for the class that implements the scenario" }
    { "Using a custom UserControl", "SDKSample.UserAndCustomControls.Scenario1" }, 
    { "Creating a custom control", "SDKSample.UserAndCustomControls.Scenario2" },
    { "DependencyProperty", "SDKSample.UserAndCustomControls.Scenario3" },
	{ "Distributing your control", "SDKSample.UserAndCustomControls.Scenario4" }
}; 
