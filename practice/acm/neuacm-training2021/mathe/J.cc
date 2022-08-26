#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e7;

int nums[1001] = {0};

void init()
{
    // memset(nums, MAXN, sizeof(int) * 1001);
    for ( int i = 2; i < 1000; i++ ) {
        int temp = 0;
        for ( int j = 1; j <= i; j++ ) {
            if ( __gcd(i, j) == 1 ) {
                temp++;
            }
        }
        if (nums[temp] == 0) {
            nums[temp] = i;
        } else {
            nums[temp] = min(nums[temp], i);
        }
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    init();
    cin >> t;
    while ( t-- ) {
        int ans = 0;
        int n;
        cin >> n;
        while ( n-- ) {
            int in;
            cin >> in;
            while (nums[in] == MAXN) {
                in++;
            }
            ans += nums[in];
        }
        cout << ans << "\n";
    }
    return 0;
}
