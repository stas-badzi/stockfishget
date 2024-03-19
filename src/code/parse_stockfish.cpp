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
    int empty = 0;
    string instring;
    fin.open("./storage/output.dat");
    fout.open("./storage/input.dat");

    instring = "";
    getline(fin,instring);
    bool remove_null = removeNulls(instring);
    bool remove_spaces = (instring[0] == ' ');
    cout << "remove null: " << remove_null << "\nremove spaces: " << remove_spaces << "\n\n";
    bool run = true;
    while (run) {
        if (remove_null) {removeNulls(instring);}
        if (remove_spaces) {removeSpaces(instring);}

        cout << instring << "\n";

        if (instring.rfind("Stockfish", 0) == 0) { // pos=0 limits the search to the prefix
            //fout << instring;
        } else if (instring.rfind("id", 0) == 0) { // pos=0 limits the search to the prefix
            //fout << instring;
        } else if (instring.rfind("option", 0) == 0) { // pos=0 limits the search to the prefix
            //fout << instring;
        } else if (instring.rfind("uci", 0) == 0) { // pos=0 limits the search to the prefix
            //fout << instring;
        } else if (instring.rfind("ready", 0) == 0) { // pos=0 limits the search to the prefix
            //fout << instring;
        } else if (instring.rfind("info", 0) == 0) { // pos=0 limits the search to the prefix
            //fout << instring;
        } else if (instring.rfind("NNUE evaluation", 0) == 0) { // pos=0 limits the search to the prefix
            for (int i = 0; i < instring.size(); ++i) {
                if (isdigit(instring[i]) || instring[i] == '-' || instring[i] == '.' || ( instring[i] == ' ' && isdigit(instring[i-1]) ) ) {
                    if (instring[i] == ' ') {
                        fout << "\n";
                        cout << "\n";
                    } else {
                        fout << instring[i];
                        cout << instring[i];
                    }
                }
            }
        } else if (instring.rfind("Final evaluation", 0) == 0) { // pos=0 limits the search to the prefix
            if (instring.find("Final evaluation: none (in check)")) {
                system("./exec/checkfish > ./logs/checkfish.log");
                return 1;
            }
            for (int i = 0; i < instring.size(); ++i) {
                if ( (isdigit(instring[i]) || instring[i] == '-' || instring[i] == '.' || ( instring[i] == ' ' && isdigit(instring[i-1]) ) ) && i <= 40 ) {
                    if (instring[i] == ' ') {
                        fout << "\n";
                        cout << "\n";
                    } else {
                        fout << instring[i];
                        cout << instring[i];
                    }
                }
            }
        }

        
        instring = "";
        getline(fin,instring);
        if (instring.size() <= 0) {
            ++empty;
            if (empty > 2) {
                run = false;
            }
        } else {
            empty = 0;
        }
        
        
    }
    
    fout.close();
    /*
    fout.open("./storage/output.dat");
    fout << "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR/w KQkq - 0 1";
    fout.close();
    //*/
    return 0;
}
