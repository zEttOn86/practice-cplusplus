#include<cstdio>
#define MAX 100000
#define SENTINEL 2000000000
struct Card{
    char suit;
    int value;
};
int n;
Card X[MAX], Y[MAX];
Card L[MAX/2+2], R[MAX/2+2];

void merge(Card A[], int left, int mid, int right){
    int n1 = mid -left;
    int n2 = right -mid;
    for(int i = 0; i<n1; i++) L[i] = A[left+i];
    for(int i=0; i< n2; i++) R[i] = A[mid+i];
    L[n1].value = R[n2].value = SENTINEL;
    
    int i=0, j=0;
    for(int k=left; k<right; k++){
        if(L[i].value <= R[j].value){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card A[], int left, int right){
    if(right-left>1){
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int partition(Card A[], int p, int r){
    Card x = A[r];
    int i = p-1;
    for(int j=p; j<r;j++){
        if(A[j].value <= x.value){
            i++;
            Card temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    Card temp = A[i+1];
    A[i+1] = A[r];
    A[r] =temp;
    return i +1;
}
void quickSort(Card A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){
    char S[10]; // 一時保存用
    int v;
    int stable=1;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s %d", S, &v);
        X[i].suit = Y[i].suit = S[0];
        X[i].value = Y[i].value = v;
    }

    mergeSort(X, 0, n); // マージは要素の1個外から
    
    quickSort(Y, 0, n-1);

    for(int i=0; i<n;i++){
        // マージソートとクイックソートの結果を比べる
        if(X[i].suit != Y[i].suit) stable = 0;
    }

    if(stable==1) printf("Stable\n");
    else printf("Not stable\n");

    for(int i=0; i<n; i++){
        printf("%c %d\n", Y[i].suit, Y[i].value);
    }

    return 0;
}