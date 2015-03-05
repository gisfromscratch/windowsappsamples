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
#include "Scenario1_BindingModes.g.h"
#include "MainPage.xaml.h"

namespace SDKSample
{
    namespace DataBinding
    {
        /// <summary>
        /// An empty page that can be used on its own or navigated to within a Frame.
        /// </summary>
        public ref class Scenario1 sealed
        {
        public:
            Scenario1();
        private:
            MainPage^ rootPage;
            void Scenario1Reset(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    	};
    }
}
