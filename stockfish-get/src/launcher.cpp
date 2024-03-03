#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#ifdef _WIN32
    #include <windows.h>
    #include <cstdlib>

    using namespace std;

    void runFile(char * file) {
        system(file);
        return;
    }

    void sleep(unsigned milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    using namespace std;

    void runFile(char * file) {
        execl(file,file,NULL);
        return;
    }
    
    void sleep(unsigned milliseconds) {
        usleep(milliseconds * 1000); // takes microseconds
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

    time_t _tm =time(NULL );
    struct tm * curtime = localtime ( &_tm );
    cout << "\nLaunched: " << asctime(curtime) << "\n";

    while (run) {
        sleep(1);

        fin.open("../input.in");
        int action;
        fin >> action;

        if (action > 0) {
            string command = "";
            fin >> command;
            removeNull(command);

            if (command == "exit") {
                fout.open("../input.in");
                fout << '0';
                fout.close();

                fout.open("../output.out");
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
                    string fen = "";
                    getline(fin,fen);
                    removeNull(fen);

                    fout.open("./storage/output.dat");
                    fout << "1 ";
                    fout.close();

                    cout << "Evaluation:\n\tfen: " << fen;

                    int n = 0;
                    string domove = "";
                    fin >> domove;

                    vector<string> froms;
                    vector<string> toos;
                    if (domove == "moves") {
                        bool move = true;
                        while (move) {
                            string frm;
                            string to;
                            fin >> frm >> to;
                            if (to.size() > 0) {
                                froms.push_back(frm);
                                toos.push_back(to);
                                ++n;
                            } else {
                                move = false;
                            }
                        }
                    }

                    fout << n << "\n" << fen;
                    if (n > 0) {
                        cout << "\n\tmoves:";
                    }
                    for (int i = 0; i < n; ++i) {
                        fout << "\n" << froms[i] << " " << toos[i];
                        cout << "\n\t\t" << froms[i] << " " << toos[i];
                    }
                    cout << "\n";
                    fout.close();

                    int progress = 0;
                    fout.open("./storage/progress.dat");
                    fout << "0";
                    fout.close();

                    runFile("./runprogram");
                    while (progress < 3) {
                        sleep(1);
                        fin.open("./storage/progress.dat");
                        fin >> progress;
                        cout << progress;
                        fin.close();
                    }

                    fout.open("../output.out");
                    fout << "1\n";
                    fout.close();

                    fout.open("../input.in");
                    fout << '0';
                    fout.close();

                } else if (subcommand == "startpos") {
                    string fen = "";
                    getline(fin,fen);
                    removeNull(fen);

                    fout.open("./storage/output.dat");
                    fout << "0 ";
                    fout.close();

                    cout << "Evaluation:\n\tstartpos";

                    int n = 0;
                    string domove = "";
                    fin >> domove;

                    vector<string> froms;
                    vector<string> toos;
                    if (domove == "moves") {
                        bool move = true;
                        while (move) {
                            string frm;
                            string to;
                            fin >> frm >> to;
                            if (to.size() > 0) {
                                froms.push_back(frm);
                                toos.push_back(to);
                                ++n;
                            } else {
                                move = false;
                            }
                        }
                    }

                    fout << n;
                    if (n > 0) {
                        cout << "\n\tmoves:";
                    }
                    for (int i = 0; i < n; ++i) {
                        fout << "\n" << froms[i] << " " << toos[i];
                        cout << "\n\t\t" << froms[i] << " " << toos[i];
                    }
                    cout << "\n";
                    fout.close();

                    int progress = 0;
                    fout.open("./storage/progress.dat");
                    fout << "0";
                    fout.close();
                    
                    runFile("./runprogram");
                    while (progress < 3) {
                        sleep(1);
                        fin.open("./storage/progress.dat");
                        fin >> progress;
                        fin.close();
                    }

                    fout.open("../output.out");
                    fout.close();

                    fin.open("./storage/input.dat");
                    string line = "1";
                    while (line.size() > 0) {
                        fout << line << "\n";
                        fin >> line;
                        removeNull(line);
                    }                 

                    fout.open("../input.in");
                    fout << '0';
                    fout.close();

                } else {
                    fout.open("../input.in");
                    fout << '0';
                    fout.close();

                    fout.open("../output.out");
                    fout << "1\nwrong syntax \"eval >" << subcommand << "<\". expected [fen/startpos]";
                    fout.close();

                    cout << "\nwrong syntax \"eval >" << subcommand << "<\". expected [fen/startpos]\n";
                }
            } else {
                fout.open("../input.in");
                fout << '0';
                fout.close();

                fout.open("../output.out");
                fout << "1\nunknown command \"" << command << "\"";
                fout.close();
                
                cout << "\nunknown command \"" << command << "\"\n";
            }
        }

        fin.close();
    }

    return 0;        
}
