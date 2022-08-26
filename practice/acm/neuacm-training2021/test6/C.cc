#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 1;

struct Tire
{
    int sum;
    Tire *next[26];
    bool isWord;
    Tire()
    {
        isWord = false;
        for ( int i = 0; i < 26; i++ )
            next[i] = NULL;
    }
};


Tire *root;

void build(string s)
{
    int len = s.size();
    Tire *cur = root;
    for ( int i = 0; i < len; i++ ) {
        int index = s[i] - 'a';
        if ( !cur->next[index] ) {
            cur->next[index] = new Tire;
        }
        cur = cur->next[index];
        cur->sum++;
    }
    cur->isWord = true;
}

bool query(string s)
{
    int len = s.size();
    Tire *cur = root;
    for ( int i = 0; i < len; i++ ) {
        int index = s[i] - 'a';
        if ( !cur->next[index] ) {
            return false;
        }
        cur = cur->next[index];
    }
    return cur->isWord;
}


string s[N];

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    root = new Tire;
    int size = 0;
    while ( cin >> s[size], cin.get() != EOF ) {
        build(s[size++]);
    }
    for ( int j = 0; j < size; j++ ) {
        string t = s[j];
        int len = t.size();
        for ( int i = 1; i < len; i++ ) {
            if ( query(t.substr(0, i)) && query(t.substr(i, len)) ) {
                cout << t << "\n";
                break;
            }
        }
    }
    return 0;
}
