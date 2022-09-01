#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int MAXN = 5e5 + 1;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}

int dp[5001] = {0};

int a[MAXN] = {0};
int b[MAXN] = {0};

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    for (int i = 0; i < 10; i++) {
        cout << (i + i >> 1 )<< "\n";
    }
    return 0;
}
