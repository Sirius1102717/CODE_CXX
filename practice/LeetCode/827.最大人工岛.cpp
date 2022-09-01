#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛

 */
// @lc code=start
const int N = 55;
class Solution
{
public:
    int n, id, sz, fa[N][N], d[4][2] = { { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 } }, vis[N][N];
    void dfs(int x, int y, vector<vector<int>>& g)
    {
        vis[x][y] = 1;
        fa[x][y] = id;
        sz++;
        for (int k = 0; k < 4; k++) {
            int xx = x + d[k][0], yy = y + d[k][1];
            if (xx < 0 || xx >= n || yy < 0 || yy >= n || vis[xx][yy] || g[xx][yy] == 0)
                continue;
            dfs(xx, yy, g);
        }
    }
    int largestIsland(vector<vector<int>>& g)
    {
        n = g.size(), id = 0;
        int ans = 0, cnt[N * N];
        memset(cnt, 0, sizeof cnt), memset(vis, 0, sizeof vis);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] && !vis[i][j]) {
                    sz = 0;
                    dfs(i, j, g);
                    cnt[id++] = sz;
                    ans = max(ans, sz);
                }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == 0) {
                    // 如果周围有1，就合并(并用map标记)，周围的1可能不是一个连通块的，所以都需要标记
                    unordered_map<int, int> can_merge;
                    for (int k = 0; k < 4; k++) {
                        int ii = i + d[k][0], jj = j + d[k][1];
                        if (ii < 0 || ii >= n || jj < 0 || jj >= n || !g[ii][jj])
                            continue;
                        if (!can_merge[fa[ii][jj]])
                            can_merge[fa[ii][jj]] = true;
                    }
                    int c = 1;
                    for (auto& [fa, flag] : can_merge)
                        if (flag)
                            c += cnt[fa];
                    ans = max(ans, c);
                }
        return ans;
    }
};
// @lc code=end
