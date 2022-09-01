#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
int main() {

    int n, t;
    scanf("%d%d", &n, &t);

    int ans = 1, mmin, mmax = -10;
    int a, pre;
    scanf("%d", &mmin);
    pre = mmin;
    for(int i = 1; i < n; i++) {
        scanf("%d", &a);
        if(a > pre) {
            if(a - mmin > mmax)
                mmax = a - mmin, ans = 1;
            else if(a - mmin == mmax)
                ans++;
        }
        mmin = min(mmin, a);
        pre = a;
    }
    cout << ans << endl;

    return 0;
}