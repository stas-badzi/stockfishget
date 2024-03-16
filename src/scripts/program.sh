#!bin/bash

echo -e "\nevaluation started"

./exec/sendfish > ./logs/sendfish.log
./exec/progress

./code/stockfish/stockfish < ./storage/input.dat > ./storage/output.dat
./exec/progress

./exec/parsefish > ./logs/parsefish.log
./exec/progress

echo -e "\nevaluation sent"

exit 0