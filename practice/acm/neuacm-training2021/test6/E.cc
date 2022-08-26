#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;

int Next[N];

string s, p;
int ans, len;

void init(string p)
{
    int j = 0, k = -1;
    ans = 0;
    Next[0] = -1;
    int len = p.size();
    while ( j < len ) {
        if ( k == -1 || p[j] == p[k] ) {
            j++, k++;
            Next[j] = p[j] != p[k] ? k : Next[k];
        } else {
            k = Next[k];
        }
    }
}

int kmp(string s, string p, int pos)
{
    int i = pos, j = 0;
    int sLen = s.size(), pLen = p.size();
    while ( i < sLen && j < pLen ) {
        if ( j == -1 || s[i] == p[j] ) {
            i++, j++;
        } else {
            j = Next[j];
        }
        if ( j == pLen ) {
            return i;
        }
    }
    return -1;
}




int getAns(string s, string p)
{
    int i = 0;
    while ( 1 ) {
        i = kmp(s, p, i);
        if ( i == -1 ) {
            break;
        }
        i += len;
        ans++;
    }
    return ans;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while ( t-- ) {
        cin >> s >> n;
        for ( int i = 0; i < n; i++ ) {
            cin >> p;
            init(p);
            cout << getAns(s, p) << "\n";
        }
    }

    return 0;
}
