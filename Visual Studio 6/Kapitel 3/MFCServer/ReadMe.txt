========================================================================
       MICROSOFT FOUNDATION CLASS BIBLIOTHEK : MFCServer
========================================================================


Diese MFCServer-DLL hat der Klassen-Assistent f�r Sie erstellt. Die DLL zeigt 
die prinzipielle Anwendung der Microsoft Foundation Classes und dient Ihnen 
als Ausgangspunkt f�r die Erstellung Ihrer eigenen DLLs.

Diese Datei enth�lt die Zusammenfassung der Bestandteile aller Dateien, die 
Ihre MFCServer-DLL bilden.

MFCServer.h
	Dies ist die Haupt-Header-Datei, in der die Klasse CMFCServerApp deklariert ist.

MFCServer.cpp
	Hierbei handelt es sich um die Haupt-Quellcodedatei der DLL. Diese enth�lt 
	die Klasse CMFCServerApp.
	Au�erdem enth�lt diese Datei die OLE-Einstiegspunkte, die von Inproc-Servern 
	ben�tigt werden.

MFCServer.odl
    	Diese Datei enth�lt den Quellcode der Object Description Language (ODL) f�r
	die Typbibliothek Ihrer DLL.

MFCServer.rc
	Hierbei handelt es sich um eine Auflistung aller Ressourcen von Microsoft Windows, die 
	vom Programm verwendet werden. Sie enth�lt die Symbole, Bitmaps und Cursors, die im 
	Unterverzeichnis RES abgelegt sind. Diese Datei l�sst sich direkt im Microsoft
	Developer Studio bearbeiten.

res\MFCServer.rc2
    	Diese Datei enth�lt Ressourcen, die nicht vom Microsoft Developer Studio bearbeitet wurden.
	In diese Datei werden alle Ressourcen abgelegt, die vom Ressourcen-Editor nicht bearbeitet 
	werden k�nnen.

MFCServer.odl
    	Diese Datei enth�lt den Quellcode der Object Description Language (ODL) f�r die
    	Typbibliothek Ihrer Anwendung.

MFCServer.def
    	Diese Datei enth�lt Informationen �ber die DLL, die f�r das Ausf�hren unter
	Microsoft Windows erforderlich sind. Es werden Parameter definiert, wie beipielsweise
	der Name und die Beschreibung der DLL. Au�erdem werden die von der DLL exportierten
	Funktionen angegeben.

MFCServer.clw
    	Diese Datei enth�lt Informationen, mit denen der Klassen-Assistent bestehende
    	Klassen bearbeitet oder neue Klassen einf�gt. Au�erdem verwendet der Klassen-Assistent 
	diese Datei, um Informationen zu speichern, die er f�r das Erstellen und Bearbeiten von
	Nachrichtentabellen und Dialogfeld-Nachrichtentabellen sowie f�r das Erstellen von 
	Prototypen vom Member-Funktionen ben�tigt.

/////////////////////////////////////////////////////////////////////////////
Andere Standarddateien:

StdAfx.h, StdAfx.cpp
    	Mit diesen Dateien werden vorkompilierte Header-Dateien (PCH) mit der Bezeichnung 
	MFCServer.pch und eine vorkompilierte Typdatei mit der Bezeichnung StdAfx.obj
	erstellt.

Resource.h
    	Dies ist die Standard-Header-Datei, die neue Ressourcen-IDs definiert.
    	Microsoft Developer Studio liest und aktualisiert diese Datei.

/////////////////////////////////////////////////////////////////////////////
Weitere Hinweise:

Der Klassen-Assistent f�gt "ZU ERLEDIGEN:" im Quellcode ein, um die Stellen anzuzeigen, 
an denen Sie Erweiterungen oder Anpassungen vornehmen k�nnen.

/////////////////////////////////////////////////////////////////////////////
