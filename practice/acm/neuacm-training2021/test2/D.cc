#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;



string highAdd(string a, string b)
{
    int lenb = b.size();
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


vector<string> vs;
void getAns()
{
    if ( vs.empty() ) {
        vs.emplace_back("3");
        vs.emplace_back("20");
    }
    for ( int i = 2; i < 251; i++ ) {
        string mul = highMul(vs[i - 1], "6");
        string sub = highSub(mul, vs[i - 2]);
        string add = highAdd(sub, "2");

        vs.emplace_back(add);
    }

}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    getAns();
 
    cin >> t;

    while ( t-- ) {
        string in;
        cin >> in;
        int inS = in.size();
        for ( int i = 0; i < 251; i++ ) {
            int vsS = vs[i].size();
            int temp = vs[i].compare(in);
            if ( vsS > inS || (temp >= 0 && vsS == inS) ) {
                cout << vs[i] << "\n";
                break;
            }
        }
    }

    return 0;
}
