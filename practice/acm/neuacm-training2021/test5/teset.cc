#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma warning(disable:4996)
struct Node
{
    ll l, r;
    ll lazy = 0, sum = 0, mlz = 1;
}tree[500005];
ll input[500005];
int n, m;
void build(int k, int l, int r)
{
    tree[k].l = l, tree[k].r = r;
    if ( l == r ) 	{
        tree[k].sum = input[l]; return;
    }
    int mid = (l + r) >> 1;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    tree[k].sum = (tree[2 * k].sum + tree[2 * k + 1].sum);
}
ll query(int k, ll l, ll r)
{
    if ( tree[k].l == l && tree[k].r == r ) 	{
        return tree[k].sum;
    }
    //pushup(k);
    int mid = (tree[k].l + tree[k].r) >> 1;
    if ( mid >= r )return query(2 * k, l, r);
    if ( mid < l )return query(2 * k + 1, l, r);
    return (query(2 * k, l, mid) + query(2 * k + 1, mid + 1, r));
}
void Sqrt(ll k, ll l, ll r)
{
    if ( tree[k].sum == tree[k].r - tree[k].l + 1 )return;
    if ( tree[k].l == tree[k].r ) 	{
        tree[k].sum = (ll)sqrt(tree[k].sum);
        return;
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    if ( mid >= r )Sqrt(2 * k, l, r);
    else if ( mid < l )Sqrt(2 * k + 1, l, r);
    else Sqrt(2 * k, l, mid), Sqrt(2 * k + 1, mid + 1, r);
    tree[k].sum = (tree[2 * k].sum + tree[2 * k + 1].sum);
}
int main()
{
    int xxx = 1;
    while ( ~scanf("%d", &n) ) 	{
        for ( int i = 1; i <= n; i++ )scanf("%lld", &input[i]);
        scanf("%d", &m);
        printf("Case #%d:\n", xxx++);
        build(1, 1, n);
        while ( m-- ) 		{
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if ( b > c )swap(b, c);
            if ( a == 0 ) 			{
                Sqrt(1, b, c);
            } 			else 			{
                printf("%lld\n", query(1, b, c));
            }
        }
        printf("\n");
    }
}