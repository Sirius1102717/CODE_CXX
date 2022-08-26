#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    while ( cin >> n ) {
        int judge = 0;
        for ( int i = 0; i < n; i++ ) {
            int j;
            cin >> j;
            if ( j % 2 == 0 ) {
                judge++;
            }
        }
        if ( judge % 2 == 0 ) {
            cout << "Mike" << "\n";
        } else {
            cout << "Constantine" << "\n";
        }

    }
    return 0;
}
