# compemu_GDP
Computer Emulation Projekt for GDP

Github Repository: 
https://github.com/girado73/compemu_GDP

## Usage:

### Compilation:

`make` um compemu zu compilieren

`make tests` um tests zu compilieren

### Execution:

`./bin/compemu <Program File>` wobei Program File die datei ist welche ausgeführt werden soll

`./bin/tester` führt die Tests aus 

### Important Informations:

- Der Cursor beginnt bei 0 in den Programmen und er nimmt nicht Annotation von Zahlen am Zeilenbeginn als Linieneingabe sondern Zählt intern.
- Der RAM hat genauch 1001 Speicherplätze. Von 0 bis 1000.
- Kommentare sind mit `#` möglich. Alles nach dem Zeichen wird ignoriert.
- Nach dem Befehlt `STOP` wird das Programm beendet, egal in welchem Abschnitt verwendet.
