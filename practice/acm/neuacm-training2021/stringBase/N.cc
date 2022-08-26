#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int N = 110001;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}

int Len[N << 1];

int init(string s, string &str)
{
    int len = s.size();
    str += '^';
    for ( int i = 0; i < len; i++ ) {
        str += '#';
        str += s[i];
    }
    str += "#$";
    return len <<= 1;
}

int manacher(string str, int len)
{
    int ans = 0, pos = 0, r = 0;
    for ( int i = 1; i <= len; i++ ) {
        if ( r > i ) {
            Len[i] = min(r - i, Len[(pos << 1) - i]);
        } else {
            Len[i] = 1;
        }
        while ( str[i + Len[i]] == str[i - Len[i]] ) {
            Len[i]++;
        }
        if ( Len[i] + i > r ) {
            r = Len[i] + i;
            pos = i;
        }
        ans = max(ans, Len[i]);
    }
    return ans - 1;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s;
    int len;
    while ( cin >> s ) {
        string str = "";
        len = init(s, str);
        cout << manacher(str, len) << "\n";
    }

    return 0;
}
