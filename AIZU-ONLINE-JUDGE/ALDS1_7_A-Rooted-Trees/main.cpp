#include<cstdio>
#define MAX 100005
#define NIL -1

struct Node{int p, l, r;};
Node T[MAX];
int n, D[MAX];


void print(int u){
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].p);
    printf("depth = %d, ", D[u]);

    if(T[u].p == NIL) printf("root, ");
    else if(T[u].l == NIL) printf("leaf, ");
    else printf("internal node, ");

    printf("[");

    for(int i=0, c = T[u].l; c!= NIL; i++, c =T[c].r){
        if(i) printf(", ");
        printf("%d", c);
    }

    printf("]\n");
}


// 再帰的に深さを求める
int rec(int u, int p){
    D[u] = p;
    if(T[u].r != NIL) rec(T[u].r, p); // 右の兄弟に同じ深さを設定
    if(T[u].l != NIL) rec(T[u].l, p+1); // 最も左の子に自分の深さ+1を設定
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;
    
    int v, d, l, c; // 接点の番号, 次数, , j番目の子の接点番号
    for(int i=0; i<n; i++){
        scanf("%d %d", &v, &d);
        for(int j = 0; j<d; j++){ // 子の接点番号ループ
            scanf("%d", &c);
            if(j==0) T[v].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }
    int r;
    for(int i=0; i<n;i++){
        if(T[i].p ==NIL) r=i;
    }
    rec(r,0);

    for(int i=0; i<n;i++) print(i);
    
    return 0;
}
