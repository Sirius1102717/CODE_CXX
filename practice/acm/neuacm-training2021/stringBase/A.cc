#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

typedef unordered_map<string, string> um;

um m;



int main(int argc, char *argv[])
{
    // std::ios::sync_with_stdio(false);
    string in, spell, func;

    while ( getline(cin, in), in != "@END@" ) {
        int pos = in.find(']');
        spell = in.substr(0, pos + 1);
        func = in.substr(pos + 2, in.size());
        m.emplace(spell, func);
        // spell = spell.substr(1, spell.size() - 2);
        // m.emplace(func, spell);
    }
    int t;
    cin >> t;
    getchar();
    while ( t-- ) {
        getline(cin, in);
        if ( in[0] == '[' ) {
            if ( m.find(in) != m.end() ) {
                cout << m[in] << endl;
            } else {
                cout << "what?\n";
            }
        } else {
            bool flag = 1;
            for ( um::iterator it = m.begin(); it != m.end(); ++it ) {
                if ( it->second == in ) {
                    cout << it->first.substr(1, it->first.size() - 2) << endl;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout << "what?\n";
            }
        }

    }
    return 0;
}