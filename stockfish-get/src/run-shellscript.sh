pwsh

Set-Location ./stockfish-get/src/
Get-Content ./storage/yes.dat | ./launch | Out-File -Append ../run.log
Set-Location ..
Set-Location ..