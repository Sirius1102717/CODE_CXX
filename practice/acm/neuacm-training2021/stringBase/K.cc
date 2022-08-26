#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5 + 1;

struct Node
{
    int next[10];
    bool end;
}nodes[N];



bool flag;
int tot;


inline void build(string s)
{
    if (flag) {
        return;
    }
    int l = 0, len = s.size();
    for (int i = 0; i < len; i++) {
        int k = s[i] - '0';
        if (!nodes[l].next[k]) {
            nodes[l].next[k] = ++tot;
        } else if (i == len - 1){
            flag = 1;
        }
        l = nodes[l].next[k];
        flag = nodes[l].end ? 1 : flag;
    }
    nodes[l].end = 1;
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);

    int t, n;
    cin >> t;
    string s;
    while ( t-- ) {
        cin >> n;
        flag = tot = 0;
        // Node *root = new Node();
        memset(nodes, 0, sizeof nodes);
        for ( int i = 0; i < n; i++ ) {
            cin >> s;
            build(s);
        }
        flag ? cout << "NO\n" : cout << "YES\n";

    }
    return 0;

}
