#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e4;
int ans = N;

bool isPrime[N] = { 0 };
// bool isVisited[N] = { 0 };


void EraPrime()
{
    isPrime[1] = 1;
    for ( int i = 2; i <= N; i++ ) {
        if ( !isPrime[i] ) {
            for ( int j = 2; j * i <= N; j++ ) {
                isPrime[j * i] = 1;
            }
        }
    }
}


struct node
{
    int val;
    int num[5];
    int step;

    node(int v)
    {
        step = 0;
        val = v;
        int i = 4;
        while ( v ) {
            num[i--] = v % 10;
            v /= 10;
        }
    }

    void initVal()
    {
        val = 0;
        for ( int i = 1; i < 5; i++ ) {
            val *= 10;
            val += num[i];
        }
    }
};

node change(node n, int index, int m)
{
    n.num[index] = m;
    n.initVal();
    return n;
}


void bfs(int b, int e)
{
    if (b == e) {
        ans = 0;
        return;
    }
    bool isVisited[N] = { 0 };

    isVisited[b] = 1;
    int step = 0;

    queue<node> q;
    q.push(b);
    while ( q.size() ) {
        node pre = q.front();
        q.pop();
        if ( pre.val == e ) {
            ans = pre.step;
            return;
        }
        for ( int i = 0; i <= 9; i++ ) {
            for ( int j = 1; j <= 5; j++ ) {
                if ( j == 1 && i == 0 ) {
                    continue;
                }
                node now = change(pre, j, i);
                if ( !isPrime[now.val] && !isVisited[now.val] ) {
                    now.step = pre.step + 1;
                    q.push(now);
                    isVisited[now.val] = 1;
                }
            }
        }
    }


}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    EraPrime();
    int t;
    cin >> t;
    while ( t-- ) {
        int b, e;
        cin >> b >> e;
        bfs(b, e);
        if (ans != N) {
            cout << ans << "\n";
        } else {
            cout << "Impossible\n";
        }


    }


    return 0;
}
