; CLW-Datei enthält Informationen für den MFC-Klassen-Assistenten

[General Info]
Version=1
LastClass=COLEDBChartView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OLEDBChart.h"
LastPage=0

ClassCount=7
Class1=COLEDBChartApp
Class2=COLEDBChartDoc
Class3=COLEDBChartView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_OLEDBCTYPE
Resource3=IDR_MAINFRAME
Class5=CChildFrame
Class6=CAboutDlg
Class7=CStockChooser
Resource4=IDD_STOCKCHOOSER

[CLS:COLEDBChartApp]
Type=0
HeaderFile=OLEDBChart.h
ImplementationFile=OLEDBChart.cpp
Filter=N

[CLS:COLEDBChartDoc]
Type=0
HeaderFile=OLEDBChartDoc.h
ImplementationFile=OLEDBChartDoc.cpp
Filter=N
LastObject=COLEDBChartDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:COLEDBChartView]
Type=0
HeaderFile=OLEDBChartView.h
ImplementationFile=OLEDBChartView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=COLEDBChartView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=OLEDBChart.cpp
ImplementationFile=OLEDBChart.cpp
Filter=D
LastObject=CAboutDlg

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
Command2=ID_FILE_PRINT_SETUP
Command3=ID_APP_EXIT
Command4=ID_VIEW_TOOLBAR
Command5=ID_VIEW_STATUS_BAR
Command6=ID_APP_ABOUT
CommandCount=6

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_PRINT
Command3=ID_APP_ABOUT
CommandCount=3

[MNU:IDR_OLEDBCTYPE]
Type=1
Class=COLEDBChartView
Command1=ID_FILE_NEW
Command2=ID_FILE_CLOSE
Command3=ID_FILE_PRINT
Command4=ID_FILE_PRINT_PREVIEW
Command5=ID_FILE_PRINT_SETUP
Command6=ID_APP_EXIT
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_WINDOW_NEW
Command10=ID_WINDOW_CASCADE
Command11=ID_WINDOW_TILE_HORZ
Command12=ID_WINDOW_ARRANGE
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_PRINT
Command3=ID_EDIT_PASTE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_NEXT_PANE
Command7=ID_PREV_PANE
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_CUT
Command11=ID_EDIT_UNDO
CommandCount=11

[DLG:IDD_STOCKCHOOSER]
Type=1
Class=CStockChooser
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,listbox,1352728835

[CLS:CStockChooser]
Type=0
HeaderFile=StockChooser.h
ImplementationFile=StockChooser.cpp
BaseClass=CDialog
Filter=D
LastObject=CStockChooser
VirtualFilter=dWC

