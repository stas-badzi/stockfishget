g++ -o ./sendfish ./send_stockfish.cpp
g++ -o ./parsefish ./parse_stockfish.cpp
g++ -o ./progress ./add_progress.cpp
g++ -o ./runprogram ./program.cpp


#*****LOAD the programms**********#
./sendfish
./parsefish
./progress
./runprogram