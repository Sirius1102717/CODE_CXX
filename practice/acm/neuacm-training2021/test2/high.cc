#include<bits/stdc++.h>
using namespace std;
#define ll long long
// const double EPS = 1e-8;
// const ll MAXN = 1e18;
// const int N = 100;



string highAdd(string a, string b)
{
    int lenb = b.size();
    a.insert(0, 1, '0');
    int lena = a.size();
    for ( int i = lenb - 1, j = lena - 1; i > 0; i--, j-- ) {
        int sum = a[j] + b[i] - '0' * 2;
        // a[j - 1] += ((char)(sum / 10) + '0');
        sum %= 10;
        a[j] = (char)sum + '0';
    }
    if (a[0] == '0') {
        a.erase(0, 1);
    }
    return a;
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string a = "607293582095303";
    string b = "547235929453";
    string ans = highAdd(a, b);
    cout << ans;
    return 0;
}
