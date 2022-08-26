#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int maxx = 105;
int map[maxx][maxx];  ///记录两者之间的关系
int coun[maxx];       ///记录入度
int n, m;
int find()
{
    int ans;
    for (int k = 0; k < n; k++) {
        ans = n;  ///每一轮都查看是否具有入度为0的点
        for (int i = 0; i < n; i++) {
            if (coun[i] == 0) {
                coun[i]--;
                ans = i;
                break;
            }
        }
        if (ans == n)  ///如果不存在入度为0 的点则有环
            return 0;
        for (int j = 0; j < n; j++)
            if (map[ans][j])
                coun[j]--;  ///将与入度为0 的点的其他点入度均减一
    }
    return 1;
}

int main()
{
    while (~scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0)
            break;
        fill(map, map + maxx, 0);
        memset(coun, 0, sizeof(coun));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (!map[u][v])  ///有可能存在重复的关系去除
            {
                map[u][v] = 1;
                coun[v]++;  ///入度加一
            }
        }
        int flag = find();
        if (flag)  /// 如果可以进行拓扑排序则表示无环
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}