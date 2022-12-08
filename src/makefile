CC = g++
CFLAGS = -g -Wall
BIN_FOLDER = ../bin
LIB_FOLDER = ./lib

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

# Create all libs
#all: $(BIN_FOLDER)/libCImg.a $(BIN_FOLDER)/libGarden.a
all: $(OBJECT_FILES) $(BIN_FOLDER)/CImg.o

# Create CImg lib
$(BIN_FOLDER)/libCImg.a: $(BIN_FOLDER)/CImg.o
	ar -crs $@ $^
	ranlib $@

$(BIN_FOLDER)/CImg.o: $(LIB_FOLDER)/CImg.h
	$(CC) $(CFLAGS) -o $@ -c $< -lX11 -lpthread

# Create garden lib from all objects files
$(BIN_FOLDER)/libGarden.a: $(OBJECT_FILES)
	ar -crs $@ $^
	ranlib $@

$(OBJECT_FILES): $(BIN_FOLDER)/%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

# Remove all .o files in bin folder
clean:
	rm -f $(BIN_FOLDER)/*.o


# check https://codereview.stackexchange.com/questions/74136/makefile-that-places-object-files-into-an-alternate-directory-bin