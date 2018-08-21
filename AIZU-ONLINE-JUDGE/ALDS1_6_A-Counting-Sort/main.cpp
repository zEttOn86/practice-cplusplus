#include<cstdio>
#include<cstdlib>

#define MAX 2000001
#define VMAX 10000

int main(){
    int C[VMAX+1]; // Aの中に要素番号以下の数がいくつかあるかを示す配列
    int n;
    
    scanf("%d", &n);
    
    unsigned short *A = (unsigned short *)malloc(sizeof(unsigned short) * n+1);
    unsigned short *B = (unsigned short *)malloc(sizeof(unsigned short) * n+1);

    for(int i= 0; i< VMAX+1; i++) C[i] = 0;

    for(int i = 0; i<n; i++) {
        scanf("%hu", &A[i+1]);
        C[A[i+1]]++;
    }

    for(int i= 1; i<= VMAX; i++) C[i] = C[i] + C[i-1];
    
    for(int i=1; i<=n; i++){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for(int i=1; i<=n; i++){
        if(i>1) printf(" ");
        printf("%u", B[i]);
    }
    printf("\n");

    return 0;
}