#include<bits/stdc++.h>
#include <functional>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int N = 100;



string highAdd(string a, string b)
{
    int lenb = b.size();
    if ( lenb > a.size() ) {
        return highAdd(b, a);
    }
    string ans = a;
    ans.insert(0, 1, '0');
    int lena = ans.size();
    b.insert(0, lena - lenb, '0');
    int temp = 0;
    for ( int i = lena - 1; i >= 0; i-- ) {
        int sum = ans[i] + b[i] - '0' * 2 + temp;
        temp = sum / 10;
        sum %= 10;
        ans[i] = sum + '0';
    }
    if ( ans[0] == '0' ) {
        ans.erase(0, 1);
    }
    return ans;
}


string highSub(string a, string b)
{
    string ans = a;
    int len = ans.size();
    if ( (a < b && len == b.size()) || len < b.size() ) {
        return "-" + highSub(b, a);
    }
    b.insert(0, len - b.size(), '0');



    int temp = 0;
    for ( int i = len; i >= 0; i-- ) {
        int sum = ans[i] - b[i] - temp;
        if ( sum < 0 && i > 0 ) {
            sum += 10;
            temp = 1;
        } else {
            temp = 0;
        }
        ans[i] = sum + '0';
    }
    int i = 0;
    while ( ans[i++] == '0' && i < len );
    ans.erase(0, --i);
    return ans;

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

string highDiv(string a, string b)
{
    int lena = a.size();
    int lenb = b.size();
    if ( lenb > lena || (lena == lenb && a < b) ) {
        return "0";
    }
    ll ans = 0;
    ll res = 0;
    int i;
    string temp = highSub(a.substr(0, lenb), b);
    ans++;
    for ( i = lenb - 1; i < lena; i++ ) {
        // ans *= 10;
        while ( temp > b ) {
            ans++;
            temp = highSub(temp, b);
        }
        while ( temp < b && i < lena - 1 ) {
            temp += a[++i];
            ans *= 10;
        }

    }
    return to_string(ans);

}

inline __int128_t read()
{
    __int128_t x = 0, f = 1;
    char ch = getchar();
    while ( ch < '0' || ch>'9' ) {
        if ( ch == '-' ) { f = -1; }
        ch = getchar();
    }
    while ( ch >= '0' && ch <= '9' ) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}


inline void write(__int128_t x)
{
    if ( x < 0 ) {
        putchar('-');
        x = -x;
    }
    if ( x > 9 ) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}




int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);

    string a = "123456789";
    string b = "2234567";
    cout << highDiv(a, b) << "\n";
    return 0;
}
