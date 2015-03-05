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
// pch.h
// Header for standard system include files.
//

#pragma once

#include <string>
#include <sstream>
#include <locale>
#include <iomanip>
#include <ctime>
#include <vector>
#include <array>
#include <collection.h>
#include <ppltasks.h>
#include "Common\SuspensionManager.h"
#include "App.xaml.h"

template <class T>
inline T FromStringTo(Platform::String^ str)
{
    std::wistringstream wiss(str->Data());
    T value = 0;
    wiss >> value;
    return value;
}

template <class T>
inline T FromStringTo(std::wstring str)
{
    std::wistringstream wiss(str);
    T value = 0;
    wiss >> value;
    return value;
}
