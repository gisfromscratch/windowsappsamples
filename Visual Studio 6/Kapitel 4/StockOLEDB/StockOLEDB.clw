; CLW-Datei enthält Informationen für den MFC-Klassen-Assistenten

[General Info]
Version=1
LastClass=CStockOLEDBView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StockOLEDB.h"
LastPage=0

ClassCount=5
Class1=CStockOLEDBApp
Class2=CStockOLEDBDoc
Class3=CStockOLEDBView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDD_STOCKOLEDB_FORM
Class5=CAboutDlg
Resource7=IDR_MAINFRAME

[CLS:CStockOLEDBApp]
Type=0
HeaderFile=StockOLEDB.h
ImplementationFile=StockOLEDB.cpp
Filter=N

[CLS:CStockOLEDBDoc]
Type=0
HeaderFile=StockOLEDBDoc.h
ImplementationFile=StockOLEDBDoc.cpp
Filter=N

[CLS:CStockOLEDBView]
Type=0
HeaderFile=StockOLEDBView.h
ImplementationFile=StockOLEDBView.cpp
Filter=D
BaseClass=COleDBRecordView
VirtualFilter=RVWC
LastObject=CStockOLEDBView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=StockOLEDB.cpp
ImplementationFile=StockOLEDB.cpp
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
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_STOCKOLEDB_FORM]
Type=1
Class=CStockOLEDBView
ControlCount=8
Control1=IDC_EDIT_SHARENAME,edit,1350631552
Control2=IDC_EDIT_WKN,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_TICKER,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_SHARENO,edit,1350633600

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

