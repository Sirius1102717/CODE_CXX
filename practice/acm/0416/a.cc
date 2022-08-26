
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

string output[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    int n;
    cin >> n;
    int year1, month1, day1;
    int year2, month2, day2;
    int ty, tm, td, sd, bd;
    string s;
    while(n--) {
        scanf("%d %d %d", &year1, &month1, &day1);
        cin >> s;
        if(s == "Monday")
            bd = 0;
        else if(s == "Tuesday")
            bd = 1;
        else if(s == "Wednesday")
            bd = 2;
        else if(s == "Thursday")
            bd = 3;
        else
            bd = 4;
        scanf("%d %d %d", &year2, &month2, &day2);
        ty = year2 - year1;
        // if(ty < 0) {
        // tm = month1 - month2 + 12;
        // td = day1 - day2;
        // sd = tm * 30 + td;
        // sd %= 5;
        // bd = bd - sd + 5;
        // } else {
        tm = month2 - month1;
        if(ty < 0) tm += 12;
        td = day2 - day1;
        sd = tm * 30 + td;
        bd += sd;
        bd %= 5;
        if(bd < 0) bd += 5;
        // }
        cout << output[bd] << '\n';
    }
    return 0;
}
