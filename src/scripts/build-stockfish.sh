#!bin/bash

if [ "$OSTYPE" == "linux-gnu" ]
then
    echo Linux

    cd ./code/stockfish/

    make -j profile-build ARCH=x86-64-avx2
    chmod +x ./stockfish

    cd ..
    cd ../scripts/

    cd ..

    

    exit 0

elif [ "$OSTYPE" == "freebsd" ]
then
    echo FreeBSD
    
    cd ./code/stockfish/

    make -j profile-build ARCH=x86-64-avx2
    chmod +x ./stockfish

    cd ..
    cd ../scripts/

    chmod -x ./program-linux.sh
    chmod -x ./run-shell.sh
    chmod -x ./compile.sh

    cd ..

    exit 0

elif  [ "$OSTYPE" == "cygwin32" ]
then
    echo Cygwin x32

    cd ./code/stockfish/
    
    C:/msys64/mingw32 make -j build ARCH=x86-32
    #C:/msys32/mingw32 make -j build ARCH=x86-32

    cd ..
    cd ..

    exit 0

elif  [ "$OSTYPE" == "cygwin64" ]
then
    echo Cygwin x64

    cd ./code/stockfish/
    
    C:/msys64/mingw64 make -j build ARCH=x86-64

    cd ..
    cd ..

    exit 0

elif  [ "$OSTYPE" == "cygwin" ]
then
    echo Cygwin unspecified

    cd ./code/stockfish/
    
    make -j build ARCH=x86-64

    cd ..
    cd ..

    exit 0

elif  [ "$OSTYPE" == "msys" ]
then
    echo msys

    cd ./code/stockfish/
    
    make -j build ARCH=x86-64

    cd ..
    cd ..

    exit 0

elif [ "$OSTYPE" == "Darwin" ]
then
    echo MacOS

    cd ./code/stockfish/
    make clean
    make build
    make net
    chmod 755 ./stockfish
    
    cd ..
    cd ..

    exit 0
else
    echo system $OSTYPE not supported
    exit 1
fi