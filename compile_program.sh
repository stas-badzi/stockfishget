#!bin/bash

cd ./src/

if [ "$OSTYPE" == "linux-gnu" ]
then
    chmod -x ./scripts/build-stockfish.sh
    chmod -x ./scripts/run.sh
    chmod -x ./scripts/compile.sh
fi

bash ./scripts/build-stockfish.sh

bash ./scripts/compile.sh > ../null.log
rm -f ../null.log

cd ..

rm -f ./run
g++ -O3 -o ./run ./src/code/run.cpp