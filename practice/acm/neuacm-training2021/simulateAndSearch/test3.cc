#include<iostream>
#include<string>
#include<stack>
#include<cstring>
#include<cstdlib>

using namespace std;


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    int n;
    string s, a, b;
    cin >> t;
label:
    while ( t-- ) {
        cin >> n >> s;
        if ( n & 1 ) {
            cout << "ERR\n";
            goto label;
        }
        int cnt = 0;
        int nnt = 0;
        bool flag = 1;
        stack<char> fe;
        stack<char> tfe;
        bool visited[26] = { 0 };
        char  r;

        for ( int i = 0; i < n; i++ ) {
            cin >> a;
            if ( a[0] == 'F' ) {
                cin >> a;
                if ( visited[a[0] - 'a'] ) {
                    cout << "ERR\n";
                    goto label;
                } else {
                    visited[a[0] - 'a'] = 1;
                }
                cin >> a >> b;
                if ( b[0] != 'n' ) {
                    tfe.emplace('F');
                    if ( a[0] == 'n' ) {
                        flag = 0;
                        while ( input[++i][0] == 'F' ) {
                            tfe.emplace('F');
                        }
                        if ( tfe.size() ) {
                            while ( tfe.size() && input[i++][0] == 'E' ) {
                                tfe.pop();
                            }
                        }
                        if ( i + 1 < n && input[i + 1][0] == 'F' ) {
                            memset(visited, 0, sizeof visited);
                        }
                        i--;
                    }
                    if ( flag ) {
                        cnt++;
                    }
                }
                if ( flag ) {
                    fe.emplace('F');
                }
                flag = 1;

            } else if ( c == 'E' ) {
                int tmp = 0;
                if ( fe.size() ) {
                    while ( fe.size() && input[i++][0] == 'E' ) {
                        fe.pop();
                        tmp++;
                    }
                } else {
                    cout << "ERR\n";
                    goto label;
                }
                nnt = max(nnt, tmp - cnt);
                cnt = 0;
                i--;
                if ( i + 1 < n && input[i + 1][0] == 'F' ) {
                    memset(visited, 0, sizeof visited);
                }
                //flag = 1;
            }
        }
        string tmp = "O(";
        if ( nnt ) {
            tmp += "n^";
            tmp += to_string(nnt);
        } else {
            tmp += '1';
        }
        tmp += ')';

        cout << (tmp == s ? "Yes" : "No") << "\n";
    }
    return 0;
}