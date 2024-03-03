#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void removeNull(string &edit) {
    for (int i = 0; i < edit.size(); ++i) {
        if (!isalpha(edit[i]) && !isdigit(edit[i]) && edit[i] != '/' && edit[i] != '-' && edit[i] != ' ') {
            edit.erase(edit.begin() + i);
            --i;
        }
    }
    return;
}

void removeSpaces(string &edit) {
    for (int i = 0; i < edit.size(); ++i) {
        edit.erase(edit.begin() + i);
    }
    return;
}

int main() {
    ifstream fin;
    ofstream fout;
    //string input = "startpos";
    int t,n;
    t = n = 0;
    fin.open("./storage/output.dat");
    fin >> t >> n;
    cout << "action: " << t << "\n";
    if (t == 0) {
        fout.open("./storage/input.dat");
        fout << "uci\nisready\nucinewgame\nsetoption name multipv value 3\nposition startpos";
        cout << "startpos";

        if (n > 0) {
            fout << " moves";
            cout << "\nmoves:";
        }

        for (int i = 0; i < n; ++i) {
            string move1,move2;
            fin >> move1;
            fin >> move2;
            fout << " " << move1 << " " << move2;
            cout << "\n\t" << move1 << " " << move2;
        }
        fout << "\neval";
    }
    if (t == 1) {
        string fen = "";
        getline(fin,fen);
        removeNull(fen);
        if (fen[0] == ' ' || fen[1] == ' ') {removeSpaces(fen);}
        fout.open("./storage/input.dat");
        fout << "uci\nisready\nucinewgame\nsetoption name multipv value 3\nposition fen " << fen;
        cout << "fen: " << fen;

        if (n > 0) {
            fout << " moves";
            cout << "\nmoves:";
        }
        
        for (int i = 0; i < n; ++i) {
            string move1,move2;
            fin >> move1;
            fin >> move2;
            fout << " " << move1 << " " << move2;
            cout << "\n\t" << move1 << " " << move2;
        }

        fout << "\neval";
    }
    fin.close();

    cout << "\n";
    return 0;
}
