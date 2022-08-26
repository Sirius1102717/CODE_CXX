#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int sum = 0;
    unordered_map<char, Node *> next;

    void add(string word);
    bool isPrefix(string prefix);
};

// typedef unordered_map<char, Node *> mn;

int ans;


void Node::add(string word)
{
    Node *cur = this;
    int len = word.size();
    for ( int i = 0; i < len; i++ ) {
        char c = word[i];
        if ( !cur->next[c] ) {
            cur->next[c] = new Node();
            // cur->next[c]->sum++;
        }
        cur = cur->next[c];
        cur->sum++;
    }
}

bool Node::isPrefix(string prefix)
{
    Node *cur = this;
    int len = prefix.size();
    ans = 0;
    for ( int i = 0; i < len; i++ ) {
        char c = prefix[i];
        if ( !cur->next[c] ) {
            return false;
        }
        cur = cur->next[c];
    }
    ans = cur->sum;
    return true;
}



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s;
    Node *root = new Node();
    while ( getline(cin, s), s != "" ) {
        root->add(s);
    }
    while ( cin >> s ) {
        root->isPrefix(s);
        cout << ans << "\n";
    }

    return 0;
}
