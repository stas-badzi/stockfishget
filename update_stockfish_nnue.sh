#!bin/bash

cd ./src/code/stockfish/

make net > ../null.log
rm -f ../null.log

cd ..
cd ..
cd ..