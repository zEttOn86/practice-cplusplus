#include<iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

int prim(){
    int u, minv;
    int d[MAX], p[MAX], color[MAX]; 
    // Tに属する頂点とV-Tに属する頂点をつなぐ辺の中で、重みが最小の辺の重みを記録
    // MSTにおける頂点vの親を記録
    // 訪問状態を記録

    for(int i=0; i<n; i++){ // 全ての頂点に関して、colorをwhite、dをinftyに初期化
        d[i] = INFTY;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while(1){
        minv = INFTY;
        u = -1;
        for(int i=0; i<n; i++){ // 最小の辺を探索
            if(minv > d[i] && color[i] != BLACK){
                u=i;
                minv = d[i];
            }
        }
        if(u==-1) break;
        color[u] = BLACK;
        for(int v=0; v<n; v++){
            if(color[v] != BLACK && M[u][v] != INFTY){ // 未訪問かつuからvに辺があるとき
                if(d[v] > M[u][v]){
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    int sum =0;
    for(int i=0; i<n; i++){
        if(p[i] != -1) sum += M[i][p[i]];
    }

    return sum;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            int e;
            cin >> e;
            M[i][j] = (e==-1) ? INFTY : e;

        }
    }

    cout << prim() << endl;

    return 0;
}
