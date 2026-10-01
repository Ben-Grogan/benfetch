#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

string os(){

    string line, os_name;
    ifstream infile("/etc/os-release");

    while(infile.good()) {
        getline(infile, line);
        if (line.find("PRETTY_NAME") != string::npos) {
            os_name = line.substr(line.find("=") + 1);
            break;
        }
    }
    infile.close();

    // Remove ""
    os_name = os_name.substr(1, os_name.length() - 2);

    return os_name;    
}