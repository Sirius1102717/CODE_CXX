#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int N = 1e4 + 1;


int Next[N];

int kmp(string s, string p)
{
    int i = 0, j = 0;
    int sLen = s.size(), pLen = p.size();
    int sum = 0;
    while ( i < sLen && j < pLen ) {
        if ( j == -1 || s[i] == p[j] ) {
            i++;
            j++;
        } else {
            j = Next[j];
        }
        if ( j == pLen ) {
            sum++;
            j = Next[j];
        }
    }
    return sum;
}

void init(string p)
{
    // memset(Next, 0, sizeof Next);
    int len = p.size();
    int j = 0, k = -1;
    Next[0] = -1;
    while ( j < len ) {
        if ( k == -1 || p[j] == p[k] ) {
            j++, k++;
            Next[j] = p[j] != p[k] ? k : Next[k];
        } else {
            k = Next[k];
        }
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string s, p;
    while ( t-- ) {
        cin >> p >> s;
        init(p);
        cout << kmp(s, p) << "\n";
    }

    return 0;
}
