#ifdef _WIN32
    #include <cstdlib>
    using namespace std;
    int main() {
        cout << "launching program ...\n";
        system("bash ./stockfish-get/src/run-batch.bat");
        return 0;
    } 
#else
    #include <iostream>
    #include <cstdlib>
    using namespace std;
    int main() {
        cout << "launching program ...\n";
        int out = system("bash ./stockfish-get/src/run-shell.sh");
        return 0;
    }
#endif
