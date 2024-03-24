#!bin/bash

mkdir -p ./exec/

cd ./exec/

rm -f ./sendfish
rm -f ./parsefish
rm -f ./launch

cd ../code/

g++ -O3 -o ../exec/launch ./launcher.cpp
g++ -O3 -o ../exec/sendfish ./send_stockfish.cpp 
g++ -O3 -o ../exec/parsefish ./parse_stockfish.cpp


cd ../exec

if [ "$OSTYPE" == "linux-gnu" ]
then
    chmod +x ./sendfish
    chmod +x ./parsefish
    chmod +x ./launch
elif [ "$OSTYPE" == "darwin" ]
then
    chmod 755 ./sendfish
    chmod 755 ./parsefish
    chmod 755 ./launch
fi

#*****LOAD the programms**********#
./sendfish
./parsefish
./launch < ../storage/no.dat > ../run.log

#rm -f input.in

cd ..

exit 0