#include<cstdio>

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j=p; j<r; j++){
        if(A[j]<= x){
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[r];
    A[r] = A[i+1];
    A[i+1] = temp;
    return i+1;
}

void quickSort(int A[], int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){
    int l[3];
    int cnt[4] ={0};

    while(1){
        for(int i=0; i<3; i++) scanf("%d", &l[i]);
        quickSort(l, 0, 2);
        double a = (double)l[0], b=(double)l[1], c=(double)l[2];

        if(!(a+b>c && b+c>a && c+a>b)) break;
        
        cnt[0]++;
        double cosine = (b*b+a*a-c*c)/(2*b*c);
        if(cosine == 0) cnt[1]++;
        else if(cosine >0) cnt[2]++;
        else cnt[3]++;
    }

    for(int i=0; i<4; i++){
        if(i) printf(" ");
        printf("%d", cnt[i]);
    }
    printf("\n");

    return 0;
}