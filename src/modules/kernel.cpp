#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

string kernel(){

    string kernel;

    ifstream infile("/proc/sys/kernel/osrelease");
    getline(infile, kernel);
    infile.close();

    return kernel;
}