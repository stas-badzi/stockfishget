powershell

./sendfish | Out-File ./logs/sendfish.log
./progress

Get-Content ./storage/input.dat | ./stockfish-windows/stockfish-windows-x86-64-avx2 | Out-File ./storage/output.dat
./progress

./parsefish | Out-File ./logs/parsefish.log
./progress

exit