#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    int n;

    fin.open("storage/progress.dat");
    fin >> n;
    ++n;

    fout.open("storage/progress.dat");
    fout << n;

    return 0;
}
