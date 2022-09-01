#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define EPS 1e-8

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    while ( cin >> t ) {
        int chess[1000] = { 0 };
        int n;
        for ( int i = 0; i < t; i++ ) {
            cin >> n;
            int ans = 0;
            for ( int j = 1; j <= n; j++ ) {
                cin >> chess[j];
            }
            sort(chess + 1, chess + 1 + n);
            int k = 1;
            for ( int i = n; i > 0; i -= 2 ) {
                ans ^= (chess[i] - chess[i - 1] - 1);
            }
            if ( ans ) {
                cout << "Georgia will win" << "\n";
            } else {
                cout << "Bob will win" << "\n";
            }
        }
    }
    return 0;
}
