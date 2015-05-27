VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "FirstAutoClient"
   ClientHeight    =   3900
   ClientLeft      =   900
   ClientTop       =   8430
   ClientWidth     =   5715
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   3900
   ScaleWidth      =   5715
   Begin VB.DriveListBox Drive1 
      Height          =   315
      Left            =   120
      TabIndex        =   10
      Top             =   1680
      Width           =   2775
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   1200
      TabIndex        =   9
      ToolTipText     =   "Tickersymbol"
      Top             =   840
      Width           =   1455
   End
   Begin VB.FileListBox File1 
      Height          =   1455
      Left            =   3000
      Pattern         =   "*.txt"
      TabIndex        =   5
      ToolTipText     =   "Wählen Sie eine Datei aus!"
      Top             =   1680
      Width           =   2535
   End
   Begin VB.DirListBox Dir1 
      Height          =   1440
      Left            =   120
      TabIndex        =   4
      Top             =   2160
      Width           =   2775
   End
   Begin VB.CommandButton CommandImport 
      Caption         =   "Importiere"
      Height          =   375
      Left            =   3960
      TabIndex        =   3
      Top             =   3480
      Width           =   1575
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   1200
      TabIndex        =   2
      ToolTipText     =   "Name der Aktie"
      Top             =   120
      Width           =   1455
   End
   Begin VB.TextBox Text1 
      Height          =   285
      Left            =   1200
      TabIndex        =   1
      Text            =   "0"
      ToolTipText     =   "Wertpapierkennummer"
      Top             =   480
      Width           =   1455
   End
   Begin VB.CommandButton CommandSet 
      Caption         =   "Setze"
      Height          =   375
      Left            =   3960
      TabIndex        =   0
      Top             =   840
      Width           =   1575
   End
   Begin VB.Line Line1 
      X1              =   0
      X2              =   5760
      Y1              =   1320
      Y2              =   1320
   End
   Begin VB.Label Label3 
      Caption         =   "Ticker"
      Height          =   255
      Left            =   120
      TabIndex        =   8
      Top             =   840
      Width           =   855
   End
   Begin VB.Label Label2 
      Caption         =   "WKN"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   480
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "Name"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   120
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim StockChartAuto As Object

Private Sub CommandSet_Click()
    StockChartAuto.ID = Text1.Text
    StockChartAuto.Name = Text2.Text
    StockChartAuto.Ticker = Text3.Text
End Sub

Private Sub CommandImport_Click()
    StockChartAuto.ImportFile File1.Path + "\" + File1.filename
End Sub

Private Sub Dir1_Change()
    File1.Path = Dir1.Path
End Sub

Private Sub Drive1_Change()
    Dir1.Path = Drive1.Drive
End Sub

Private Sub Form_Load()
    Set StockChartAuto = CreateObject("StockAuto.Document")
    StockChartAuto.ShowWindow ' Dokument sichtbar machen
End Sub










