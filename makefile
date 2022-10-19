CC = g++
CFLAGS = -g -Wall
CLIBS = -lX11 -lpthread


main.o: main.cpp main.h
	$(CC) $(CFLAGS) -c $<

plantes.o: plantes.cpp plantes.h
	$(CC) $(CFLAGS) -c $<

prog.exe: main.o plantes.o
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)

clean:
	clear
	rm -f *.exe *.o
