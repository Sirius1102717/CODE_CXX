#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define INFINITY 65535
#define MAX_SIZE 60
#define MAX_COST 0x3f3f3f3f
int distance[MAX_SIZE][MAX_SIZE];  //距离的权值
int v_num = 0;                     //点的数量
int e_num = 0;                     //边的数量
//顶点链表，用于接下来转化为数字
typedef struct List {
    char place[MAX_SIZE];
    struct List* pnext;
} List;
//边结构，因为文件给的一行是边的属性
typedef struct Edge {
    int from;       //起点
    int to;         //终点
    int cost;       //路费
    int dis;        //距离
} Edges[MAX_SIZE];  //边的数组
//顶点列表初始化
List* init_List() {
    List* head;
    head = (List*)malloc(sizeof(List));
    // head->place=NULL;
    head->pnext = NULL;
    return head;
}
//添加节点
void insertBack(List* head, char* name) {
    List* newnode = (List*)malloc(sizeof(List));
    newnode->pnext = NULL;
    strcpy(newnode->place, name);
    List* p = head;

    while(p->pnext != NULL) {
        p = p->pnext;
    }
    p->pnext = newnode;
    p = newnode;
    v_num++;
}
//判断是否顶点重复
int isUsed(List* head, char* name) {
    List* p = head->pnext;
    while(p) {
        if(!strcmp(p->place, name)) {
            return 1;
        }
        p = p->pnext;
    }
    return 0;
}
//增加顶点
void v_Insert(List* l, char* name) {
    bool flag = isUsed(l, name);
    if(!flag) {
        insertBack(l, name);
    }
}
//遍历链表
void travelLink(List* head) {
    List* p = head->pnext;
    while(p != NULL) {
        printf("%s\t", p->place);
        p = p->pnext;
    }
    putchar('\n');
}
//顶点转成数字
int getIndex(List* l, char* name) {
    int i = 1;
    List* tmp = l->pnext;
    while(tmp) {
        if(!strcmp(tmp->place, name)) {
            return i;
        }
        tmp = tmp->pnext;
        i++;
    }
    return -1;
}

// void prim(int weight[][MAX_SIZE],int n){
    // int lowcost[MAX_SIZE];
    // int start[MAX_SIZE];
    // int min,minid,sum=0;
    // for(int i=2;i<=n;i++){
        // lowcost[i]=weight[1][i];
        // start[i]=1;
    // }
    // start[1]=0;
    // for(int i=2;i<=n;i++){
        // min=MAX_COST;
        // minid=0;
        // for(int j=2;j<=n;j++){
            // if(lowcost[j]<min&&lowcost[j]>0){
                // min=lowcost[j];
                // minid=j;
            // }
        // }
        // printf("V%d-V%d=%d\n",start[minid],minid,min);
        // sum+=min;
        // lowcost[minid]=0;
        // for(int j=2;j<=n;j++){
            // if(weight[minid][j]<lowcost[j]){
                // lowcost[j]=weight[minid][j];
                // start[j]=minid;
            // }
        // }
    // }
    // printf("最短距离之和：%d",sum);
// }

void prim(int graph[][MAX_SIZE], int n) {
    int lowcost[MAX_SIZE];
    int mst[MAX_SIZE];
    int i, j, min, minid, sum = 0;
    for(i = 2; i <= n; i++) {
        lowcost[i] = graph[1][i];  // lowcost存放顶点1可达点的路径长度
        mst[i] = 1;                //初始化以1位起始点
    }
    mst[1] = 0;
    for(i = 2; i <= n; i++) {
        min = MAX_COST;
        minid = 0;
        for(j = 2; j <= n; j++) {
            if(lowcost[j] < min && lowcost[j] > 0) {
                min = lowcost[j];  //找出权值最短的路径长度
                minid = j;         //找出最小的ID
            }
        }
        printf("V%d-V%d=%d\n", mst[minid], minid, min);
        sum += min;          //求和
        lowcost[minid] = 0;  //该处最短路径置为0
        for(j = 2; j <= n; j++) {
            if(graph[minid][j] < lowcost[j])  //对这一点直达的顶点进行路径更新
            {
                lowcost[j] = graph[minid][j];
                mst[j] = minid;
            }
        }
    }
    printf("最小权值之和=%d\n", sum);
}

int main() {
    freopen("/home/freaver/CODE_C/practice/homework/ds/services.txt", "r", stdin);
    List* head = init_List();
    Edges e;
    v_num = e_num = 0;
    char from[MAX_SIZE], to[MAX_SIZE];
    int dis, cost;
    memset(distance, MAX_COST, sizeof distance);
    while(~scanf("%s%s%d%d", from, to, &cost, &dis)) {
        // printf("%s %s %d %d\n",from,to,cost,dis);
        v_Insert(head, from);
        v_Insert(head, to);
        e[e_num].from = getIndex(head, from);
        e[e_num].to = getIndex(head, to);
        distance[e[e_num].from][e[e_num].to] = dis;
        e[e_num].cost = cost;
        e[e_num++].dis = dis;
    }
    

    for(int i = 0; i < v_num; i++) {
        for(int j = 0; j < v_num; j++) {
            printf("%04d ", distance[i][j]);
            if(j == v_num - 1) {
                printf("\n");
            }
        }
    }
    prim(distance, v_num);
    return 0;
}