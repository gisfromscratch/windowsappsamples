﻿//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#pragma once

#include "pch.h"
#include "Scenario5_BadgePoll.g.h"
#include "MainPage.xaml.h"

namespace SDKSample
{
    namespace SDKTemplate
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
    	[Windows::Foundation::Metadata::WebHostHidden]
        public ref class Scenario5 sealed
        {
        public:
            Scenario5();
    
        protected:
            virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
        private:
            MainPage^ rootPage;
            void StartBadgePolling_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    		void StopBadgePolling_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        };
    }
}
