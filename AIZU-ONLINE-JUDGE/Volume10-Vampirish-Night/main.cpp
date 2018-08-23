#include<cstdio>
#define MAX 100

int main(int argc, char const *argv[])
{
    int N, K;
    int S[MAX], sum[MAX];
    int temp;
    while(1){
        bool flag = true;
        scanf("%d %d", &N, &K);
        if(N==0 && K==0) break;

        for(int i=0; i<K; i++){
            sum[i] = 0;
            scanf("%d", &S[i]);
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<K; j++){
                scanf("%d", &temp);
                sum[j] += temp;
            }
        }

        for(int i=0; i<K; i++){
            if(S[i] < sum[i]) { flag = false; break;}
        }

        if(flag) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
