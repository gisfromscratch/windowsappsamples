; CLW-Datei enthält Informationen für den MFC-Klassen-Assistenten

[General Info]
Version=1
LastClass=CODBCChartDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ODBCChart.h"
LastPage=0

ClassCount=10
Class1=CODBCChartApp
Class2=CODBCChartDoc
Class3=CODBCChartView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_ODBCCHTYPE
Resource2=IDR_MAINFRAME
Class5=CChildFrame
Class6=CAboutDlg
Class7=Quotes
Resource3=IDD_ABOUTBOX
Class8=CStockChooser
Class9=CShares
Class10=CChartProperty
Resource4=IDD_STOCKCHOOSER

[CLS:CODBCChartApp]
Type=0
HeaderFile=ODBCChart.h
ImplementationFile=ODBCChart.cpp
Filter=N

[CLS:CODBCChartDoc]
Type=0
HeaderFile=ODBCChartDoc.h
ImplementationFile=ODBCChartDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CODBCChartDoc

[CLS:CODBCChartView]
Type=0
HeaderFile=ODBCChartView.h
ImplementationFile=ODBCChartView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CODBCChartView


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
HeaderFile=ODBCChart.cpp
ImplementationFile=ODBCChart.cpp
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

[MNU:IDR_ODBCCHTYPE]
Type=1
Class=CODBCChartView
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

[CLS:CShares]
Type=0
HeaderFile=Shares.h
ImplementationFile=Shares.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CShares

[DB:CShares]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[Aktiennummer], 4, 4
Column2=[Aktienname], 12, 50
Column3=[WKN], 4, 4
Column4=[Tickersymbol], 12, 6

[CLS:CQuotes]
Type=0
HeaderFile=Quotes.h
ImplementationFile=Quotes.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CQuotes

[DB:CQuotes]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[Aktie].[Aktiennummer], 4, 4
Column2=[Aktienname], 12, 50
Column3=[WKN], 4, 4
Column4=[Tickersymbol], 12, 6
Column5=[Kurs].[Aktiennummer], 4, 4
Column6=[Datum], 11, 16
Column7=[Kurs], 2, 21

[CLS:CChartProperty]
Type=0
HeaderFile=ChartProperty.h
ImplementationFile=ChartProperty.cpp
BaseClass=CDialog
Filter=D

