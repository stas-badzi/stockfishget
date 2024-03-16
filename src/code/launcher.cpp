#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cstdlib>

#ifdef _WIN32
    #include <windows.h>

    using namespace std;

    void sleepMiliseconds(unsigned milliseconds) {
        Sleep(milliseconds);
        return;
    }
#else
    #include <unistd.h>

    using namespace std;
    
    void sleepMiliseconds(unsigned milliseconds) {
        usleep(milliseconds * 1000); // takes microseconds
        return;
    }
#endif

void removeNull(string &edit) {
    for (int i = 0; i < edit.size(); ++i) {
        if (!isalpha(edit[i]) && !isdigit(edit[i]) && edit[i] != '/' && edit[i] != '-' && edit[i] != ' ') {
            edit.erase(edit.begin() + i);
            --i;
        }
    }
    return;
}

int main() {
    ifstream fin;
    ofstream fout;

    bool run;
    cin >> run;
    if (!run) {
        cout << "Here are all program logs since the last compile\n";
        return 0;
    }

    time_t _tm = time(NULL);
    struct tm * curtime = localtime ( &_tm );
    cout << "\nLaunched: " << asctime(curtime) << "\n" << flush;

    while (run) {
        sleepMiliseconds(1);

        fin.open("./input.in");
        int action;
        fin >> action;

        if (action > 0) {
            string command = "";
            fin >> command;
            removeNull(command);

            if (command == "exit") {
                fout.open("./input.in");
                fout << '0';
                fout.close();

                fout.open("./output.out");
                fout << "1\nsuccess";
                fout.close();

                time_t _tm =time(NULL );
                struct tm * curtime = localtime ( &_tm );
                cout << "Process exited: " << asctime(curtime) << "\n";
                run = false;
            } else if (command == "eval") {
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

                    removeNull(fen);

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

                    int progress = 0;
                    fout.open("./storage/progress.dat");
                    fout << "0";
                    fout.close();

                    fout.open("./input.in");
                    fout << '0';
                    fout.close();

                    system("./exec/sendfish > ./logs/sendfish.log");
                    system("./code/stockfish/stockfish < ./storage/input.dat > ./storage/output.dat");
                    system("./exec/parsefish > ./logs/parsefish.log");
                    

                    fout.open("./output.out");
                    fout << "1";
                    cout << "\n\toutput:";

                    fin.open("./storage/input.dat");

                    string value;

                    do {
                        value.clear();
                        fin >> value;
                        fout << "\n" << value;
                        cout << "\n\t\t" << value;
                    } while (value.size() > 0);

                    fin.close();

                    cout << "\n" << flush;
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

                    int progress = 0;
                    fout.open("./storage/progress.dat");
                    fout << "0";
                    fout.close();

                    fout.open("./input.in");
                    fout << '0';
                    fout.close();
                    
                    system("./exec/sendfish > ./logs/sendfish.log");
                    system("./code/stockfish/stockfish < ./storage/input.dat > ./storage/output.dat");
                    system("./exec/parsefish > ./logs/parsefish.log");
                    

                    fout.open("./output.out");
                    fout << "1";
                    cout << "\n\toutput:";

                    fin.open("./storage/input.dat");

                    string value;

                    do {
                        value.clear();
                        fin >> value;
                        fout << "\n" << value;
                        cout << "\n\t\t" << value;
                    } while (value.size() > 0);

                    fin.close();

                    cout << "\n" << flush;
                    fout.close();

                } else {
                    fout.open("./input.in");
                    fout << '0';
                    fout.close();

                    fout.open("./output.out");
                    fout << "1\nwrong syntax \"eval >" << subcommand << "<\". expected [fen/startpos]";
                    fout.close();

                    cout << "\nwrong syntax \"eval >" << subcommand << "<\". expected [fen/startpos]\n" << flush;
                }
            } else {
                fout.open("./input.in");
                fout << '0';
                fout.close();

                fout.open("./output.out");
                fout << "1\nunknown command \"" << command << "\"";
                fout.close();
                
                cout << "\nunknown command \"" << command << "\"\n" << flush;
            }
        }

        fin.close();
    }

    return 0;        
}
