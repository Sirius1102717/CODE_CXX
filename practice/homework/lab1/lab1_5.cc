#include <fstream>
#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
    string filename = string(argv[1]);
    ifstream ifs(filename);
    string newFinename = "new.txt";
    ofstream ofs(newFinename);
    char *s;
    while (ifs >> s) {
        ofs.write(s, sizeof s).write("\n", 1);
        cout << s << endl;
    }
    return 0;
}