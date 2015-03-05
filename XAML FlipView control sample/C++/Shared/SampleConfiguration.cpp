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

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
Platform::Array<Scenario>^ MainPage::scenariosInner = ref new Platform::Array<Scenario>  
{
    // The format here is the following:
    //     { "Description for the sample", "Fully qualified name for the class that implements the scenario" }
    { "Basic population", "SDKSample.FlipViewCPP.Scenario1" }, 
    { "Orientation", "SDKSample.FlipViewCPP.Scenario2" },
    { "Using interactive content", "SDKSample.FlipViewCPP.Scenario3" },
	{ "Creating a context control", "SDKSample.FlipViewCPP.Scenario4" }
}; 
#else
Platform::Array<Scenario>^ MainPage::scenariosInner = ref new Platform::Array<Scenario>
{
	// The format here is the following:
	//     { "Description for the sample", "Fully qualified name for the class that implements the scenario" }
	{ "Basic population", "SDKSample.FlipViewCPP.Scenario1" },
	{ "Orientation", "SDKSample.FlipViewCPP.Scenario2" },
	{ "Using interactive content", "SDKSample.FlipViewCPP.Scenario3" },
	{ "Creating a context control", "SDKSample.FlipViewCPP.Scenario4" },
	{ "Styling navigation buttons", "SDKSample.FlipViewCPP.Scenario5" }
};
#endif