#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    cout << "launching stockfish-get ...\n";
    int out = system("bash ./src/scripts/run.sh");
    return 0;
}