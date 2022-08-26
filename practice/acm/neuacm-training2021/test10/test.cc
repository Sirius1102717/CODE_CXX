#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define N 1001
#define MOD 16007
#define E 1e-6
#define LL long long
using namespace std;
int m;
int degIn[N], degOut[N];
int father[N];
int Find(int x)
{
    if (father[x] == -1)
        return x;
    return father[x] = Find(father[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
        father[x] = y;
}
int main()
{

    int t;
    scanf("%d", &t);
    while (t--) {
        memset(degIn, 0, sizeof(degIn));
        memset(degOut, 0, sizeof(degOut));
        memset(father, -1, sizeof(father));

        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            char str[2000];
            scanf("%s", str);

            int len = strlen(str);
            int x = str[0] - 'a';
            int y = str[len - 1] - 'a';

            degIn[x]++;
            degOut[y]++;
            Union(x, y);
        }

        int cnt = 0;  //统计连通分量
        for (int i = 0; i < 26; i++)
            if ((degIn[i] || degOut[i]) && (Find(i) == i))
                cnt++;
        if (cnt > 1)
            printf("The door cannot be opened.\n");
        else {
            //出度不等于入度的三种情况
            int situation1 = 0;
            int situation2 = 0;
            int flag = 1;

            for (int i = 0; i < 26; i++) {
                if (degIn[i] == degOut[i])
                    continue;
                else if (abs(degIn[i] - degOut[i]) == 1)
                    situation1++;
                else
                    flag = 0;
            }
            if ((situation1 == 1) || (situation1 == 0) && flag)
                printf("Ordering is possible.\n");
            else
                printf("The door cannot be opened.\n");
        }
    }
    return 0;
}