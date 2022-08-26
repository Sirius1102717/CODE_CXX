#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Tire
{
    bool isw;    //是否是一个单词
    Tire *next[26];
    Tire()
    {
        isw = false;
        int i;
        for ( i = 0; i < 26; i++ )
            next[i] = NULL;
    }

};
Tire root;

void Insert(char word[])    //将word插入到字典树中，在最后标记这是一个单词
{
    Tire *p = &root;
    int i;
    for ( i = 0; word[i]; i++ ) {
        int t = word[i] - 'a';
        if ( p->next[t] == NULL )    //如果没有对应的节点
            p->next[t] = new Tire;
        p = p->next[t];

    }
    p->isw = true;    //标记到这为止是一个单词
}

bool isWord(char str[])    //判断这个字符串是否为一个单词
{
    Tire *p = &root;
    int i;
    for ( i = 0; str[i]; i++ ) {
        int t = str[i] - 'a';
        if ( p->next[t] == NULL )    //如果没有对应的节点
            return false;
        p = p->next[t];

    }      
    return p->isw;
}
char word[50010][101];    //字典

int main()
{
    int size = 1, i, j;    //字典大小

    while ( scanf("%s", word[size]) != EOF ) {    //读入字典
        //if(word[size][0]=='0') break;
        Insert(word[size++]);

    }
    size--;
    //检查每一个单词，判断这个单词是否为Hat's word
    for ( i = 1; i <= size; i++ ) {
        for ( j = 1; j < strlen(word[i]); j++ ) {
            char t[101], *p = word[i];
            strncpy(t, word[i], j);
            t[j] = '\0';
            p += j;
            if ( isWord(t) && isWord(p) ) {    //如果这两部分都是单词，说明是Hat's word
                printf("%s\n", word[i]);
                break;

            }

        }

    }
    return 0;
}