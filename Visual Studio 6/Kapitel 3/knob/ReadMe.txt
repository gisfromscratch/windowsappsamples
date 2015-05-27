========================================================================
		ActiveX-Steuerelement-DLL : KNOB
========================================================================

Der Steuerelement-Assistent hat dieses Projekt für Ihre ActiveX-Steuer-
element-DLL KNOB erstellt, die 1 control enthält.

Dieses Entwurfsprojekt demonstriert nicht nur die Grundlagen, um ein 
ActiveX-Steuerelement zu entwerfen, sondern stellt auch einen Ausgangspunkt
dar, um die spezifischen Funktionen des Steuerelements zu schreiben.

Diese Datei enthält eine Zusammenfassung des Inhalts der Dateien, welche
die ActiveX-Steuerelement-DLL KNOB ergeben.

knob.mak
	Das Makefile für das Projekt in Visual C++ zur Erstellung des 
        ActiveX-Steuerelements.

knob.h
	Dies ist die zentrale Header-Datei für die ActiveX-Steuerelement-DLL. 
        Sie bindet weitere projektspezifische Header-Dateien ein, wie etwa 
        resource.h.

knob.cpp
	Dies ist die zentrale Quellcodedatei, die den Code für die 
        Initialisierung der DLL, ihre Beendigung und andere Verwaltungs-
        aufgaben enthält.

knob.rc
	Dies ist eine Aufstellung der Ressourcen von Microsoft Windows, die 
        das Projekt verwendet. Diese Datei kann unmittelbar im Ressourcen-
        Editor von Visual C++ bearbeitet werden.

knob.def
	Diese Datei enthält Informationen über die ActiveX-Steuerelement-DLL, 
        die für eine Ausführung unter Microsoft Windows zur Verfügung stehen 
        müssen.

knob.clw
	Diese Datei enthält Informationen, die vom Klassen-Assistenten benötigt 
        werden, um existierende Klassen zu bearbeiten oder neue Klassen hinzu-
        zufügen. Der Klassen-Assistent verwendet diese Datei auch, um 
        Informationen zu speichern, die zur Erstellung und Bearbeitung von 
        Zuordnungstabellen für Nachrichten und Dialogfelddaten und zur 
        Erstellung der Funktionsprototypen von Member-Funktionen benötigt werden.

knob.odl
	Diese Datei enthält den Quellcode in der Objektbeschreibungssprache ODL 
        für die Typbibliothek der control.

/////////////////////////////////////////////////////////////////////////////
Steuerelement Knob:

KnobCtl.h
	Diese Datei enthält die Deklaration der C++-Klasse CKnobCtrl.

KnobCtl.cpp
	Diese Datei enthält die Implementierung der C++-Klasse CKnobCtrl.

KnobPpg.h
	Diese Datei enthält die Deklaration der C++-Klasse CKnobPropPage.

KnobPpg.cpp
	Diese Datei enthält die Implementierung der C++-Klasse CKnobPropPage.

KnobCtl.bmp
	Diese Datei enthält eine Bitmap, die von einem Container verwendet 
        wird, um das Steuerelement CKnobCtrl darzustellen, wenn es auf
        einer Symbolleiste erscheint. Diese Bitmap wird von der zentralen 
        Ressourcendatei knob.rc eingebunden.

/////////////////////////////////////////////////////////////////////////////
Weitere Standarddateien: 

stdafx.h, stdafx.cpp
	Diese Dateien werden benötigt, um eine vorkompilierte Header-Datei 
        (.PCH-Datei) mit dem Namen stdafx.pch zu erstellen sowie eine 
        vorkompilierte Typendatei (.PCT-Datei) mit dem Namen stdafx.obj.

resource.h
	Dies ist die Standard-Header-Datei, in der neue Ressourcen-IDs definiert
        werden. Der Ressourcen-Editor von Visual C++ liest diese Datei und führt 
        Aktualisierungen durch.

/////////////////////////////////////////////////////////////////////////////
Weitere Hinweise:

Der Steuerelement-Assistent verwendet "ZU ERLEDIGEN:", um auf Abschnitte im 
Quellcode hinzuweisen, die hinzugefügt oder angepasst werden sollen.

/////////////////////////////////////////////////////////////////////////////
