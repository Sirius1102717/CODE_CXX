#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int N = 1e5;


template <class T>
size_t getHash(T p)
{
    return hash<T>{}(p);
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}


int Next[N];

int KmpSearch(char *s, char *p)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while ( i < sLen && j < pLen ) {
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
        if ( j == -1 || s[i] == p[j] ) {
            i++;
            j++;
        } else {
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
            //next[j]即为j所对应的next值      
            j = Next[j];
        }
    }
    if ( j == pLen )
        return i - j;
    else
        return -1;
}


int kmp(string s, string p)
{
    int i, j;
    i = j = 0;
    int sLen = s.size();
    int pLen = p.size();
    while ( i < sLen && j < pLen ) {
        if ( j == -1 || s[i] == p[i] ) {
            i++;
            j++;
        } else {
            j = Next[j];
        }
        if ( j == pLen ) {
            return i - j;
        }
    }
    return -1;
}


//优化过后的next 数组求法
void GetNextval(char *p, int Next[])
{
    int pLen = strlen(p);
    Next[0] = -1;
    int k = -1;
    int j = 0;
    while ( j < pLen - 1 ) {
        //p[k]表示前缀，p[j]表示后缀  
        if ( k == -1 || p[j] == p[k] ) {
            ++j;
            ++k;
            //较之前next数组求法，改动在下面4行
            if ( p[j] != p[k] )
                Next[j] = k;   //之前只有这一行
            else
                //因为不能出现p[j] = p[ Next[j ]]，所以当出现时需要继续递归，k = Next[k] = next[Next[k]]
                Next[j] = Next[k];
        } else {
            k = Next[k];
        }
    }
}


void init(string p)
{
    int len = p.size();
    int j = 0, k = -1;
    Next[0] = -1;
    while ( j < len - 1 ) {
        if ( k == -1 || p[j] == p[k] ) {
            j++, k++;

            Next[j] = p[j] == p[k] ? k : Next[k];

            // if ( p[j] == p[k] ) {
            //     Next[j] = k;
            // } else {
            //     Next[j] = Next[k];
            // }
        } else {
            k = Next[k];
        }
    }
}