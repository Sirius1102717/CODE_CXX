#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <initializer_list>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

map<string, string> mp;
void init() {
    mp["iu"] = "q";
    mp["ei"] = "w";
    mp["uan"] = "r";
    mp["ue"] = "t";
    mp["un"] = "y";
    mp["sh"] = "u";
    mp["ch"] = "i";
    mp["uo"] = "o";
    mp["ie"] = "p";
    mp["ong"] = "s";
    mp["iong"] = "s";
    mp["ai"] = "d";
    mp["en"] = "f";
    mp["eng"] = "g";
    mp["ang"] = "h";
    mp["an"] = "j";
    mp["uai"] = "k";
    mp["ing"] = "k";
    mp["uang"] = "l";
    mp["iang"] = "l";
    mp["ou"] = "z";
    mp["ia"] = "x";
    mp["ua"] = "x";
    mp["ao"] = "c";
    mp["zh"] = "v";
    mp["ui"] = "v";
    mp["in"] = "b";
    mp["iao"] = "n";
    mp["ian"] = "m";
    mp["a"] = "a";
    mp["b"] = "b";
    mp["c"] = "c";
    mp["d"] = "d";
    mp["e"] = "e";
    mp["f"] = "f";
    mp["g"] = "g";
    mp["h"] = "h";
    mp["i"] = "i";
    mp["j"] = "j";
    mp["k"] = "k";
    mp["l"] = "l";
    mp["m"] = "m";
    mp["n"] = "n";
    mp["o"] = "o";
    mp["p"] = "p";
    mp["q"] = "q";
    mp["r"] = "r";
    mp["s"] = "s";
    mp["t"] = "t";
    mp["u"] = "u";
    mp["v"] = "v";
    mp["w"] = "w";
    mp["x"] = "x";
    mp["y"] = "y";
    mp["z"] = "z";
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    string s;
    string tmp;
    init();
    while(getline(cin, s)) {
        stringstream ss(s);
        ss >> tmp;
        if(tmp.size() == 1)
            cout << tmp + tmp;
        else if(tmp.size() == 2)
            cout << tmp;
        else {
            if(tmp[1] == 'h')
                cout << mp[tmp.substr(0, 2)] + mp[tmp.substr(2)];
            else if(tmp.substr(1) == "ng")
                cout << tmp[0] + mp[tmp];
            else
                cout << tmp[0] + mp[tmp.substr(1)];
        }

        while(ss >> tmp) {
            cout << ' ';
            if(tmp.size() == 1)
                cout << tmp + tmp;
            else if(tmp.size() == 2)
                cout << tmp;
            else {
                if(tmp[1] == 'h')
                    cout << mp[tmp.substr(0, 2)] + mp[tmp.substr(2)];
                else if(tmp.substr(1) == "ng")
                    cout << tmp[0] + mp[tmp];
                else
                    cout << tmp[0] + mp[tmp.substr(1)];
            }
        }
        cout << '\n';
    }

    return 0;
}
