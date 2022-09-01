#include<iostream>
#include<stack>
#include<deque>
#include<cstring>
using namespace std;
#define ll  long long
const double EPS = 1e-8;
const ll MAXN = 1e18;


void cal(char c, stack<double> &nums)
{
    double r = nums.top();
    nums.pop();
    double l = nums.top();
    nums.pop();
    if ( c == '+' ) {
        nums.push(l + r);
    } else if ( c == '-' ) {
        nums.push(l - r);
    } else if ( c == '*' ) {
        nums.push(l * r);
    } else {
        nums.push(l / r);
    }
}



int getNum(string s, int &i, int n)
{
    string ans;

    while ( s[i] >= '0' && s[i] <= '9' && i < n ) {
        ans += s[i];
        i++;
    }
    i--;
    // i++;
    return stoi(ans);
}

int main(int argc, char *argv[])
{
    string s;
    while ( getline(cin, s), s != "0" ) {
        int len = s.size();
        stack<char> signal;
        stack<double> nums;
        for ( int i = 0; i < len; i += 2 ) {
            char c = s[i];
            if ( c == '+' || c == '-' ) {
                if ( signal.empty() ) {
                    signal.push(c);
                } else {
                    while ( !signal.empty() ) {
                        cal(signal.top(), nums);
                        signal.pop();
                    }
                    signal.push(c);
                }
            } else if ( c == '*' || c == '/' ) {
                i += 2;
                int r = getNum(s, i, len);
                nums.push(r);
                cal(c, nums);
            } else {
                nums.push(getNum(s, i, len));
            }
        }
        while ( !signal.empty() ) {
            cal(signal.top(), nums);
            signal.pop();
        }

        printf("%.2lf\n", nums.top());
    }

    return 0;
}
