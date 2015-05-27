; CLW-Datei enthält Informationen für den MFC-Klassen-Assistenten

[General Info]
Version=1
LastClass=CStockODBCView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StockODBC.h"
LastPage=0

ClassCount=6
Class1=CStockODBCApp
Class2=CStockODBCDoc
Class3=CStockODBCView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CStockODBCSet
Resource7=IDD_STOCKODBC_FORM

[CLS:CStockODBCApp]
Type=0
HeaderFile=StockODBC.h
ImplementationFile=StockODBC.cpp
Filter=N

[CLS:CStockODBCDoc]
Type=0
HeaderFile=StockODBCDoc.h
ImplementationFile=StockODBCDoc.cpp
Filter=N
LastObject=CStockODBCDoc

[CLS:CStockODBCView]
Type=0
HeaderFile=StockODBCView.h
ImplementationFile=StockODBCView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=CStockODBCView


[CLS:CStockODBCSet]
Type=0
HeaderFile=StockODBCSet.h
ImplementationFile=StockODBCSet.cpp
Filter=N
LastObject=CStockODBCSet

[DB:CStockODBCSet]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[Aktiennummer], 4, 4
Column2=[Aktienname], 12, 50
Column3=[WKN], 4, 4
Column4=[Tickersymbol], 12, 6


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=StockODBC.cpp
ImplementationFile=StockODBC.cpp
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
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_RECORD_FIRST
Command7=ID_RECORD_PREV
Command8=ID_RECORD_NEXT
Command9=ID_RECORD_LAST
Command10=ID_RECORD_DELETE
Command11=ID_RECORD_NEW
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_APP_ABOUT
CommandCount=14

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_UNDO
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
CommandCount=10

[DLG:IDD_STOCKODBC_FORM]
Type=1
Class=CStockODBCView
ControlCount=8
Control1=IDC_EDIT_STOCKNAME,edit,1350631552
Control2=IDC_EDIT_WKN,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_TICKER,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_STOCKNO,edit,1350633600

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

