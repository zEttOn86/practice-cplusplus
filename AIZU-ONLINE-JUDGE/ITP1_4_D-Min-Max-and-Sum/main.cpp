#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n, max_val=-1000000, min_val=1000000, temp;
    long long sum=0;
    printf("Hello");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        sum += temp;
        max_val = max(temp, max_val);
        min_val = min(temp, min_val);
    }
    printf("%d %d %lld\n", min_val, max_val, sum);
    
    return 0;
}
