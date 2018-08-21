#include<cstdio>

int partition(int A[], int p, int r){
    int x = A[r];
    int i=p-1;
    for(int j=p; j<r; j++){
        if(A[j] <= x){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i+1];
    A[i+1] =A[r];
    A[r] =temp;
    return i+1;
}

void quickSort(int A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(int argc, char const *argv[])
{
    int H[10];
    for(int i=0; i<10; i++) scanf("%d", &H[i]);

    quickSort(H, 0,10-1);
    for(int i=0; i<3; i++) printf("%d\n", H[9-i]);
    return 0;
}
