./sendfish > ./logs/sendfish.log
./progress

./stockfish-windows/stockfish-windows-x86-64-avx2.exe < ./storage/input.dat > ./storage/output.dat
./progress

./parsefish > ./logs/parsefish.log
./progress