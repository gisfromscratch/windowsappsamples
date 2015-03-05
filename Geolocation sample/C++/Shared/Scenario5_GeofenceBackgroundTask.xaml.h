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
// Scenario5_BackgroundTask.xaml.h
// Declaration of the Scenario5 class
//

#pragma once

#include "pch.h"
#include "Scenario5_GeofenceBackgroundTask.g.h"
#include "MainPage.xaml.h"

namespace SDKSample
{
    namespace GeolocationCPP
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
        [Windows::Foundation::Metadata::WebHostHidden]
        public ref class Scenario5 sealed
        {
        private:
            Platform::Collections::Vector<Platform::String^>^ geofenceBackgroundEvents;

        public:
            Scenario5();

        protected:
            virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
            virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

        private:
            MainPage^ rootPage;
            Platform::String^ sampleBackgroundTaskName;
            Platform::String^ sampleBackgroundTaskEntryPoint;
            Windows::ApplicationModel::Background::BackgroundTaskRegistration^ geofenceTask;
            Windows::Foundation::EventRegistrationToken taskCompletedToken;
            Windows::Devices::Geolocation::Geolocator^ geolocator;
            concurrency::cancellation_token_source geopositionTaskTokenSource;

            void RegisterBackgroundTask(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
            void UnregisterBackgroundTask(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
            void GetGeopositionAsync();
            void OnCompleted(Windows::ApplicationModel::Background::BackgroundTaskRegistration^ sender, Windows::ApplicationModel::Background::BackgroundTaskCompletedEventArgs^ e);
            void FillEventListBoxWithExistingEvents();
            void UpdateButtonStates(bool registered);
        };
    }
}
