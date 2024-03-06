echo Process:\n...

./sendfish > ./logs/sendfish.log
./progress

echo \n1...

stockfish < ./storage/input.dat > ./storage/output.dat
./progress

echo \n2...

./parsefish > ./logs/parsefish.log
./progress

echo \n3\nFinished