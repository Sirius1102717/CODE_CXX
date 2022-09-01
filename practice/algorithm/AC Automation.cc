#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}


struct Node
{
    int sum;
    Node *next[256];
    Node *fail;
    bool isWord;

    Node()
    {
        sum = 0;
        fail = nullptr;
        isWord = false;
        for ( int i = 0; i < 256; i++ ) {
            next[i] = nullptr;
        }
    }
}*Queue[N];

Node *root;
int head, tail;

void build(string s)
{
    Node *cur = root;
    int len = s.size();
    for ( int i = 0; i < len; i++ ) {
        char c = s[i];
        if ( !cur->next[c] ) {
            cur->next[c] = new Node();
        }
        cur = cur->next[c];
        cur->sum++;
    }
    cur->isWord = 1;

}

int query(string s, Node *root)
{
    int ans = 0;
    Node *cur = root;
    int len = s.size();
    for ( int i = 0; i < len; i++ ) {
        int index = s[i];
        while ( !cur->next[index] && cur != root ) {
            cur = cur->fail;
        }
        cur = cur->next[index];
        if ( !cur ) {
            cur = root;
        }
    }
    ans = cur->sum;
    return ans;
}

void Build_AC_automation(Node *root)
{

    // queue<Node *> q;
    // q.push(root);
    // while ( !q.empty() ) {
    //     Node *tmp = q.front();
    //     Node *p;
    //     for ( int i = 0; i < 256; i++ ) {
    //         if ( tmp == root ) {
    //             tmp->next[i]->fail = root;
    //         } else {
    //             p = tmp->fail;
    //             while ( p ) {
    //                 if ( p->next[i] ) {
    //                     tmp->next[i]->fail = p->next[i];
    //                     break;
    //                 }
    //                 p = p->fail;
    //             }
    //             if ( !p ) {
    //                 tmp->next[i]->fail = root;
    //             }
    //             q.push(tmp->next[i]);
    //         }
    //     }
    // }
    head = 0, tail = 0;//队列头、尾指针 
    Queue[head++] = root;//先将root入队 
    while ( head != tail ) {
        Node *p = nullptr;
        Node *temp = Queue[tail++];//弹出队头结点 
        for ( int i = 0; i < 256; i++ ) {
            if ( temp->next[i] )//找到实际存在的字符结点 
            { //temp->next[i] 为该结点，temp为其父结点 
                if ( temp == root )//若是第一层中的字符结点，则把该结点的失败指针指向root 
                    temp->next[i]->fail = root;
                else {
                    // 依次回溯该节点的父节点的失败指针直到某节点的next[i]与该节点相同，
                    // 则把该节点的失败指针指向该next[i]节点； 
                    // 若回溯到 root 都没有找到，则该节点的失败指针指向 root
                    p = temp->fail;//将该结点的父结点的失败指针给p 
                    while ( p ) {
                        if ( p->next[i] ) {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    // 让该结点的失败指针也指向root 
                    if ( !p )
                        temp->next[i]->fail = root;
                }
                Queue[head++] = temp->next[i];//每处理一个结点，都让该结点的所有孩子依次入队 
            }
        }
    }

}

void init(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while ( !q.empty() ) {
        Node *pre;
        Node *cur = q.front();
        for ( int i = 0; i < 256; i++ ) {
            if ( cur == root ) {
                cur->next[i]->fail = root;
            } else {
                pre = cur->fail;
                while ( pre ) {
                    if ( pre->next[i] ) {
                        cur->next[i]->fail = pre->next[i];
                        break;
                    }
                    pre = pre->fail;
                }
                if ( !pre ) {
                    cur->next[i]->fail = root;
                }
            }
            q.push(cur->next[i]);
        }
    }
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
