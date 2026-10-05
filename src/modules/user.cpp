#include <pwd.h>
#include <unistd.h>
#include <string>

using namespace std;

string user() {
    passwd* pw = getpwuid(getuid());
    return pw ? pw->pw_name : "Unknown";
}