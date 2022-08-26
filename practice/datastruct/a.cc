#include <cstdio>
#include <iostream>
const int N = 1e3 + 5;
const int MAX = 0x3f3f3f3f;
using namespace std;
double p[N];
//存储第j虚拟键的概率(j=0…n)
double q[N];
//存储包含关键字ki….kj的最优子树的搜索代价
double c[N][N];
//存储包含关键字ki….kj和虚拟键的最优子树的概率和
double w[N][N];
//存储存储包含关键字ki….kj的最优子树的根
int root[N][N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    //p[j]存储第j关键字的概率(j=1…n)
    int m;
    int n;
    cin >> n;
    double sum = 0;
    int i, j, l;
    for(i = 1; i <= n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    for(i = 0; i <= n; i++) {
        cin >> q[i];
        sum += q[i];
    }
    for(i = 1; i <= n + 1; i++) {
        c[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    for(l = 1; l <= n; l++) {
        for(i = 1; i <= n - l + 1; i++) {
            j = l + i - 1;
            c[i][j] = MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            int r;
            for(r = i; r <= j; r++) {
                double k = c[i][r - 1] + w[i][j] + c[r + 1][j];
                if(k < c[i][j]) {
                    c[i][j] = k;
                    root[i][j] = k;
                }
            }
        }
    }
    printf("%.8f", c[1][n]);
    return 0;
}