﻿// Copyright (c) Microsoft. All rights reserved.


#include "pch.h"
#include "Scenario4_ProximityDeviceEvents.xaml.h"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Core;
using namespace Windows::UI::ViewManagement;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Networking::Proximity;
using namespace Windows::Storage::Streams;
using namespace Platform;
using namespace SDKSample;
using namespace Windows::UI::Xaml::Navigation;

ProximityDeviceEvents::ProximityDeviceEvents()
{
    InitializeComponent();
    m_proximityDevice = ProximityDevice::GetDefault();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void ProximityDeviceEvents::OnNavigatedTo(NavigationEventArgs^ e)
{
    // A pointer back to the main page.  This is needed if you want to call methods in ProximityDeviceEvents such
    // as NotifyUser()
    m_rootPage = MainPage::Current;
    if (m_proximityDevice != nullptr)
    {
        // Also register for device arrived and departed events to know when a proximate device is in range.
        m_arrivedToken = m_proximityDevice->DeviceArrived += ref new  DeviceArrivedEventHandler(this, &ProximityDeviceEvents::DeviceArrived, CallbackContext::Same);
        m_departedToken = m_proximityDevice->DeviceDeparted += ref new  DeviceDepartedEventHandler(this, &ProximityDeviceEvents::DeviceDeparted, CallbackContext::Same);
    }
    else
    {
        m_rootPage->NotifyUser("No proximity device found", NotifyType::ErrorMessage);
    }
}

void ProximityDeviceEvents::OnNavigatingFrom(NavigatingCancelEventArgs^ e)
{
    if (m_proximityDevice != nullptr)
    {
        m_proximityDevice->DeviceArrived -= m_arrivedToken;
        m_proximityDevice->DeviceDeparted -= m_departedToken;
    }
}
void ProximityDeviceEvents::DeviceArrived(ProximityDevice^ device) 
{
    Dispatcher->RunAsync(CoreDispatcherPriority::Low,
        ref new DispatchedHandler([this]()
    {
        ProximityDeviceEventsOutputText->Text += "Proximate device arrived\n";
    }));
}

void ProximityDeviceEvents::DeviceDeparted(ProximityDevice^ device) 
{
    Dispatcher->RunAsync(CoreDispatcherPriority::Low,
        ref new DispatchedHandler([this]()
    {
        ProximityDeviceEventsOutputText->Text += "Proximate device departed\n";
    }));
}

