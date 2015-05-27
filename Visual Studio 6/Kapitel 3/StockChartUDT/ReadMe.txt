========================================================================
       MICROSOFT FOUNDATION CLASS BIBLIOTHEK : StockChart
========================================================================


Diese StockChart-Anwendung hat der Klassen-Assistent für Sie erstellt. Diese Anwendung
zeigt nicht nur die prinzipielle Verwendung der Microsoft Foundation Classes, 
sondern dient auch als Ausgangspunkt für die Erstellung Ihrer eigenen DLLs.

Diese Datei enthält die Zusammenfassung der Bestandteile aller Dateien, die 
Ihre StockChart-Anwendung bilden.

StockChartUDT.h
    	Hierbei handelt es sich um die Haupt-Header-Datei der Anwendung. Diese enthält 
	andere projektspezifische Header (einschließlich Resource.h) und deklariert die
	Anwendungsklasse CStockChartUDTApp.

StockChartUDT.cpp
    	Hierbei handelt es sich um die Haupt-Quellcodedatei der Anwendung. Diese enthält die
    	Anwendungsklasse CStockChartUDTApp.

StockChartUDT.rc
	Hierbei handelt es sich um eine Auflistung aller Ressourcen von Microsoft Windows, die 
	vom Programm verwendet werden. Sie enthält die Symbole, Bitmaps und Cursors, die im 
	Unterverzeichnis RES abgelegt sind. Diese Datei lässt sich direkt im Microsoft
	Developer Studio bearbeiten.

res\StockChartUDT.ico
    	Dies ist eine Symboldatei, die als Symbol für die Anwendung verwendet wird. Dieses 
	Symbol wird durch die Haupt-Ressourcendatei StockChartUDT.rc eingebunden.

res\StockChartUDT.rc2
    	Diese Datei enthält Ressourcen, die nicht vom Microsoft Developer Studio bearbeitet wurden.
	In diese Datei werden alle Ressourcen abgelegt, die vom Ressourcen-Editor nicht bearbeitet 
	werden können.

StockChartUDT.reg
    	Dies ist eine .REG-Beispieldatei, die Ihnen anzeigt, welche Registrierungseinstellungen 
	durch die Programmumgebung festlegt werden. Diese können Sie als .REG-
    	-Datei für Ihre Anwendung festlegen, oder diese löschen und die Standardregistrierung 
	RegisterShellFileTypes verwenden.

StockChartUDT.clw
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

/////////////////////////////////////////////////////////////////////////////

Der Klassen-Assistent erstellt einen Dokumenttyp und eine Ansicht(View):

StockChartUDTDoc.h, StockChartUDTDoc.cpp - das Dokument
    	Diese Dateien enthalten die Klasse CStockChartUDTDoc. Bearbeiten Sie diese Dateien,
  	um Ihre speziellen Dokumentdaten hinzuzufügen und das Speichern und Laden von 
	Dateien zu implementieren (mit Hilfe von CStockChartUDTDoc::Serialize).

StockChartUDTView.h, StockChartUDTView.cpp - die Ansicht des Dokuments
    	Diese Dateien enthalten die Klasse CStockChartUDTView.
    	CStockChartUDTView-Objekte werden verwendet, um CStockChartUDTDoc-Objekte anzuzeigen.

res\StockChartUDTDoc.ico
    	Dies ist eine Symboldatei, die als Symbol für untergeordnete MDI-Fenster 
	der Klasse CStockChartUDTDoc verwendet wird. Dieses Symbol wird durch die
	Haupt-Ressourcendatei StockChartUDT.rc eingebunden.


/////////////////////////////////////////////////////////////////////////////
Andere Standarddateien:

StdAfx.h, StdAfx.cpp
    	Mit diesen Dateien werden vorkompilierte Header-Dateien (PCH) mit der Bezeichnung 
	StockChartUDT.pch und eine vorkompilierte Typdatei mit der Bezeichnung StdAfx.obj
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
