if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]
then
    
    #wget http://mirrors.kernel.org/ubuntu/pool/universe/s/stockfish/stockfish_15.1-4_amd64.deb
    #sudo dpkg --install stockfish_15.1-4_amd64.deb
    #rm stockfish_15.1-4_amd64.deb

    make -j profile-build ARCH=x86-64-avx2

    chmod -x ./stockfish-get/src/program-linux.sh
    chmod -x ./stockfish-get/src/run-shell.sh
    chmod -x ./stockfish-get/src/compile.sh
elif [ "$(expr substr $(uname -s) 1 5)" == "CYGWIN" ]
then
    cd ./stockfish-get/src/windows/
    cmd ./install-choco.bat
    cmd ./install-msys2-choco.bat
    cd ..

    C:\tools\msys64\mingw64
    bash ./makefish.sh
    cd ..
    cd ..
elif [ "$(expr substr $(uname -s) 1 5)" == "Darwin" ]
    sudo xcode-select --install

else
    echo system not supported
    exit
fi