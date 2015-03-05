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

#include <collection.h>

using namespace Platform;

namespace SDKSample
{
    public value struct Scenario
    {
        Platform::String^ Title;
        Platform::String^ ClassName;
    };

    partial ref class MainPage
    {
    public:
        static property Platform::String^ FEATURE_NAME
        {
            Platform::String^ get()
            {
                return ref new Platform::String(L"Syndication (CPP)");
            }
        }

        static property Platform::Array<Scenario>^ scenarios
        {
            Platform::Array<Scenario>^ get()
            {
                return scenariosInner;
            }
        }

        bool TryGetUri(Platform::String^ uriString, Windows::Foundation::Uri^* uri)
        {
            // Create a Uri instance and catch exceptions related to invalid input. This method returns 'true'
            // if the Uri instance was successfully created and 'false' otherwise.
            try
            {
                *uri = ref new Windows::Foundation::Uri(StringTrimmer::Trim(uriString));
                return true;
            }
            catch (Platform::NullReferenceException^ exception)
            {
                NotifyUser("Error: URI must not be null or empty.", NotifyType::ErrorMessage);
            }
            catch (Platform::InvalidArgumentException^ exception)
            {
                NotifyUser("Error: Invalid URI", NotifyType::ErrorMessage);
            }

            return false;
        }

    private:
        static Platform::Array<Scenario>^ scenariosInner;
    };

    class StringTrimmer
    {
    public:
        static Platform::String^ Trim(Platform::String^ s)
        {
            const WCHAR* first = s->Begin();
            const WCHAR* last = s->End();

            while (first != last && iswspace(*first))
            {
                ++first;
            }

            while (first != last && iswspace(last[-1]))
            {
                --last;
            }

            return ref new Platform::String(first, static_cast<unsigned int>(last - first));
        }
    };

    [Windows::UI::Xaml::Data::Bindable]
    public ref class BindableNode sealed
    {
    public:
        BindableNode(String^ nodeName, String^ nodeNamespace, String^ nodeValue)
        {
            this->NodeName = nodeName;
            this->NodeNamespace = nodeNamespace;
            this->NodeValue = nodeValue;
        }

        property String^ NodeName
        {
            String^ get()
            {
                return nodeName;
            }
            void set(String^ value)
            {
                nodeName = value;
            }
        }

        property String^ NodeNamespace
        {
            String^ get()
            {
                return nodeNamespace;
            }
            void set(String^ value)
            {
                nodeNamespace = value;
            }
        }

        property String^ NodeValue
        {
            String^ get()
            {
                return nodeValue;
            }
            void set(String^ value)
            {
                nodeValue = value;
            }
        }

    private:
        String^ nodeName;
        String^ nodeNamespace;
        String^ nodeValue;
    };
}
