#include<iostream>
using namespace std;
const double EPS = 1e-8;
const int N = 1e6 + 1;

int Next[N];

void init(string p)
{
    int i = 0, j = Next[0] = -1;
    int len = p.size();
    while ( i < len ) {
        if ( j == -1 || p[i] == p[j] ) {
            j++, i++;
            Next[i] = p[i] != p[j] ? j : Next[j];
        } else {
            j = Next[j];
        }
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string p;
    while ( cin >> p ) {
        if ( p == "." ) {
            break;
        }
        int len = p.size();
        int ans = 1;
        init(p);
        if ( len % (len - Next[len]) == 0 ) {
            ans = len / (len - Next[len]);
        }

        cout << ans << "\n";
    }

    return 0;
}
