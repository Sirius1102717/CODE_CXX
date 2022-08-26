#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n[1001] = { 0 };
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    // int n;
    for ( int i = 0; i < t; i++ ) {
        cin >> n[i];
        // cout << n / 10 << endl;
    }
    for ( int i = 0; i < t; i++ ) {
        cout << (n[i] + 1) / 10 << "\n";
    }
    return 0;
}
