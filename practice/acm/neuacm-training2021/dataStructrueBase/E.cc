#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;



/**
 * @brief 若heightStack为空或者当前高度大于heightStack栈顶，则当前高度和当前下标分别入站。所以heightStack记录了一个连续递增的序列。

若当前高度小于heightStack栈顶，heightStack和indexStack出栈，直到当前高度大于等于heightStack栈顶。
出栈时，同时计算区间所形成的最大面积。注意计算完之后，当前值入栈的时候，其对应的下标应该为最后一个从indexStack出栈的下标。
比如height[2]入栈时，其对应下标入栈应该为1，而不是其本身的下标2。如果将其本身下标2入栈，则计算绿色区域的最大面积时，会忽略掉红色区域。


栈内存储的是高度递增的下标。对于每一个直方图高度，分两种情况。1：当栈空或者当前高度大于栈顶下标所指示的高度时，当前下标入栈。否则，2：当前栈顶出栈

 *
 * @param argc
 * @param argv
 * @return int
 */


ll h[10000] = { 0 };
int main(int argc, char *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    while ( cin >> n, n ) {
        stack<int> index;
        bool flag = false;
        ll area = 0;
        for ( int i = 0; i < n; i++ ) {
            cin >> h[i];
            if ( index.empty() || h[i] >= h[index.top()] ) {
                // s.push(h);
                index.push(i);
            } else {
                int start = index.top();
                index.pop();
                ll width = index.empty() ? n : n - index.top() - 1;
                area = max(area, h[start] * width);
            }
        }
        while ( !index.empty() ) {
            area = max(area, (h[index.top()] * (n - index.top())));
            index.pop();
        }
        cout << area << "\n";
    }



    return 0;
}
