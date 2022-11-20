CC = g++
CFLAGS = -g -Wall
CLIBS_PATH = -I../bin -L../bin
CLIBS_BASICS = -lX11 -lpthread -lm
CLIBS = $(CLIBS_BASICS)
BIN_FOLDER = ../bin

SRC_FILES =\
	champs.cpp\
	coordonnees.cpp\
	fleurs.cpp\
	jardiniers.cpp\
	legumes.cpp\
	plantes.cpp\
	plants_types.cpp\
	seed_plants.cpp\
	varietes.cpp\
	orientation.cpp\
	CImgUtils.cpp\
	moodType.cpp\
	crops.cpp

OBJECT_FILES = $(SRC_FILES:%.cpp=$(BIN_FOLDER)/%.o)


# Create main executable
prog.exe: main.o
	$(CC) $(CFLAGS) -o ../$@ $^ $(OBJECT_FILES) $(CLIBS_PATH) $(CLIBS)

main.o: main.cpp main.h
	$(CC) $(CFLAGS) -c $<

# Create CImg test executable
testCImg.exe: testCImg.o
	$(CC) $(CFLAGS) -o ../$@ $^ $(CLIBS) $(CLIBS_PATH)

testCImg.o: testCImg.cpp testCImg.h
	$(CC) $(CFLAGS) -c $<

# Create objects test executables
testObjects.exe: testObjects.o
	$(CC) $(CFLAGS) -o ../$@ $^ 

testObjects.o: testObjects.cpp testObjects.h
	$(CC) $(CFLAGS) -c $<

# Remove all .o files in bin folder
clean:
	rm -f ../*.exe *.o 
