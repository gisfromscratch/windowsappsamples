; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStockChartAutoDoc
LastTemplate=CCmdTarget
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StockChartAuto.h"
ODLFile=StockChartAuto.odl
LastPage=0

ClassCount=9
Class1=CStockChartAutoApp
Class2=CStockChartAutoDoc
Class3=CStockChartAutoView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDD_STOCKPROPERTY
Resource3=IDR_STOCKCTYPE
Class5=CAboutDlg
Class6=CChildFrame
Resource4=IDR_MAINFRAME
Class7=CStockProperty
Class8=CChartProperty
Class9=CStatusBarInterface
Resource5=IDD_CHARTPROPERTY

[CLS:CStockChartAutoApp]
Type=0
HeaderFile=StockChartAuto.h
ImplementationFile=StockChartAuto.cpp
Filter=N

[CLS:CStockChartAutoDoc]
Type=0
HeaderFile=StockChartAutoDoc.h
ImplementationFile=StockChartAutoDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CStockChartAutoDoc

[CLS:CStockChartAutoView]
Type=0
HeaderFile=StockChartAutoView.h
ImplementationFile=StockChartAutoView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CStockChartAutoView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M

[CLS:CAboutDlg]
Type=0
HeaderFile=StockChartAuto.cpp
ImplementationFile=StockChartAuto.cpp
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

[CLS:CStatusBarInterface]
Type=0
HeaderFile=StatusBarInterface.h
ImplementationFile=StatusBarInterface.cpp
BaseClass=CCmdTarget
Filter=N
VirtualFilter=C
LastObject=CStatusBarInterface

