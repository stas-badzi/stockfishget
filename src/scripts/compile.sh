#!bin/bash

mkdir ./exec/
cd ./exec/

rm -f ./sendfish
rm -f ./parsefish
rm -f ./launch

cd ../code/

g++ -O3 -o ../exec/launch ./launcher.cpp
g++ -O3 -o ../exec/sendfish ./send_stockfish.cpp 
g++ -O3 -o ../exec/parsefish ./parse_stockfish.cpp

g++ -O3 -o ../exec/checkfish ./check_stockfish.cpp
g++ -O3 -o ../exec/sendcheckfish ./send_check_stockfish.cpp 
g++ -O3 -o ../exec/parsecheckfish ./parse_check_stockfish.cpp


cd ../exec

if [ "$OSTYPE" == "linux-gnu" ]
then
    chmod +x ./sendfish
    chmod +x ./parsefish
    chmod +x ./launch
    chmod +x ./sendcheckfish
    chmod +x ./parsecheckfish
    chmod +x ./checkfish
elif [ "$OSTYPE" == "darwin" ]
then
    chmod 755 ./sendfish
    chmod 755 ./parsefish
    chmod 755 ./launch
    chmod 755 ./sendcheckfish
    chmod 755 ./parsecheckfish
    chmod 755 ./checkfish
fi

#*****LOAD the programms**********#
./sendcheckfish
./parsecheckfish
./checkfish

./sendfish
./parsefish
./launch < ../storage/no.dat > ../run.log

cd ..

exit 0