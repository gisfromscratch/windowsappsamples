; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChartProperty
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StockChartOle.h"
LastPage=0

ClassCount=9
Class1=CStockChartOleApp
Class2=CStockChartOleDoc
Class3=CStockChartOleView
Class4=CMainFrame
Class5=CInPlaceFrame
Class7=CChildFrame

ResourceCount=7
Resource1=IDD_CHARTPROPERTY
Resource2=IDR_STOCKCTYPE
Resource3=IDR_STOCKCTYPE_SRVR_EMB
Resource5=IDR_MAINFRAME
Resource6=IDR_STOCKCTYPE_SRVR_IP
Class6=CAboutDlg
Resource4=IDD_ABOUTBOX
Class8=CStockProperty
Class9=CChartProperty
Resource7=IDD_STOCKPROPERTY

[CLS:CStockChartOleApp]
Type=0
HeaderFile=StockChartOle.h
ImplementationFile=StockChartOle.cpp
Filter=N

[CLS:CStockChartOleDoc]
Type=0
HeaderFile=StockChartOleDoc.h
ImplementationFile=StockChartOleDoc.cpp
Filter=N
BaseClass=COleServerDoc
VirtualFilter=vLODC
LastObject=CStockChartOleDoc

[CLS:CStockChartOleView]
Type=0
HeaderFile=StockChartOleView.h
ImplementationFile=StockChartOleView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CStockChartOleView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T

[CLS:CInPlaceFrame]
Type=0
HeaderFile=IpFrame.h
ImplementationFile=IpFrame.cpp
Filter=T
LastObject=CInPlaceFrame
BaseClass=COleIPFrameWnd
VirtualFilter=PfWC

[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M

[CLS:CAboutDlg]
Type=0
HeaderFile=StockChartOle.cpp
ImplementationFile=StockChartOle.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_STOCKCTYPE_SRVR_EMB]
Type=1
Class=CStockChartOleView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_UPDATE
Command5=ID_FILE_SAVE_COPY_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_CHART_PROPERTY
Command12=ID_STOCK_PROPERTY
Command13=ID_FILE_IMPORT
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_WINDOW_NEW
Command17=ID_WINDOW_CASCADE
Command18=ID_WINDOW_TILE_HORZ
Command19=ID_WINDOW_ARRANGE
Command20=ID_APP_ABOUT
CommandCount=20

[MNU:IDR_STOCKCTYPE_SRVR_IP]
Type=1
Class=CStockChartOleView
Command1=ID_CHART_PROPERTY
Command2=ID_STOCK_PROPERTY
Command3=ID_FILE_IMPORT
Command4=ID_VIEW_TOOLBAR
Command5=ID_APP_ABOUT
CommandCount=5

[TB:IDR_STOCKCTYPE_SRVR_IP]
Type=1
Class=CStockChartOleView
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_APP_ABOUT
CommandCount=4

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[ACL:IDR_STOCKCTYPE_SRVR_IP]
Type=1
Class=CStockChartOleView
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_CANCEL_EDIT_SRVR
CommandCount=9

[ACL:IDR_STOCKCTYPE_SRVR_EMB]
Type=1
Class=CStockChartOleView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_UPDATE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[MNU:IDR_STOCKCTYPE]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_CHART_PROPERTY
Command12=ID_STOCK_PROPERTY
Command13=ID_FILE_IMPORT
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_WINDOW_NEW
Command17=ID_WINDOW_CASCADE
Command18=ID_WINDOW_TILE_HORZ
Command19=ID_WINDOW_ARRANGE
Command20=ID_APP_ABOUT
CommandCount=20

[DLG:IDD_CHARTPROPERTY]
Type=1
Class=CChartProperty
ControlCount=14
Control1=IDOK,button,1342242817
Control2=ID_APPLY_NOW,button,1342242816
Control3=IDCANCEL,button,1342242816
Control4=IDC_CHECK_GRID,button,1342242819
Control5=IDC_RADIO_RED,button,1342373897
Control6=IDC_RADIO_GREEN,button,1342177289
Control7=IDC_RADIO_BLUE,button,1342177289
Control8=IDC_STATIC,static,1342308355
Control9=IDC_STATIC,static,1342177283
Control10=IDC_STATIC,static,1342177283
Control11=IDC_STATIC,button,1342177287
Control12=IDC_CHECK_LINE,button,1342242819
Control13=IDC_SLIDER_AVERAGE,msctls_trackbar32,1342242840
Control14=IDC_STATIC,button,1342177287

[DLG:IDD_STOCKPROPERTY]
Type=1
Class=CStockProperty
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350639744
Control5=IDC_EDIT3,edit,1350631560
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CStockProperty]
Type=0
HeaderFile=StockProperty.h
ImplementationFile=StockProperty.cpp
BaseClass=CDialog
Filter=D
LastObject=CStockProperty
VirtualFilter=dWC

[CLS:CChartProperty]
Type=0
HeaderFile=ChartProperty.h
ImplementationFile=ChartProperty.cpp
BaseClass=CDialog
Filter=D
LastObject=CChartProperty
VirtualFilter=dWC

