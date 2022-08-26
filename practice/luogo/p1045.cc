#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}


string highMul(string a, string b)
{
    int lena = a.size();
    int lenb = b.size();
    int len = lena + lenb;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int temp[len];
    memset(temp, 0, sizeof(temp));
    string ans = "";
    for ( int j = 0; j < lena; j++ ) {
        for ( int i = 0; i < lenb; i++ ) {

            temp[i + j] += (a[j] - '0') * (b[i] - '0');
            temp[i + j + 1] += temp[i + j] / 10;
            temp[i + j] %= 10;
        }
    }
    while ( temp[len - 1] == 0 && len > 1 ) {
        len--;
    }
    for ( int i = 0; i < len; i++ ) {
        ans += (temp[len - 1 - i] + '0');
    }

    return ans;
}

string qmi(int base, int power)
{
    string ans = "1";
    while ( power > 0 ) {
        if ( power & 1 ) {
            ans = highMul(ans, to_string(base));
        }
        power >>= 1;
        base *= base;
    }
    return ans;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p;
    cin >> p;
    string ans = qmi(2, 1279);
    int len = ans.size();
    int temp;
    if (len < 500) {
        temp = 500 - len; 
    } else {
        temp = len - 500;
    }
    printf("%d\n", ans.size());
    return 0;
}
