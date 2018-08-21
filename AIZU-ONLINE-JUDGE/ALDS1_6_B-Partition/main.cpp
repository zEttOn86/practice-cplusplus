#include<cstdio>
int A[100000];
int partition(int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j=p; j< r; j++){
        if(A[j] <= x){
            i++;
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    int t = A[i+1]; // 最後のrの部分を交換
    A[i+1] = A[r];
    A[r] = t;
    return i+1;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n;i++) scanf("%d", &A[i]);
    
    int q = partition(0, n-1);

    for(int i= 0; i<n; i++){
        if(i) printf(" ");
        if(i==q) printf("[");
        printf("%d", A[i]);
        if(i==q) printf("]");
    }
    printf("\n");
    
    return 0;

}