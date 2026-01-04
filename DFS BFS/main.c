
#include <stdio.h>

#define N 5

int adj[N][N] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,1,1},
    {0,1,1,0,0},
    {0,0,1,0,0}
};

void DFS_recursive(int v, int vis[]){
    vis[v]=1;
    printf("%d ", v);
    for(int i=0;i<N;i++)
        if(adj[v][i] && !vis[i]) DFS_recursive(i, vis);
}

void DFS_stack(int start){
    int st[100], top=-1;
    int vis[N]={0};

    st[++top]=start;
    while(top!=-1){
        int v=st[top--];
        if(vis[v]) continue;
        vis[v]=1;
        printf("%d ", v);


        for(int i=N-1;i>=0;i--)
            if(adj[v][i] && !vis[i]) st[++top]=i;
    }
}

void BFS_queue(int start){
    int q[100], f=0, r=0;
    int vis[N]={0};

    q[r++]=start; vis[start]=1;
    while(f<r){
        int v=q[f++];
        printf("%d ", v);
        for(int i=0;i<N;i++){
            if(adj[v][i] && !vis[i]){
                vis[i]=1;
                q[r++]=i;
            }
        }
    }
}

int main(void){
    int vis[N]={0};

    printf("DFS (Recursive): ");
    DFS_recursive(0, vis);
    printf("\n");

    printf("DFS (Stack):     ");
    DFS_stack(0);
    printf("\n");

    printf("BFS (Queue):     ");
    BFS_queue(0);
    printf("\n");

    return 0;
}
