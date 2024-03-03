if ($IsLinux) {
    sudo apt-get install stockfish
    chmod -x ./stockfish-get/src/program-linux.sh
    chmod -x ./stockfish-get/src/run-shellscript.sh
}

Set-Location ./stockfish-get/src/
./compile.ps1 | Out-Null
g++ -O3 -o ./launch ./launcher.cpp

<# load programm #>
Set-Location ..
Get-Content ./src/storage/no.dat | ./src/launch | Out-File ./run.log
Set-Location ..
<# ************ #>

g++ -O3 -o ./run ./stockfish-get/src/run.cpp