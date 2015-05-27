; CLW-Datei enthält Informationen für den MFC-Klassen-Assistenten

[General Info]
Version=1
LastClass=CStockDAOView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StockDAO.h"
LastPage=0

ClassCount=6
Class1=CStockDAOApp
Class2=CStockDAODoc
Class3=CStockDAOView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDD_STOCKDAO_FORM
Class5=CStockDAOSet
Resource7=IDR_MAINFRAME

[CLS:CStockDAOApp]
Type=0
HeaderFile=StockDAO.h
ImplementationFile=StockDAO.cpp
Filter=N

[CLS:CStockDAODoc]
Type=0
HeaderFile=StockDAODoc.h
ImplementationFile=StockDAODoc.cpp
Filter=N

[CLS:CStockDAOView]
Type=0
HeaderFile=StockDAOView.h
ImplementationFile=StockDAOView.cpp
Filter=D
BaseClass=CDaoRecordView
VirtualFilter=XRVWC
LastObject=CStockDAOView


[CLS:CStockDAOSet]
Type=0
HeaderFile=StockDAOSet.h
ImplementationFile=StockDAOSet.cpp
Filter=N

[DB:CStockDAOSet]
DB=1
DBType=DAO
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
HeaderFile=StockDAO.cpp
ImplementationFile=StockDAO.cpp
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
Command13=ID_RECORD_DELETE
Command14=ID_RECORD_NEW
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
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

[DLG:IDD_STOCKDAO_FORM]
Type=1
Class=CStockDAOView
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

