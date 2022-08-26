#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int M = 1e5;

// template <class T>
// size_t getHash(T s)
// {
//     return hash<T>{}(s);
// }


priority_queue<int, vector<int>, greater<int>> up;

priority_queue<int> down;


int main(int argc, char *argv[])
{
    int p, cnt, m;
    scanf("%d", &p);
    while ( p-- ) {

        scanf("%d %d", &cnt, &m);
        printf("%d %d\n", cnt, (m + 1) / 2);

        while ( down.size() ) {
            down.pop();
        }
        while ( up.size() ) {
            up.pop();
        }
        int x, res = 1;

        for ( int i = 1; i <= m; i++ ) {
            scanf("%d", &x);
            if ( up.empty() || up.top() <= x ) {
                up.push(x);
            } else {
                down.push(x);
            }
            if ( up.size() > down.size() + 1 ) {
                down.push(up.top());
                up.pop();
            }
            if ( down.size() > up.size() ) {
                up.push(down.top());
                down.pop();
            }
            if ( i & 1 ) {
                if ( res % 10 == 1 ) {
                    cout << up.top();
                } else {
                    cout << " " << up.top();
                }
                if ( res % 10 == 0 || i == m ) {
                    cout << endl;
                }
                res++;
            }
        }
    }
    return 0;
}