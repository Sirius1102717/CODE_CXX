#include <bits/stdc++.h>
#define il inline
#define maxn 500005
#define ll long long
const int inf = 0x3f3f3f3f;
using namespace std;
int main() {
    string l, r;
    int n;
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output_1.txt", "w", stdout);
    cin >> n;

    int a[4], b[4], c[4];
    cout << a << " " << b << " " << c << endl;
    
    // while(n--) {
        // cin >> l >> r;
        // int m = 0;
// 
        // for(int i = 0; i < 4; i++) {
            // a[i] = r[i] - l[i];
            // if(a[i] < 0)
                // b[i] = 10 + a[i];
            // else if(!a[i])
                // b[i] = 0;
            // else
                // b[i] = a[i] - 10;
        // }
        // int k = 2, kk = 2, kkk = 2, kkkk = 2;
        // int output = inf;
        // while(k--) {
            // swap(a[0], b[0]);
            // kk = 2;
            // while(kk--) {
                // swap(a[1], b[1]);
                // kkk = 2;
                // while(kkk--) {
                    // swap(a[2], b[2]);
                    // kkkk = 2;
                    // while(kkkk--) {
                        // swap(a[3], b[3]);
                        // for(int i = 0; i < 4; ++i) {
                            // c[i] = a[i];
                            // cout << c[i] << ' ';
                        // }
                        // int l = 0, r = 0;
                        // int flag = 1;
                        // int ans = 0;
                        // while(l < 4) {
                            // l = 0;
                            // while(!c[l] && l < 4)
                                // ++l;
                            // r = l;
                            // if(l == 4)
                                // break;
                            // while(c[r + 1] * c[r] > 0) {
                                // r++;
                            // }
                            // if(c[l] > 0)
                                // flag = -1;
                            // else
                                // flag = 1;
                            // while(1) {
                                // int flgg = 0;
                                // ++ans;
                                // for(int i = l; i <= r; ++i) {
                                    // c[i] += flag;
                                    // if(!c[i])
                                        // flgg = 1;
                                // }
                                // if(flgg)
                                    // break;
                            // }
                        // }
                        // cout << ans << endl;
                        // output = min(output, ans);
                    // }
                // }
            // }
        // }
        // cout << output << endl;
    // }
    // cout << sad;
    return 0;
}