
1 LDAZ 123
2 WRA 10
3 LDAZ 124
4 WRA 9
5 LDAZ 125
6 WRA 8
LDAZ 126
WRA 7
LDAZ 127
WRA 6
LDAZ 128
WRA 5
LDAZ 129
WRA 4
LDAZ 130
WRA 3
LDAZ 131
WRA 2
LDAZ 132
20 WRA 1

# Routine Display
21 LDAZ 10 # L Ãàadt die Zahl 10 in den Akku, das ist die erste ausgegebene Speicherstelle 10
22 WRA 1000 # Rettet den Akku in die Speicherstelle 1000 zur Sicherung f Ãàur sp 10
23 LOAD # Lädt die aktuelle Speicherstelle in den Akku 123
24 DISPA # Zeigt den Wert an 123
25 LDAA 1000 # L Ãàadt die aktuelle Speicherstelle der Ausgabe aus der Sicherung in Speicherstelle 1000 10
26 ADDZ -1 # Erniedrigt die Speicherstelle 9
27 JNZ 21 # Wenn noch nicht fertig, fahre mit Zeile 2 fort # Ende des Programms
28 STOP
