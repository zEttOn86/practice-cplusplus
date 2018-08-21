#include<cstdio>
#define MAX 100000
typedef long long llong;
int n,k;
llong T[MAX];
// 最大積載量 P の k台のトラックで何個の荷物を積めるか
/*トラックの数ループさせて、最大積載量Ｐになるまで、荷物数を計算*/
int check(llong P){
    int i =0; // トラックに積載する荷物の数
    for(int j=0; j<k; j++){ // トラックの数
        llong s = 0;
        while(s+T[i] <= P){
            s += T[i];
            i++;
            if(i==n) return n;
        }
    }
    return i;
}

int solve(){
    llong left = 0;
    llong right = 100000 * 10000; // 荷物の個数×1個あたりの最大重量
    while(right - left>1){
        llong mid = (left+right)/2;
        int v = check(mid); // mid==Pを決めて何個積めるかチェック
        if(v>=n) right=mid;
        else left = mid;    
    }
    return right;
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n; i++) scanf("%d", &T[i]);
    llong ans =solve();
    printf("%lld\n", ans);
    return 0;
}