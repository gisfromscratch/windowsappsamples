; CLW-Datei enthält Informationen für den MFC-Klassen-Assistenten

[General Info]
Version=1
LastClass=CDAOChartDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DAOChart.h"
LastPage=0

ClassCount=9
Class1=CDAOChartApp
Class2=CDAOChartDoc
Class3=CDAOChartView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDR_DAOCHATYPE
Class5=CChildFrame
Class6=CAboutDlg
Class7=CShares
Class8=CQuotes
Resource3=IDD_ABOUTBOX
Class9=CStockChooser
Resource4=IDD_STOCKCHOOSER

[CLS:CDAOChartApp]
Type=0
HeaderFile=DAOChart.h
ImplementationFile=DAOChart.cpp
Filter=N

[CLS:CDAOChartDoc]
Type=0
HeaderFile=DAOChartDoc.h
ImplementationFile=DAOChartDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CDAOChartDoc

[CLS:CDAOChartView]
Type=0
HeaderFile=DAOChartView.h
ImplementationFile=DAOChartView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CDAOChartView


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
HeaderFile=DAOChart.cpp
ImplementationFile=DAOChart.cpp
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

[MNU:IDR_DAOCHATYPE]
Type=1
Class=CDAOChartView
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
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_PRINT
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_NEXT_PANE
Command8=ID_PREV_PANE
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_CUT
Command12=ID_EDIT_UNDO
CommandCount=12

[CLS:CShares]
Type=0
HeaderFile=Shares.h
ImplementationFile=Shares.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x
LastObject=CShares

[DB:CShares]
DB=1
DBType=DAO
ColumnCount=4
Column1=[Aktiennummer], 4, 4
Column2=[Aktienname], 12, 50
Column3=[WKN], 4, 4
Column4=[Tickersymbol], 12, 6

[CLS:CQuotes]
Type=0
HeaderFile=Quotes.h
ImplementationFile=Quotes.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x
LastObject=CQuotes

[DB:CQuotes]
DB=1
DBType=DAO
ColumnCount=7
Column1=[Aktie].[Aktiennummer], 4, 4
Column2=[Aktienname], 12, 50
Column3=[WKN], 4, 4
Column4=[Tickersymbol], 12, 6
Column5=[Kurs].[Aktiennummer], 4, 4
Column6=[Datum], 11, 8
Column7=[Kurs], -5, 8

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
LastObject=IDC_LIST1
VirtualFilter=dWC

