#!bin/bash

cd ./src/
mkdir ./logs/

./exec/launch < ./storage/yes.dat >> ./run.log
cd ..
echo -e "exited\n"
exit 0