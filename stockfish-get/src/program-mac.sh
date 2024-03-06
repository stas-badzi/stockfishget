./sendfish > ./logs/sendfish.log
./progress

./stockfish-mac/stockfish-arm64 < ./storage/input.dat > ./storage/output.dat
./progress

./parsefish > ./logs/parsefish.log
./progress