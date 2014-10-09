#projekt do predmetu ZP

COMPIL = g++

prog_kalendar: main.o funkce.o
	$(COMPIL) main.o funkce.o -o prog_kalendar

funkce.o: funkce.cpp funkce.h
	$(COMPIL) funkce.cpp -c

main.o: main.cpp
	$(COMPIL) main.cpp -c
