#ifdef _WIN32
    #include <cstdlib>
    using namespace std;
    int main() {
        system("bash ./stockfish-get/src/run-batch.bat");
        return 0;
    } 
#else
    #include <unistd.h>
    using namespace std;
    int main() {
        execl("./stockfish-get/src/run-shell.sh","./stockfish-get/src/run-shell.sh",NULL);
        return 0;
    }
#endif
