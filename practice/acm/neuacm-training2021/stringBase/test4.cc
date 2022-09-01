#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int sum;//是否为该单词的最后一个结点 
    Node *fail;//失败指针 
    Node *next[26];//Trie中每个结点的各个节点 
}*queue[500005];//队列，方便用BFS构造失败指针 
char s[1000005];//主字符串 
char keyword[55];//需要查找的单词 
Node *root;//头结点 
void Init(Node *root)//每个结点的初始化 
{
    root->sum = 0;
    root->fail = NULL;
    for ( int i = 0; i < 26; i++ )
        root->next[i] = NULL;
}
void Build_trie(char *keyword)//构建Trie树 
{
    Node *cur, *q;
    int i, index;
    int len = strlen(keyword);
    for ( i = 0, cur = root; i < len; i++ ) 	{
        index = keyword[i] - 'a';
        if ( cur->next[index] == NULL ) 		{
            q = (struct Node *)malloc(sizeof(Node));
            Init(q);
            cur->next[index] = q;//结点链接 
        }
        cur = cur->next[index];//指针移动到下一个结点 
    }
    cur->sum++;//单词最后一个结点sum++，代表一个单词 

    // Node *cur = root;
    // int len = strlen(keyword);
    // for ( int i = 0; i < len; i++ ) {
    //     int index = keyword[i] - 'a';
    //     if ( !cur->next[index] ) {
    //         cur->next[index] = new Node;
    //     }
    //     cur = cur->next[index];
    //     // cur->sum++;
    // }
    // cur->sum++;
}
void Build_AC_automation(Node *root)
{
    int head = 0, tail = 0;//队列头、尾指针 
    queue[head++] = root;//先将root入队 
    while ( head != tail ) {
        Node *cur = NULL;
        Node *tmp = queue[tail++];//弹出队头结点 
        for ( int i = 0; i < 26; i++ ) {
            if ( tmp->next[i] != NULL )//找到实际存在的字符结点 
            { //tmp->next[i] 为该结点，temp为其父结点 
                if ( tmp == root )//若是第一层中的字符结点，则把该结点的失败指针指向root 
                    tmp->next[i]->fail = root;
                else {
                    //依次回溯该节点的父节点的失败指针直到某节点的next[i]与该节点相同，
                    //则把该节点的失败指针指向该next[i]节点； 
                    //若回溯到 root 都没有找到，则该节点的失败指针指向 root
                    cur = tmp->fail;//将该结点的父结点的失败指针给p 
                    while ( cur != NULL ) {
                        if ( cur->next[i] != NULL ) {
                            tmp->next[i]->fail = cur->next[i];
                            break;
                        }
                        cur = cur->fail;
                    }
                    //让该结点的失败指针也指向root 
                    if ( cur == NULL )
                        tmp->next[i]->fail = root;
                }
                queue[head++] = tmp->next[i];//每处理一个结点，都让该结点的所有孩子依次入队 
            }
        }
    }
}
int query(Node *root)
{ //i为主串指针，p为模式串指针 
    int count = 0;
    Node *cur = root;
    int len = strlen(s);
    for (int i = 0; i < len; i++ ) {
        int index = s[i] - 'a';
        //由失败指针回溯查找，判断s[i]是否存在于Trie树中 
        while ( cur->next[index] == NULL && cur != root ) {
            cur = cur->fail;
        }
        cur = cur->next[index];//找到后p指针指向该结点 
        if ( cur == NULL )//若指针返回为空，则没有找到与之匹配的字符 
            cur = root;
        Node *tmp = cur;//匹配该结点后，沿其失败指针回溯，判断其它结点是否匹配 
        while ( tmp != root )//匹配结束控制 
        {
            if ( tmp->sum >= 0 )//判断该结点是否被访问 
            {
                count += tmp->sum;//由于sum初始化为 0，所以只有sum>0时才统计了单词的个数 
                tmp->sum = -1;//标记已访问过 
            } else//结点已访问，退出循环 
                break;
            tmp = tmp->fail;//回溯 失败指针 继续寻找下一个满足条件的结点 
        }
    }
    return count;
}
int main()
{
    int T, n;
    scanf("%d", &T);
    while ( T-- ) {
        root = (struct Node *)malloc(sizeof(Node));
        Init(root);
        scanf("%d", &n);
        for ( int i = 0; i < n; i++ ) {
            scanf("\n%s", keyword);
            Build_trie(keyword);
        }
        Build_AC_automation(root);
        scanf("\n%s", s);
        printf("%d\n", query(root));
    }
    return 0;
}
