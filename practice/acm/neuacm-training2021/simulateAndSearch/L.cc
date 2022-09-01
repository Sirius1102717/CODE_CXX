#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int n, a[21], visited[21];
bool isPrime[40] = { 0 };

void EulerPrime()
{
    isPrime[1] = 1;
    for ( int i = 2; i <= 39; i++ ) {
        if ( !isPrime[i] ) {
            for ( int j = 2; j * i <= 39; j++ ) {
                isPrime[i * j] = 1;
            }
        }
    }
}



void dfs(int step)
{
    if ( step == n + 1 && !isPrime[a[1] + a[n]] ) {
        printf("1");
        for ( int i = 2; i <= n; i++ ) {
            printf(" %d", a[i]);
        }
        printf("\n");
        return;
    }
    for ( int i = 2; i <= n; i++ ) {
        if ( !visited[i] && !isPrime[i + a[step - 1]] ) {
            a[step] = i;
            visited[i] = 1;
            dfs(step + 1);
            visited[i] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    EulerPrime();
    int res = 0;
    a[1] = 1;
    while ( ~scanf("%d", &n) ) {
        printf("Case %d:\n", ++res);
        memset(visited, 0, sizeof visited);
        dfs(2);
        printf("\n");
    }

    return 0;
}
