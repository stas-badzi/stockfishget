pwsh

./sendfish | Out-File ./logs/sendfish.log
./progress

Get-Content ./storage/input.dat | ./stockfish-mac/stockfish | Out-File ./storage/output.dat
./progress


./parsefish | Out-File ./logs/parsefish.log
./progress

exit