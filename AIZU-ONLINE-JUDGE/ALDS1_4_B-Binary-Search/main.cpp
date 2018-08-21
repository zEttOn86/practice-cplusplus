#include<cstdio>
bool binarySearch(int A[], int n, int key){
    int left = 0;
    int right = n;
    while (left < right){
        int mid = (int)((left+right)/2);
        if(A[mid]==key) return true;
        else if(key<A[mid]) right=mid;
        else left = mid+1;
    }
    return false;
}

int main(){
    int n, q, S[100000], temp, sum=0;
    
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        scanf("%d", &temp);
        if(binarySearch(S, n, temp)) sum++;
    }
    printf("%d\n", sum);
    return 0;
}