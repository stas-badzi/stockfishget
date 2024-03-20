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
    fout.open("./storage/input.dat");
    if (t == 0) {
        fout << "uci\nisready\nucinewgame\nsetoption name Debug Log File value ./logs/stockfish.log\nposition startpos";
        cout << "startpos";

        if (n > 0) {
            fout << " moves";
            cout << "\nmoves:";
        }

        for (int i = 0; i < n; ++i) {
            string move;
            fin >> move;
            fout << " " << move;
            cout << "\n\t" << move;
        }
        fout << "\ngo depth 10";
        fout.close();

        fout.open("storage/output.dat");
        fout << "moves: " << (n > 0) << "\n";
        fout.close();
    }
    if (t == 1) {
        string fen;
        string input;

        // position
        fin >> input;
        fen = input;

        // turn
        fin >> input;
        fen.push_back(' ');
        fen += input;

        // castles
        fin >> input;
        fen.push_back(' ');
        fen += input;
                    
        // en passaunt
        fin >> input;
        fen.push_back(' ');
        fen += input;
                    
        // no capture & pawn move counter
        fin >> input;
        fen.push_back(' ');
        fen += input;

        // black turn counter
        fin >> input;
        fen.push_back(' ');
        fen += input;

        removeNull(fen);

        if (fen[0] == ' ' || fen[1] == ' ') {removeSpaces(fen);}
        fout << "uci\nisready\nucinewgame\nsetoption name Debug Log File value ./logs/stockfish.log\nposition fen " << fen;
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

        fout << "\ngo depth 10";
        fout.close();

        fout.open("storage/output.dat");
        fout << "moves: " << (n > 0) << "\n";
        fout.close();
    }
    fin.close();

    cout << "\n";
    return 0;
}
