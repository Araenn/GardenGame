CC = g++
CFLAGS = -g -Wall
CLIBS = -lpthread


main.o: main.cpp main.h
	$(CC) $(CFLAGS) -c $<

plantes.o: plantes.cpp plantes.h
	$(CC) $(CFLAGS) -c $<

fleurs.o: fleurs.cpp fleurs.h
	$(CC) $(CFLAGS) -c $<

seed_plants.o: seed_plants.cpp seed_plants.h
	$(CC) $(CFLAGS) -c $<

legumes.o: legumes.cpp legumes.h
	$(CC) $(CFLAGS) -c $<

jardiniers.o: jardiniers.cpp jardiniers.h
	$(CC) $(CFLAGS) -c $<

champs.o: champs.cpp champs.h
	$(CC) $(CFLAGS) -c $<

coordonnees.o: coordonnees.cpp coordonnees.o
	$(CC) $(CFLAGS) -c $<

prog.exe: main.o plantes.o fleurs.o seed_plants.o legumes.o jardiniers.o champs.o coordonnees.o
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)

clean:
	clear
	rm -f *.exe *.o
