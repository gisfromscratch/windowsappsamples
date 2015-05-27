// create.js (Jscript)
// Erzeugt StockChart-Datei aus Rohdaten
// unter Ausnutzung der Automatisierungsschnittstelle

// Dokument erzeugen
doc = WScript.CreateObject ("StockAuto.Document");

// Daten importieren
doc.ImportFile ("c:\\Visual Studio.NET Beispiele\\Daten\\Import\\sap.txt");

// Eigenschaften setzen
doc.name       = "Sap AG";
doc.id         = 716460;
doc.ticker     = "sag";
doc.grid       = true;
doc.average    = true;
doc.averagecnt = 10;
doc.SetColor (255,255,0);  // gelb !

// Daten speichern
doc.SaveFile ("c:\\data\\sap.stka");
