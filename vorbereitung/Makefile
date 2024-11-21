# Name des .tar.gz archivs
TAR_FILE = aufgabe1.tar.gz

# all anweisung
all:  pack

# Pack anweisung zum archivieren
pack:
	tar -czvf $(TAR_FILE) *

# Aufräumregel
clean:
	rm -f $(TAR_FILE)

.PHONY: all pack clean