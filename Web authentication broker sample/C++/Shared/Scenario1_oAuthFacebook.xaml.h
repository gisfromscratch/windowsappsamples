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
// Scenario1.xaml.h
// Declaration of the Scenario1 class
//

#pragma once

#include "pch.h"
#include "Scenario1_oAuthFacebook.g.h"
#include "MainPage.xaml.h"

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#include "ContinuationManager.h"
using namespace Windows::ApplicationModel::Activation;
#endif

namespace SDKSample
{
    namespace WebAuthentication
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		public ref class Scenario1 sealed : IWebAuthenticationContinuable
#else
        [Windows::Foundation::Metadata::WebHostHidden]
		public ref class Scenario1 sealed
#endif
        {

        public:
            Scenario1();
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			virtual void ContinueWebAuthentication(WebAuthenticationBrokerContinuationEventArgs^ args);
#endif
        protected:
            virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;		
        private:
            MainPage^ rootPage;
            void Launch_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    	};
    }
}
