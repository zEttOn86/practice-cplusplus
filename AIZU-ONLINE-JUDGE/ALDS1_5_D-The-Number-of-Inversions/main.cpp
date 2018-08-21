#include<cstdio>
#include<cstdlib>
#define MAX 200000
#define SENTINEL 2000000000
typedef long long llong;

int L[MAX/2+2], R[MAX/2+2];

llong merge(int A[], int n, int left, int mid, int right){
    llong cnt = 0;
    int n1 = mid-left;
    int n2 = right -mid;
    for(int i=0; i<n1; i++) L[i] = A[left+i];
    for(int i=0; i<n2; i++) R[i] = A[mid+i];
    L[n1] = R[n2] = SENTINEL;

    int i=0, j=0;
    for(int k=left; k<right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }
        else{
            A[k] = R[j++];
            cnt += n1 -i; // = mid + j - k - 1
        }
    }
    return cnt;
    
}

llong mergeSort(int A[], int n, int left, int right){
    if(right-left>1){
        int mid = (left+right)/2;
        llong v1 = mergeSort(A, n, left, mid);
        llong v2 = mergeSort(A, n, mid, right);
        llong v3 = merge(A, n, left, mid, right);
        return v1 + v2 + v3;
    }
    else return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(sizeof(int)*MAX);

    for(int i=0; i<n; i++) scanf("%d", &A[i]);

    llong ans = mergeSort(A, n, 0, n);

    printf("%ld\n", ans);


    return 0;
}