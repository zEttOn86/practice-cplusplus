#include<cstdio>
int search(int A[], int n, int key){
    int i=0;
    A[n] = key;
    while(A[i]!=key) i++;
    return i!=n;
}

int main()
{
    int n, S[10000+1], q, key, sum=0;

    scanf("%d", &n);
    for(int i =0; i<n; i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for(int i=0; i< q; i++){
        scanf("%d", &key);
        if(search(S, n, key)) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
