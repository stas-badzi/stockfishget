#!bin/bash

cd ./src/
./exec/launch < ./storage/yes.dat >> ./run.log
cd ..
echo -e "exited\n"
exit 0