#include<bits/stdc++.h>
using namespace std;


bool judge(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
    int x21 = x2 - x1;
    int x43 = x4 - x3;
    int y21 = y2 - y1;
    int y43 = y4 - y3;
    if ( y43 * x21 == x43 * y21 ) {
        return true;
    } else {
        return false;
    }
}

int *init(int x1, int y1, int x2, int y2)
{
    int n[2] = { x2 - x1, y2 - y1 };
    return n;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ ) {
        int n = 0;
        cin >> n;
        int answer = 0;
        int x[n];
        int y[n];
        for ( int j = 0; j < n; j++ ) {
            cin >> x[j] >> y[j];
        }
    }

    
    return 0;
}
