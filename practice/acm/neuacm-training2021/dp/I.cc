#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool visited[1000000] = {0};

string toBinary(int c)
{
    string s;
    s.append(16, '0');
    int i = 15;
    while ( c ) {
        if ( c & 1 ) {
            s[i] = '1';
        }
        i--;
        c >>= 1;
    }
    return s;
}

void judge(string &ans, int t)
{
    int i = 15;
    while ( t ) {
        if ( t % 2 != ans[i] - '0' ) {
            ans[i] = '?';
        }
        i--;
        t >>= 1;
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int a, b, c, s;
    while ( cin >> a ) {
        if ( a == 0 ) {
            break;
        }
        memset(visited, 0, sizeof visited);
        cin >> b >> c >> s;
        string ans = toBinary(s);
        while ( !visited[s]) {
            visited[s] = 1;
            judge(ans, s);
            s = (((a * s) % c) + (b % c)) % c;
        }

        cout << ans << "\n";
    }
    return 0;
}
