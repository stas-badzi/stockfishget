#!bin/bash

cd ./src/

if [ "$OSTYPE" == "linux-gnu" ]
then
    chmod +x ./scripts/build-stockfish.sh
    chmod +x ./scripts/run.sh
    chmod +x ./scripts/compile.sh
elif [ "$OSTYPE" == "darwin" ]
then
    chmod 755 ./scripts/build-stockfish.sh
    chmod 755 ./scripts/run.sh
    chmod 755 ./scripts/compile.sh
fi

bash ./scripts/build-stockfish.sh > ../null.log

bash ./scripts/compile.sh > ../null.log
rm -f ../null.log

cd ..

rm -f ./run
g++ -O3 -o ./run ./src/code/run.cpp

if [ "$OSTYPE" == "linux-gnu" ]
then
    chmod +x ./run
elif [ "$OSTYPE" == "darwin" ]
then
    chmod 755 ./run
fi
