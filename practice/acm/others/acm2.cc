#include<bits/stdc++.h>
using namespace std;


stack<char> bracket;
int judge(char todo, char left, char right)
{
    if ( todo == left ) {
        if ( bracket.top() == right ) {
            cout << "No";
            return 0;
        } else {
            cout << "Yes";
            return 1;
        }
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s = nullptr;
    int len = s.length();
    if ( s.compare(nullptr) ) {
        cout << "No";

    }
    int toJughe = 0;
    for ( int i = 0; i < len; i++ ) {
        char c = s[i];
        if ( c == '{' || c == '<' || c == '[' || c == '(' ) {
            bracket.push(c);
        }
        if ( judge(c, '{', '}') || judge(c, '<', '>') || judge(c, '[', ']') ||
            judge(c, '(', ')') ) {
            return;
        }
    }
    return 0;
}
