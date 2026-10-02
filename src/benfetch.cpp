#include <iostream>
#include <fstream>
#include "fetchThis.h"
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
using namespace std;


/* 
all this just to be able to centre the console text :(
*/
int terminalWidth() {
    winsize w{};
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0 && w.ws_col > 0)
        return w.ws_col;
    return 80;
}

// Length as displayed: skips ANSI escape sequences and UTF-8 continuation bytes
int visibleLength(const string& s) {
    int len = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '\033' && i + 1 < s.size() && s[i + 1] == '[') {
            i += 2;
            while (i < s.size() && !isalpha(static_cast<unsigned char>(s[i]))) ++i;
            // loop's ++i steps past the final letter (e.g. 'm')
        } else if ((static_cast<unsigned char>(s[i]) & 0xC0) != 0x80) {
            ++len;
        }
    }
    return len;
}

void printCentered(const string& text) {
    int pad = max(0, (terminalWidth() - visibleLength(text)) / 2);
    cout << string(pad, ' ') << text << '\n';
}



int main(){


    

    int width = terminalWidth();

    cout << string(width, '-') << '\n';
    printCentered("\033[1;37mSystem Info\033[0m");
    cout << string(width, '-') << '\n';  
    printCentered("\033[93mOperating System: \033[0m" + os());
    printCentered("\033[93mKernel: \033[0m" + kernel());
    printCentered("\033[93mProcessor: \033[0m" + cpu());
    printCentered("\033[93mRam: \033[0m" + ram());
    printCentered("\033[93mGPU: \033[0m");
    printCentered("\033[93mUser \033[0m");
    cout << string(width, '-') << '\n';
    
    return 0;
}
