#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int q;
    ll ans[100] = { 0 };

    while ( cin >> q ) {
        for ( int i = 0; i < q; i++ ) {
            double n;
            cin >> n;
            double v = 0;
            for ( int j = 0; j < n; j++ ) {
                int temp;
                cin >> temp;
                v += temp;
            }
            ans[i] = (int)ceil(v / n);
        }

        for ( int i = 0; i < q; i++ ) {
            cout << ans[i] << endl;
        }
    }


    return 0;
}