#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

struct Node
{
    int sum;
    Node *next[26];
    Node()
    {
        sum = 0;
        for ( int i = 0; i < 26; i++ ) {
            next[i] = NULL;
        }
    }
};

void add(string s, Node *root)
{
    Node *cur = root;
    int len = s.size();
    for ( int i = 0; i < len; i++ ) {
        int index = s[i] - 'a';
        if ( !cur->next[index] ) {
            cur->next[index] = new Node();
            // cur->next[index]->sum++;
        }
        cur = cur->next[index];
        cur->sum++;
    }
}

void find(string prefix, Node *root)
{
    Node *cur = root;
    int len = prefix.size(), i;
    for ( i = 0; i < len; i++ ) {
        int index = prefix[i] - 'a';
        cur = cur->next[index];
        cout << prefix[i];
        if ( cur->sum == 1 ) {
            return;
        }
    }
}



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int cnt = 0;
    Node *root = new Node();
    string s[1001];

    while ( cin >> s[cnt++] ) {
        add(s[cnt - 1], root);
    }
    for ( int i = 0; i < cnt; i++ ) {
        cout << s[i] << " ";
        find(s[i], root);
        cout << "\n";
    }
    return 0;
}