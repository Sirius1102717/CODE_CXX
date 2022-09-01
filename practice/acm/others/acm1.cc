#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s = nullptr;
    int n = 0;
    cin >> n;
    
    for ( int i = 0; i < n; i++ ) {
        /* code */
        string s = nullptr;
        cin >> s;
        if ( s == "wo shi fei wu!" ) {
            cout << "Dui!!!!!";
        } else {
            cout << s;
        }
    }
    return 0;
}
