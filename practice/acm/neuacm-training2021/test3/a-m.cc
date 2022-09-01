#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;



vector<int> a;
vector<int> b;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int maxMove = 0;
    for ( int i = 0; i < n; i++ ) {
        int in;
        cin >> in;
        // m[in]++;
        a.emplace_back(in);
    }
    for ( int i = 0; i < n; i++ ) {
        int in;
        // maxMove = max(m[a[i]], maxMove);
        cin >> in;

        b.emplace_back(in);
    }
    reverse(b.begin(), b.end());
    // label:
    int j = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( a[i] == b[i] ) {
            while ( j < n && (b[j] == a[i] || a[i] == a[j]) ) {
                j++;
            }
            if ( j == n ) {
                cout << "No\n";
                return 0;
            }
            swap(b[i], b[j]);
            j++;
            // goto label;
        }
    }
    bool flag = false;
    for ( int i = 0; i < n; i++ ) {
        if ( a[i] == b[i] ) {
            flag = true;
        }
    }
    if ( flag || n == 1 ) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for ( int i = 0; i < n; i++ ) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
    // cin >> n;
}
