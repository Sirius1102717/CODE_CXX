#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int N = 1e6 + 1;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}



struct KMP
{
    int dp[N][256] = {0};
    string pat;

    KMP(string pat)
    {
        this->pat = pat;
        int M = pat.size();
        // dp[状态][字符] = 下个状态
        // base case
        dp[0][pat[0]] = 1;
        // 影子状态 X 初始为 0
        int X = 0;
        // 构建状态转移图（稍改的更紧凑了）
        for ( int j = 1; j < M; j++ ) {
            for ( int c = 0; c < 256; c++ ) {
                dp[j][c] = dp[X][c];
            }
            dp[j][pat[j]] = j + 1;
            // 更新影子状态
            X = dp[X][pat[j]];
        }
    }

    int search(string txt)
    {
        int M = pat.size();
        int N = txt.size();
        // pat 的初始态为 0
        int j = 0;
        for ( int i = 0; i < N; i++ ) {
            // 计算 pat 的下一个状态
            j = dp[j][txt[i]];
            // 到达终止态，返回结果
            if ( j == M ) {
                return i - M + 1;
            }
        }
        // 没到达终止态，匹配失败
        return -1;
    }
};