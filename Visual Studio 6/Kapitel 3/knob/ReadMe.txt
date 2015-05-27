========================================================================
		ActiveX-Steuerelement-DLL : KNOB
========================================================================

Der Steuerelement-Assistent hat dieses Projekt f�r Ihre ActiveX-Steuer-
element-DLL KNOB erstellt, die 1 control enth�lt.

Dieses Entwurfsprojekt demonstriert nicht nur die Grundlagen, um ein 
ActiveX-Steuerelement zu entwerfen, sondern stellt auch einen Ausgangspunkt
dar, um die spezifischen Funktionen des Steuerelements zu schreiben.

Diese Datei enth�lt eine Zusammenfassung des Inhalts der Dateien, welche
die ActiveX-Steuerelement-DLL KNOB ergeben.

knob.mak
	Das Makefile f�r das Projekt in Visual C++ zur Erstellung des 
        ActiveX-Steuerelements.

knob.h
	Dies ist die zentrale Header-Datei f�r die ActiveX-Steuerelement-DLL. 
        Sie bindet weitere projektspezifische Header-Dateien ein, wie etwa 
        resource.h.

knob.cpp
	Dies ist die zentrale Quellcodedatei, die den Code f�r die 
        Initialisierung der DLL, ihre Beendigung und andere Verwaltungs-
        aufgaben enth�lt.

knob.rc
	Dies ist eine Aufstellung der Ressourcen von Microsoft Windows, die 
        das Projekt verwendet. Diese Datei kann unmittelbar im Ressourcen-
        Editor von Visual C++ bearbeitet werden.

knob.def
	Diese Datei enth�lt Informationen �ber die ActiveX-Steuerelement-DLL, 
        die f�r eine Ausf�hrung unter Microsoft Windows zur Verf�gung stehen 
        m�ssen.

knob.clw
	Diese Datei enth�lt Informationen, die vom Klassen-Assistenten ben�tigt 
        werden, um existierende Klassen zu bearbeiten oder neue Klassen hinzu-
        zuf�gen. Der Klassen-Assistent verwendet diese Datei auch, um 
        Informationen zu speichern, die zur Erstellung und Bearbeitung von 
        Zuordnungstabellen f�r Nachrichten und Dialogfelddaten und zur 
        Erstellung der Funktionsprototypen von Member-Funktionen ben�tigt werden.

knob.odl
	Diese Datei enth�lt den Quellcode in der Objektbeschreibungssprache ODL 
        f�r die Typbibliothek der control.

/////////////////////////////////////////////////////////////////////////////
Steuerelement Knob:

KnobCtl.h
	Diese Datei enth�lt die Deklaration der C++-Klasse CKnobCtrl.

KnobCtl.cpp
	Diese Datei enth�lt die Implementierung der C++-Klasse CKnobCtrl.

KnobPpg.h
	Diese Datei enth�lt die Deklaration der C++-Klasse CKnobPropPage.

KnobPpg.cpp
	Diese Datei enth�lt die Implementierung der C++-Klasse CKnobPropPage.

KnobCtl.bmp
	Diese Datei enth�lt eine Bitmap, die von einem Container verwendet 
        wird, um das Steuerelement CKnobCtrl darzustellen, wenn es auf
        einer Symbolleiste erscheint. Diese Bitmap wird von der zentralen 
        Ressourcendatei knob.rc eingebunden.

/////////////////////////////////////////////////////////////////////////////
Weitere Standarddateien: 

stdafx.h, stdafx.cpp
	Diese Dateien werden ben�tigt, um eine vorkompilierte Header-Datei 
        (.PCH-Datei) mit dem Namen stdafx.pch zu erstellen sowie eine 
        vorkompilierte Typendatei (.PCT-Datei) mit dem Namen stdafx.obj.

resource.h
	Dies ist die Standard-Header-Datei, in der neue Ressourcen-IDs definiert
        werden. Der Ressourcen-Editor von Visual C++ liest diese Datei und f�hrt 
        Aktualisierungen durch.

/////////////////////////////////////////////////////////////////////////////
Weitere Hinweise:

Der Steuerelement-Assistent verwendet "ZU ERLEDIGEN:", um auf Abschnitte im 
Quellcode hinzuweisen, die hinzugef�gt oder angepasst werden sollen.

/////////////////////////////////////////////////////////////////////////////
