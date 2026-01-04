
#include <stdio.h>

#define N 6

int g[N][N] = {
    {0,1,0,0,0,0},
    {1,0,1,0,0,0},
    {0,1,0,0,0,0},
    {0,0,0,0,1,0},
    {0,0,0,1,0,1},
    {0,0,0,0,1,0}
};

int visited[N];

void dfs(int v){
    visited[v] = 1;
    printf("%d ", v);
    for(int i=0;i<N;i++){
        if(g[v][i] && !visited[i]) dfs(i);
    }
}


void findComponents(void){
    int comp = 1;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            printf("Kume %d: ", comp++);
            dfs(i);
            printf("\n");
        }
    }
}

int main(void){
    for(int i=0;i<N;i++) visited[i]=0;
    findComponents();
    return 0;
}
