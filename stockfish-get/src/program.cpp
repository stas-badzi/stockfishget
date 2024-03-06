#ifdef _WIN32
    #include <cstdlib>
    using namespace std;
    int main() {
        int out = system("bash ./program-windows.bat");
        return 0;        
    } 
#elif __linux__
    #include <cstdlib>
    #include <iostream>
    using namespace std;
    int main() {
        cout << "Linux!!!!!!!!!!!!!";
        int out = system("bash ./program-linux.sh");
        return 0;
    }
#elif __APPLE_
    #include <cstdlib>
    int main() {
        int out = system("bash ./program-mac.sh");
        return 0;
    }
#else
#error "OS not supported!"
#endif
