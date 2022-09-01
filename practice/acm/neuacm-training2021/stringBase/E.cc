#include<iostream>
using namespace std;
const double EPS = 1e-8;
const int N = 4e5 + 1;

int Next[N], len;


void init(string p)
{
    // memset(Next, 0, sizeof Next);
    // len = p.size();
    int i = 0, j = -1;
    Next[0] = -1;
    len = p.size();
    while ( p[i] ) {
        if ( j == -1 || p[i] == p[j] ) {
            Next[++i] = ++j;
        } else {
            j = Next[j];
        }
    }

}

void visit(int i)
{
    if ( Next[i] == 0 ) {
        return;
    }
    visit(Next[i]);

    cout << Next[i] << " ";
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s;
    while ( cin >> s ) {
        init(s);
        visit(len);
        cout << len << "\n";
    }

    return 0;
}
