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
    { "Track position", "SDKSample.GeolocationCPP.Scenario1" }, 
    { "Get position", "SDKSample.GeolocationCPP.Scenario2" },
    { "Background position", "SDKSample.GeolocationCPP.Scenario3" },
    { "Foreground geofencing", "SDKSample.GeolocationCPP.Scenario4" },
    { "Background geofencing", "SDKSample.GeolocationCPP.Scenario5" }
}; 
