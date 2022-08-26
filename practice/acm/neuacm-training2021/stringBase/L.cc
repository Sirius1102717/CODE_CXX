#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

struct Node
{
    int sum;
    Node *next[26];
    Node *fail;
    // bool isWord;

    Node()
    {
        sum = 0;
        fail = nullptr;
        // isWord = false;
        for ( int i = 0; i < 26; i++ ) {
            next[i] = nullptr;
        }
    }
};

void build(string s, Node *root)
{
    Node *cur = root;
    int len = s.size();
    for ( int i = 0; i < len; i++ ) {
        int index = s[i] - 'a';
        if ( !cur->next[index] ) {
            cur->next[index] = new Node;
        }
        cur = cur->next[index];
        // cur->sum++;
    }
    cur->sum++;
    // cur->isWord = 1;

}

int query(string s, Node *root)
{
    int ans = 0;
    Node *cur = root;
    int len = s.size();
    for ( int i = 0; i < len; i++ ) {
        int index = s[i] - 'a';
        while ( !cur->next[index] && cur != root ) {
            cur = cur->fail;
        }
        cur = cur->next[index];
        if ( !cur ) {
            cur = root;
        }
        Node *tmp = cur;
        while ( tmp != root ) {
            if ( tmp->sum >= 0 ) {
                ans += tmp->sum;
                // tmp->isWord = 0;
                tmp->sum = -1;
            } else {
                break;
            }
            tmp = tmp->fail;
        }
    }
    return ans;
}

void init(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while ( !q.empty() ) {
        Node *pre;
        Node *cur = q.front();
        q.pop();
        for ( int i = 0; i < 26; i++ ) {
            if ( cur->next[i] ) {
                if ( cur == root ) {
                    cur->next[i]->fail = root;
                } else {
                    pre = cur->fail;
                    while ( pre ) {
                        if ( pre->next[i] ) {
                            cur->next[i]->fail = pre->next[i];
                            break;
                        }
                        pre = pre->fail;
                    }
                    if ( !pre ) {
                        cur->next[i]->fail = root;
                    }
                }
                q.push(cur->next[i]);
            }
        }
    }
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t, n;
    string s;
    cin >> t;
    while ( t-- ) {
        Node *root = new Node;
        cin >> n;
        for ( int i = 0; i < n; i++ ) {
            cin >> s;
            build(s, root);
        }
        init(root);
        cin >> s;
        cout << query(s, root) << "\n";
    }

    return 0;
}
