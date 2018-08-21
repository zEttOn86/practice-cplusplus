#include<cstdio>
int n, A[50];

// 入力値のMから選んだ要素を引いていく再帰関数
/* i番目以降の要素を使って、mを作れる場合trueを返す関数 */
int solve(int i, int m){
    if(m==0) return 1;
    if(i>=n) return 0;
    int res =solve(i+1, m) || solve(i+1, m-A[i]);
    return res;
}
int main(){
    int q, temp;

    scanf("%d", &n);
    for(int i=0; i<n;i++) scanf("%d", &A[i]);
    scanf("%d", &q);
    for(int i=0; i<q; i++){
        scanf("%d", &temp);
        if(solve(0, temp)) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}