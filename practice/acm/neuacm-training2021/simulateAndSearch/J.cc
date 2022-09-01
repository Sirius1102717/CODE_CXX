#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int ans = N;

bool isPrime[N] = { 0 };
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
    if ( b == e ) {
        ans = 0;
        return;
    }
    bool isVisited[N] = { 0 };
    queue<node> q;
    q.push(b);
    while ( q.size() ) {
        node pre = q.front();
        q.pop();
        if ( pre.val == e ) {
            cout << pre.step << "\n";
            return;
        }
        for ( int i = 1; i < 5; i++ ) {
            node now = pre;
            now.num[i]++;
            if (now.num[i] == 10) {
                now.num[i] = 1;
            }
            now.initVal();
            if ( !isVisited[now.val] ) {
                now.step++;
                q.push(now);
                isVisited[now.val] = 1;
            }
        }
        for ( int i = 1; i < 5; i++ ) {
            node now = pre;
            now.num[i]--;
            if ( now.num[i] == 0 ) {
                now.num[i] = 9;
            }
            now.initVal();
            if ( !isVisited[now.val] ) {
                now.step++;
                q.push(now);
                isVisited[now.val] = 1;
            }
        }
        for ( int i = 1; i < 4; i++ ) {
            node now = pre;
            swap(now.num[i], now.num[i + 1]);
            now.initVal();
            if ( !isVisited[now.val] ) {
                now.step++;
                q.push(now);
                isVisited[now.val] = 1;
            }
        }

    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while ( t-- ) {
        int b, e;
        cin >> b >> e;
        bfs(b, e);
    }

    return 0;
}
