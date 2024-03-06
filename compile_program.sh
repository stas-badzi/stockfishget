cd ./stockfish-get/src/

bash ./build-stockfish.sh

bash ./compile.sh > ../run.log
g++ -O3 -o ./launch ./launcher.cpp

cd ./stockfish/src/
make -j profile-build ARCH=x86-64
cd ..
cd ..

# load programm
cd ..
./src/launch < ./src/storage/no.dat > ./run.log
cd ..
# ************

g++ -O3 -o ./run ./stockfish-get/src/run.cpp