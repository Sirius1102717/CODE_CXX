#include<iostream>
using namespace std;
#define ll long long

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int m;
    while ( cin >> m ) {
        int input[21];
        int judge = 0;
        for ( int i = 1; i <= m; i++ ) {
            cin >> input[i];
            judge ^= input[i];
        }
        if (judge == 0) {
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
        }
        
    }
    return 0;
}

