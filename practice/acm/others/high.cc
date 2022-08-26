#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
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

template <class T>
void read(T& c) {
    T x, y = 1;
    do {
        c = getchar();
        if(c == '-') {
            y = -1;
        }
    } while(!isdigit(c));
    do {
        c = getchar();
        x = x * 10 + c - '0';
    } while(isdigit(c));
    x *= y;
}

void erase_pre_zero(string& s) {
    size_t c = 0;
    size_t len = s.size() - 1;
    for(size_t i = 0; i < len; i++) {
        if(s[i] != '0') {
            break;
        }
        c++;
    }
    s.erase(0, c);
}

string high_add(string a, string b) {
    erase_pre_zero(a), erase_pre_zero(b);
    if(b.size() > a.size()) {
        swap(a, b);
    }
    b.insert(0, a.size() - b.size(), '0');
    bool c = 0;
    for(int i = a.size() - 1; i >= 0; i--) {
        int tmp = a[i] + b[i] + c - '0' * 2;
        c = tmp / 10;
        a[i] = tmp % 10 + '0';
    }
    if(c) {
        return '1' + a;
    } else {
        return a;
    }
}

string high_sub(string a, string b) {
    erase_pre_zero(a), erase_pre_zero(b);
    bool flag = 0;
    if(b.size() > a.size()) {
        swap(a, b);
        flag = 1;
    }
    b.insert(0, a.size() - b.size(), '0');
    bool c = 0;
    for(int i = a.size() - 1; i >= 0; i--) {
        int tmp = a[i] - b[i] - c;
        if(tmp < 0) {
            c = 1;
            tmp += 10;
        } else {
            c = 0;
        }
        a[i] = abs(tmp) % 10 + '0';
    }
    erase_pre_zero(a);
    if(c || flag) {
        return '-' + a;
    } else {
        return a;
    }
}


    // string a = "56923075075435";
    // string b = "97034670432646";

string high_mul(string a, string b) {
    erase_pre_zero(a), erase_pre_zero(b);
    if(b.size() > a.size()) {
        swap(a, b);
    }
    int lenb = b.size();
    int lena = a.size() - 1;

    string ans = "0";
    for(int j = 0; j < lenb; j++) {
        ans += '0';
        string s = a;
        int c = 0;
        for(int i = lena; i >= 0; i--) {
            int tmp = (s[i] - '0') * (b[j] - '0') + c;
            c = tmp / 10;
            s[i] = tmp % 10 + '0';
        }
        ans = high_add(ans, to_string(c) + s);
    }
    erase_pre_zero(ans);
    return ans;
}

//高精初低精
string high_div(string a, ll b) {
    erase_pre_zero(a);
    ll c = 0;
    int len = a.size();
    string ans = "";
    for(int i = 0; i < a.size(); i++) {
        c = c * 10 + a[i] - '0';
        if(c >= b) {
            ans += (c / b + '0');
            c %= b;
        } else {
            ans += '0';
        }
    }
    erase_pre_zero(ans);
    return ans;
}

// 高精除高精
string high_div(string a, string b) {
    erase_pre_zero(a), erase_pre_zero(b);
    if(a.size() < b.size()) {
        return "0";
    }
    string ans = "";
    string c = a.substr(0, b.size());
    for(int i = b.size(); i < a.size(); i++) {
        c += a[i];
        ans += "0";
        if(high_sub(a, b)[0] != '-') {
            while(high_sub(c, b)[0] != '-') {
                c = high_sub(c, b);
                ans = high_add(ans, "1");
            }
        }
    }
    erase_pre_zero(ans);
    return ans;
}

ll high_mod(string a, ll b) {
    erase_pre_zero(a);
    ll c = 0;
    int len = a.size();
    string ans = "";
    for(int i = 0; i < a.size(); i++) {
        c = c * 10 + a[i] - '0';
        if(c >= b) {
            ans += (c / b + '0');
            c %= b;
        } else {
            ans += '0';
        }
    }
    return c;
}

string high_mod(string a, string b) {
    erase_pre_zero(a), erase_pre_zero(b);
    if(a.size() < b.size()) {
        return "0";
    }
    string ans = "";
    string c = a.substr(0, b.size() - 1);
    for(int i = b.size() - 1; i < a.size(); i++) {
        c += a[i];
        ans += "0";
        if(high_sub(a, b)[0] != '-') {
            while(high_sub(c, b)[0] != '-') {
                c = high_sub(c, b);
                ans = high_add(ans, "1");
            }
        }
    }
    erase_pre_zero(c);
    return c;
}

int main(int argc, char* argv[]) {
    int tmp;
    string a = "750347604376043";
    string b = "305430";
    cout << high_div(a, b);
    // cout << high_mul(a, b);
    while(cin >> tmp) {
        string x;
        if(!tmp) {
            string b;
            cin >> x >> b;
            cout << high_add(x, b) << endl;
        } else {
            ll b;
            cin >> x >> b;
            if(tmp == 1) {
                cout << high_mul(x, to_string(b)) << endl;
            } else {
                cout << (high_mod(x, b) == 0) << endl;
            }
        }
    }
    return 0;
}
