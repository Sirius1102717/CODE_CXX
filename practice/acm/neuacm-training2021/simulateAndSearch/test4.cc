#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

struct node
{
    int num[4], step;
}pre, last;
int book[11][11][11][11];

void bfs()
{
    int i;
    node now, next;
    queue<node> q;
    now = pre;
    now.step = 0;
    book[now.num[0]][now.num[1]][now.num[2]][now.num[3]] = 1;
    q.push(now);
    while ( !q.empty() ) {
        now = q.front();
        q.pop();
        if ( now.num[0] == last.num[0] && now.num[1] == last.num[1] && now.num[2] == last.num[2] && now.num[3] == last.num[3] ) {
            printf("%d\n", now.step);
            return;
        }
        //+1操作
        for ( i = 0; i < 4; i++ ) {
            next = now;	//每次都为next赋值为最初的值
            next.num[i]++;
            if ( next.num[i] == 10 )
                next.num[i] = 1;
            if ( !book[next.num[0]][next.num[1]][next.num[2]][next.num[3]] ) {
                book[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step++;
                q.push(next);
            }
        }
        //-1操作
        for ( i = 0; i < 4; i++ ) {
            next = now;
            next.num[i]--;
            if ( next.num[i] == 0 )
                next.num[i] = 9;
            if ( !book[next.num[0]][next.num[1]][next.num[2]][next.num[3]] ) {
                book[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step++;
                q.push(next);
            }
        }
        //换位操作
        for ( i = 0; i < 3; i++ ) {
            next = now;
            next.num[i] = now.num[i + 1];
            next.num[i + 1] = now.num[i];
            if ( !book[next.num[0]][next.num[1]][next.num[2]][next.num[3]] ) {
                book[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = 1;
                next.step++;
                q.push(next);
            }
        }
    }
}

int main()
{
    int i, t;
    char s1[10], s2[10];
    scanf("%d", &t);
    while ( t-- ) {
        scanf("%s%s", s1, s2);
        for ( i = 0; i < 4; i++ ) {
            pre.num[i] = s1[i] - '0';
            last.num[i] = s2[i] - '0';
        }
        memset(book, 0, sizeof(book));
        bfs();
    }
    return 0;
}
