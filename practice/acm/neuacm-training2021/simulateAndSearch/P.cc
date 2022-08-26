#include<bits/stdc++.h>
using namespace std;
const int N = 101;
typedef long long ll;

int a[N] = {0};
vector<int> v1, v2;


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, cnt = 0;
    // string s;
    cin >> n;
    int n1 = 0, n2 = 0;
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            for ( int k = 0; k < n; k++ ) {
                v1.push_back(a[i] * a[j] + a[k]);
                if ( a[k] ) {
                    v2.push_back(a[k] * (a[j] + a[i]));
                }
            }
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll ans = 0;
    for ( int i = 0; i < v1.size(); i++ ) {
        int l = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
        int h = upper_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
        ans += h;
        ans -= l;
    }
    cout << ans << "\n";


    return 0;
}
