========================================================================
       MICROSOFT FOUNDATION CLASS BIBLIOTHEK : StockChartX
========================================================================


Diese StockChartX-Anwendung hat der Klassen-Assistent für Sie erstellt. Diese Anwendung
zeigt nicht nur die prinzipielle Verwendung der Microsoft Foundation Classes, 
sondern dient auch als Ausgangspunkt für die Erstellung Ihrer eigenen DLLs.

Diese Datei enthält die Zusammenfassung der Bestandteile aller Dateien, die 
Ihre StockChartX-Anwendung bilden.

StockChartX.h
    	Hierbei handelt es sich um die Haupt-Header-Datei der Anwendung. Diese enthält 
	andere projektspezifische Header (einschließlich Resource.h) und deklariert die
	Anwendungsklasse CStockChartXApp.

StockChartX.cpp
    	Hierbei handelt es sich um die Haupt-Quellcodedatei der Anwendung. Diese enthält die
    	Anwendungsklasse CStockChartXApp.

StockChartX.rc
	Hierbei handelt es sich um eine Auflistung aller Ressourcen von Microsoft Windows, die 
	vom Programm verwendet werden. Sie enthält die Symbole, Bitmaps und Cursors, die im 
	Unterverzeichnis RES abgelegt sind. Diese Datei lässt sich direkt im Microsoft
	Developer Studio bearbeiten.

res\StockChartX.ico
    	Dies ist eine Symboldatei, die als Symbol für die Anwendung verwendet wird. Dieses 
	Symbol wird durch die Haupt-Ressourcendatei StockChartX.rc eingebunden.

res\StockChartX.rc2
    	Diese Datei enthält Ressourcen, die nicht vom Microsoft Developer Studio bearbeitet wurden.
	In diese Datei werden alle Ressourcen abgelegt, die vom Ressourcen-Editor nicht bearbeitet 
	werden können.

StockChartX.reg
    	Dies ist eine .REG-Beispieldatei, die Ihnen anzeigt, welche Registrierungseinstellungen 
	durch die Programmumgebung festlegt werden. Diese können Sie als .REG-
    	-Datei für Ihre Anwendung festlegen, oder diese löschen und die Standardregistrierung 
	RegisterShellFileTypes verwenden.

StockChartX.clw
    	Diese Datei enthält Informationen, mit denen der Klassen-Assistent bestehende
    	Klassen bearbeitet oder neue Klassen einfügt. Außerdem verwendet der Klassen-Assistent 
	diese Datei, um Informationen zu speichern, die er für das Erstellen und Bearbeiten von
	Nachrichtentabellen und Dialogfeld-Nachrichtentabellen sowie für das Erstellen von 
	Prototypen vom Member-Funktionen benötigt.

/////////////////////////////////////////////////////////////////////////////

Für das Hauptfenster:

MainFrm.h, MainFrm.cpp
    	Diese Dateien enthalten die Frame-Klasse CMainFrame, die von
    	CMDIFrameWnd abgeleitet wurde und alle MDI-Frame-Merkmale steuert.

res\Toolbar.bmp
    	Mit dieser Bitmap-Datei werden nebeneinander angeordnete Bilder für 
	die Symbolleiste erstellt. Die beginnende Symbolleiste und Statusleiste
	wird in der Klasse CMainFrame konstruiert. Um der Symbolleiste
	weitere Schaltflächen hinzuzufügen, wird diese Symbolleisten-
	Bitmap zusammen mit dem Array in MainFrm.cpp bearbeitet.

res\IToolbar.bmp
	Mit dieser Bitmap-Datei werden nebeneinander angeordnete Bilder für 
	die Symbolleiste erstellt, wenn die Server-Anwendung innerhalb eines
	anderen Containers "vor Ort" aktiviert wird. Die Symbolleiste wird
	in der Klasse CInPlaceFrame konstruiert. Diese Bitmap ist der Bitmap in 
	res\Toolbar.bmp ähnlich, jedoch fehlen verschiedene Nicht-Server-Befehle.

/////////////////////////////////////////////////////////////////////////////

Der Klassen-Assistent erstellt einen Dokumenttyp und eine Ansicht(View):

StockChartXDoc.h, StockChartXDoc.cpp - das Dokument
    	Diese Dateien enthalten die Klasse CStockChartXDoc. Bearbeiten Sie diese Dateien,
  	um Ihre speziellen Dokumentdaten hinzuzufügen und das Speichern und Laden von 
	Dateien zu implementieren (mit Hilfe von CStockChartXDoc::Serialize).

StockChartXView.h, StockChartXView.cpp - die Ansicht des Dokuments
    	Diese Dateien enthalten die Klasse CStockChartXView.
    	CStockChartXView-Objekte werden verwendet, um CStockChartXDoc-Objekte anzuzeigen.

res\StockChartXDoc.ico
    	Dies ist eine Symboldatei, die als Symbol für untergeordnete MDI-Fenster 
	der Klasse CStockChartXDoc verwendet wird. Dieses Symbol wird durch die
	Haupt-Ressourcendatei StockChartX.rc eingebunden.

/////////////////////////////////////////////////////////////////////////////

Darüber hinaus hat der Klassen-Assistent OLE-spezifische Klassen erzeugt.

SrvrItem.h, SrvrItem.cpp - diese Klasse dient der Verbindung
	der Klasse CStockChartXDoc mit dem OLE-System und stellt auf Wunsch eine 
	Verknüpfung zu Ihrem Dokument zur Verfügung.
IpFrame.h, IpFrame.cpp - diese Klasse ist abgeleitet
	von COleIPFrameWnd und steuert alle Rahmenmerkmale während der Vor-Ort-
	Aktivierung.

/////////////////////////////////////////////////////////////////////////////
Andere Standarddateien:

StdAfx.h, StdAfx.cpp
    	Mit diesen Dateien werden vorkompilierte Header-Dateien (PCH) mit der Bezeichnung 
	StockChartX.pch und eine vorkompilierte Typdatei mit der Bezeichnung StdAfx.obj
	erstellt.

Resource.h
    	Dies ist die Standard-Header-Datei, die neue Ressourcen-IDs definiert.
    	Microsoft Developer Studio liest und aktualisiert diese Datei.

/////////////////////////////////////////////////////////////////////////////
Weitere Hinweise:

Der Klassen-Assistent fügt "ZU ERLEDIGEN:" im Quellcode ein, um die Stellen anzuzeigen, 
an denen Sie Erweiterungen oder Anpassungen vornehmen können.

Wenn Ihre Anwendung die MFC in einer gemeinsam genutzten DLL verwendet und Ihre Anwendung
eine andere als die aktuell auf dem Betriebssystem eingestellte Sprache verwendet, muss 
die entsprechend lokalisierte Ressource MFC40XXX.DLL von der Microsoft Visual C++ CD-ROM 
in das Verzeichnis system oder system32 kopiert und in MFCLOC.DLL umbenannt werden ("XXX" 
steht für die Abkürzung der Sprache. So enthält beispielsweise MFC40DEU.DLL die ins Deutsche 
übersetzten Ressourcen). Anderenfalls erscheinen einige Oberflächenelemente Ihrer Anwendung 
in der Sprache des Betriebssystems.

/////////////////////////////////////////////////////////////////////////////
