//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once

#include "DirectXSample.h"

// Helper class that initializes DirectX APIs for both 2D and 3D rendering.
// Some of the code in this class may be omitted if only 2D or only 3D rendering is being used.
ref class DirectXBase abstract
{
internal:
    DirectXBase();

    virtual void Initialize(Windows::UI::Core::CoreWindow^ window, float dpi);
    virtual void HandleDeviceLost();
    virtual void CreateDeviceIndependentResources();
    virtual void CreateDeviceResources();
    virtual void SetDpi(float dpi);
    virtual void UpdateForWindowSizeChange();
    virtual void CreateWindowSizeDependentResources();
    virtual void Render() = 0;
    virtual void Present();
    virtual float ConvertDipsToPixels(float dips);
    void Trim();

protected private:
    DXGI_MODE_ROTATION ComputeDisplayRotation();

    Platform::Agile<Windows::UI::Core::CoreWindow>  m_window;

    // DirectWrite & Windows Imaging Component Objects.
    Microsoft::WRL::ComPtr<IDWriteFactory2>         m_dwriteFactory;
    Microsoft::WRL::ComPtr<IWICImagingFactory2>     m_wicFactory;

    // DirectX Core Objects. Required for 2D and 3D.
    Microsoft::WRL::ComPtr<ID3D11Device2>           m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext2>    m_d3dContext;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_d3dRenderTargetView;

    // Direct2D Rendering Objects. Required for 2D.
    Microsoft::WRL::ComPtr<ID2D1Factory2>           m_d2dFactory;
    Microsoft::WRL::ComPtr<ID2D1Device1>            m_d2dDevice;
    Microsoft::WRL::ComPtr<ID2D1DeviceContext1>     m_d2dContext;
    Microsoft::WRL::ComPtr<ID2D1Bitmap1>            m_d2dTargetBitmap;

    // Direct3D Rendering Objects. Required for 3D.
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_d3dDepthStencilView;

    // Cached renderer properties.
    D3D_FEATURE_LEVEL                               m_featureLevel;
    Windows::Foundation::Size                       m_renderTargetSize;
    Windows::Foundation::Rect                       m_windowBounds;
    float                                           m_dpi;
    Windows::Graphics::Display::DisplayOrientations m_orientation;
    bool                                            m_windowSizeChangeInProgress;

    // Transforms used for display orientation.
    D2D1::Matrix3x2F                                m_rotationTransform2D;
    float4x4                                        m_rotationTransform3D;
};
