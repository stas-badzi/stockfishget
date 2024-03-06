if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]
then
    
    wget http://mirrors.kernel.org/ubuntu/pool/universe/s/stockfish/stockfish_15.1-4_amd64.deb
    sudo dpkg --install stockfish_15.1-4_amd64.deb
    rm stockfish_15.1-4_amd64.deb

    chmod -x ./stockfish-get/src/program-linux.sh
    chmod -x ./stockfish-get/src/run-shell.sh
    chmod -x ./stockfish-get/src/compile.sh

else
    echo no need to install anything
fi

cd ./stockfish-get/src/
bash ./compile.sh > ../run.log
g++ -O3 -o ./launch ./launcher.cpp

cd ./stockfish/src/
make -j profile-build ARCH=x86-64-avx2
cd ..
cd ..

# load programm
cd ..
./src/launch < ./src/storage/no.dat > ./run.log
cd ..
# ************

g++ -O3 -o ./run ./stockfish-get/src/run.cpp