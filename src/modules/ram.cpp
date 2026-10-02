#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string ram(){
    
    string line;
    int total_ram {};
   
    ifstream ram("/proc/meminfo");

    while (ram.good()) {
        ram >> line >> total_ram;
        if (line == "MemTotal:") {
            break;
        }
    }
    ram.close();

    string s_out;
    s_out = to_string((total_ram / 1000)/1000) + "GB";

    return s_out;
}