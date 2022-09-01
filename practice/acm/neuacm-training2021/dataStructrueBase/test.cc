#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;


int n, d, nodes;
int si, ai, s[200001], a[200001];
int main()
{
    int x;
    char ch[1];
    cin >> n >> d;
    while ( n-- ) {

        cin >> ch >> x;
        if ( ch[0] == 'A' ) {
            x = (x + nodes) % d;
            a[++ai] = x;
            while ( si && a[s[si]] <= x ) {
                si--;
            }
            s[++si] = ai;
        } else {
            int i = lower_bound(s + 1, s + si + 1, ai - x + 1) - s;
            nodes = a[s[i]];
            printf("%d\n", nodes = a[s[i]]);
        }
    }
    return 0;
}