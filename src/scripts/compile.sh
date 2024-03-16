#!bin/bash

cd ./exec/

rm -f ./sendfish
rm -f ./parsefish
rm -f ./launch

cd ../code/

g++ -o ../exec/sendfish ./send_stockfish.cpp
g++ -o ../exec/parsefish ./parse_stockfish.cpp
g++ -O3 -o ../exec/launch ./launcher.cpp

mkdir ./exec/
cd ../exec

if [ "$OSTYPE" == "linux-gnu" ]
then
    chmod +x ./sendfish
    chmod +x ./parsefish
    chmod +x ./launch
fi

#*****LOAD the programms**********#
./sendfish
./parsefish
./launch < ../storage/no.dat > ../run.log

cd ..

exit 0