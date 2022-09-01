#include <cstdio>
#include <cstring>
int vis[1000000];
int main()
{
    int str[47];
    
    int a, b, c, s;
    while ( scanf("%d", &a) ) {
        if ( a == 0 )
            break;
        scanf("%d%d%d", &b, &c, &s);
        memset(vis, 0, sizeof(vis));
        int tt = s;
        int l = 0;
        while ( tt ) {
            str[l++] = tt % 2;
            tt /= 2;
        }
        for ( int i = l; l < 16; l++ ) {
            str[i++] = 0;
        }
        /*for(int i = 0; i < 16; i++)
        {
            printf("%d ",str[i]);
        }*/
        tt = s;
        while ( !vis[tt] ) {
            l = 0;
            vis[tt] = 1;
            int tm = tt;
            while ( tm ) {
                if ( str[l] != tm % 2 ) {
                    str[l] = 3;
                }
                tm /= 2;
                l++;
            }
            tt = (((a * tt) % c) + (b % c)) % c;
        }
        for ( int i = 15; i >= 0; i-- ) {
            if ( str[i] != 3 )
                printf("%d", str[i]);
            else
                printf("?");
        }
        printf("\n");
    }
    return 0;
}