#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool removeNulls(string &edit) {
    int start = edit.size();
    for (int i = 0; i < edit.size(); ++i) {
        if (!isalpha(edit[i]) && !isdigit(edit[i]) && edit[i] != '/' && edit[i] != '-' && edit[i] != ' ' && edit[i] != '+' && edit[i] != '|' && edit[i] != '(' && edit[i] != ')' && edit[i] != ':' && edit[i] != '.') {
            edit.erase(edit.begin() + i);
            --i;
        }
    }
    return (edit.size() != start);
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

    fin.open("./input.in");
    int action;
    fin >> action;

    if (action > 0) {
        string command = "";
        fin >> command;
        removeNulls(command);

        if (command == "eval") {
            string subcommand;
            fin >> subcommand;
            if (subcommand == "fen") {
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

                removeNulls(fen);

                fout.open("./storage/output.dat");
                fout << "1 ";

                cout << "Evaluation:\n\tfen: " << fen;

                int n = 0;
                string domove = "";
                fin >> domove;

                vector<string> mvs;
                if (domove == "moves") {
                    bool move = true;
                    while (move) {
                        string mv;
                        fin >> mv;
                        if (mv.size() > 0) {
                            mvs.push_back(mv);
                            ++n;
                        } else {
                            move = false;
                        }
                    }
                }

                fin.close();

                fout << n << "\n" << fen << "\n";

                cout << "\n\t" << domove;

                for (int i = 0; i < n; ++i) {
                    fout << mvs[i] << " ";
                    cout << "\n\t\t" << mvs[i];
                }
                cout << "\n" << flush;
                fout.close();

                int out;
                out = system("./exec/sendcheckfish > ./logs/sendcheckfish.log");
                out = system("./code/stockfish/stockfish < ./storage/input.dat >> ./storage/output.dat");
                out = system("./exec/parsecheckfish > ./logs/parsecheckfish.log");

                fout.open("./input.in");
                fout << '0';
                fout.close();

            } else if (subcommand == "startpos") {

                fout.open("./storage/output.dat");
                fout << "0 ";

                cout << "Evaluation:\n\tstartpos";

                int n = 0;
                string domove = "";
                fin >> domove;

                vector<string> mvs;
                if (domove == "moves") {
        bool move = true;
        while (move) {
            string mv;
            fin >> mv;
            if (mv.size() > 0) {
                mvs.push_back(mv);
                ++n;
            } else {
                move = false;
            }
        }
                }

                fin.close();

                fout << n << "\n";
        
                cout << "\n\t" << domove;
        
                for (int i = 0; i < n; ++i) {
                    fout << mvs[i] << " ";
                    cout << "\n\t\t" << mvs[i];
                }
                cout << "\n" << flush;
                fout.close();

                int out;
                out = system("./exec/sendcheckfish > ./logs/sendcheckfish.log");
                out = system("./code/stockfish/stockfish < ./storage/input.dat >> ./storage/output.dat");
                out = system("./exec/parsecheckfish > ./logs/parsecheckfish.log");

            }
        }
    }

    fin.close();
    
    return 0;
            
}