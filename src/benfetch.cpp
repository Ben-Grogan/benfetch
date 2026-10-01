#include <iostream>
#include <fstream>
#include "fetchThis.h"
#include <iomanip>
using namespace std;





int main(){
    int width = 80;
    cout << "System Info" << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "\033[93mOperating System: \033[0m"+os() << endl;
    cout << "\033[93mKernel: \033[0m"+kernel() << endl;
    cout << "\033[93mProcessor: \033[0m"+cpu() << endl;
    cout << "\033[93mRam: \033[0m" << endl;
    cout << "\033[93mGPU: \033[0m" << endl;
    cout << "\033[93mUser \033[0m" << endl; 
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    return 0;
}
