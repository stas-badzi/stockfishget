if  [ "$OSTYPE" == "cygwin32" ]
then

    echo Cygwin x32 > ./src/code/null.log

    cd ./src/code/stockfish/
    
    make net >> ../null.log

    cd ..
    rm null.log
    cd ..
    cd ..

    exit 0

elif  [ "$OSTYPE" == "cygwin64" ]
then
    echo Cygwin x6 > ./src/null.log

    cd ./src/code/stockfish/
    
    make net >> ../null.log

    cd ..
    rm null.log
    cd ..
    cd ..

    exit 0

elif  [ "$OSTYPE" == "cygwin" ]
then
    echo Cygwin unspecified > ./src/null.log

    cd ./src/code/stockfish/
    
    make net >> ../null.log
    make net >> ../null.log

    cd ..
    rm null.log
    cd ..
    cd ..

    exit 0

elif  [ "$OSTYPE" == "msys" ]
then
    echo msys > ./src/code/null.log

    cd ./src/code/stockfish/
    
    make net >> ../null.log

    cd ..
    rm null.log
    cd ..
    cd ..

    exit 0
else
    echo system $OSTYPE not supported
    exit 1
fi