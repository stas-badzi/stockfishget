#ifdef _WIN32
    #include <cstdlib>
    using namespace std;
    int main() {
        system("bash ./program-windows.bat");
        return 0;        
    } 
#elif __linux__
    #include <unistd.h>
    using namespace std;
    int main() {
        execl("./program-linux.sh","./program-linux.sh",NULL);
        return 0;
    }
#elif __APPLE_
    #include <unistd.h>
    int main() {
        execl("./program-mac.sh","./program-mac.sh",NULL);
        return 0;
    }
#else
#error "OS not supported!"
#endif
