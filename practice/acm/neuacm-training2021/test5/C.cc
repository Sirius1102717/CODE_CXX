#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Tree;

void inline build(int data, Tree *&root)
{
    if ( root == nullptr ) {
        root = new Tree();
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if ( data < root->data ) {
            build(data, root->left);
        } else {
            build(data, root->right);
        }
    }
}

void inline dfs(Tree *root, vector<int> &in)
{
    if ( root ) {
        in.push_back(root->data);
        dfs(root->left, in);
        dfs(root->right, in);
    } else {
        return;
    }

}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    while ( cin >> n, n != 0 ) {
        string t;
        Tree *origin = nullptr;
        cin >> t;
        for ( int i = 0; i < t.size(); i++ ) {
            build(t[i] - '0', origin);
        }
        vector<int> in;
        dfs(origin, in);
        while ( n-- ) {
            cin >> t;
            Tree *judge = nullptr;
            vector<int> ans;
            for ( int i = 0; i < t.size(); i++ ) {
                build(t[i] - '0', judge);
            }
            dfs(judge, ans);
            int len = ans.size();
            bool flag = 1;
            for ( int i = 0; i < len; i++ ) {
                if ( ans[i] != in[i] ) {
                    flag = 0;
                    cout << "NO\n";
                    break;
                }
            }
            if (flag) {
                cout << "YES\n";
            }
        }
    }


    return 0;
}
