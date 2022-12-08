clear
cd ./src/
make clean
make
cd ../test/
make clean

# prog.exe || testCImg.exe || testObjects.exe
executable_name="prog.exe"

make $executable_name
cd ../

$1 ./$executable_name