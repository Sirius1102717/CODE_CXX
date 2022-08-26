#include<iostream>
#include<string>
using namespace std;
const double EPS = 1e-8;



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);

    string s, p;
    while ( cin >> s, s[0] != '#' ) {
        cin >> p;
        size_t i = 0;
        int ans = 0;
        int len = p.size();
        while ( 1 ) {
            i = s.find(p, i);
            if ( i == string::npos ) {
                break;
            }
            i += len;
            ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
