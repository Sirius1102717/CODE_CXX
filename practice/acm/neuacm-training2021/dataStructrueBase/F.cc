#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int MAXN = 1e6;



int a[MAXN] = { 0 };
int qd[MAXN] = { 0 };
int ql[MAXN] = { 0 };
int ad[MAXN] = { 0 };
int al[MAXN] = { 0 };

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int ld = 0;
    int rd = 0;
    int ll = 0;
    int rl = 0;
    int cnt = 0;
    for ( int i = 0; i < k; i++ ) {
        cin >> a[i];
        while ( ld < rd && a[qd[rd - 1]] >= a[i] ) {
            rd--;
        }
        while ( ll < rl && a[ql[rl - 1]] <= a[i] ) {
            rl--;
        }
        qd[rd++] = i;
        ql[rl++] = i;
    }
    ad[cnt] = a[qd[ld]];
    al[cnt++] = a[ql[ll]];

    for ( int i = k; i < n; i++ ) {
        cin >> a[i];
        while ( ld < rd && i - qd[ld] >= k ) {
            ld++;
        }
        while ( ll < rl && i - ql[ll] >= k ) {
            ll++;
        }
        while ( ld < rd && a[qd[rd - 1]] >= a[i] ) {
            rd--;
        }
        while ( ll < rl && a[ql[rl - 1]] <= a[i] ) {
            rl--;
        }
        qd[rd++] = i;
        ql[rl++] = i;
        ad[cnt] = a[qd[ld]];
        al[cnt++] = a[ql[ll]];
    }

    for ( int i = 0; i < cnt; i++ ) {
        cout << ad[i] << " ";
    }
    cout << "\n";
    for ( int i = 0; i < cnt; i++ ) {
        cout << al[i] << " ";
    }
    cout << "\n";


    return 0;
}
