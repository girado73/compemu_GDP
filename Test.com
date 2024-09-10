# Routine Display
1 LDAZ 10 # L ̈adt die Zahl 10 in den Akku, das ist die erste ausgegebene Speicherstelle
2 WRA 1000  ̈a t e r
3 LOAD
4 DISPA
5 LDAA 1000
# Rettet den Akku in die Speicherstelle 1000 zur Sicherung f ̈ur sp
# L ̈adt die aktuelle Speicherstelle in den Akku
# Zeigt den Wert an
# L ̈adt die aktuelle Speicherstelle der Ausgabe aus der Sicherung in Speicherstelle 1000
6 ADDZ -1 7 JNZ 2
9 STOP
# Erniedrigt die Speicherstelle
# Wenn noch nicht fertig, fahre mit Zeile 2 fort # Ende des Programms
