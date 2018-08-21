#include<cstdio>
void insertionSort(int A[], int n){
    for(int i=1; i<n;i++){
        int v = A[i];
        int j = i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=v;
    }
    for(int i=0; i<n;i++){
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int main(){
    int A[3];
    for(int i=0; i<3;i++) scanf("%d", &A[i]);
    insertionSort(A, 3);
    return 0;
}