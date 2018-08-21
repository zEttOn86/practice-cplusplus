#include<cstdio>
#include<cstring>
#define NIL -1
#define M 1046527

// 文字から数値に変換
int getChar(char ch){
    if(ch == 'A') return 1;
    else if(ch=='C') return 2;
    else if(ch=='G') return 3;
    else if(ch=='T') return 4;
    else return 0;
}
// 文字列から数値へ変換してkeyを生成する
long long getKey(char str[]){
    long long sum=0, p=1;
    for(long long i=0; i< strlen(str);i++){
        sum += p*(getChar(str[i]));
        p*=5;
    }
    return sum;
}


int h1(int key, int m){
    return key%m;
}
int h2(int key, int m){
    return 1+(key%(m-1));
}
int find(char str[], char H[][14]){
    long long key = getKey(str);
    for(long long i=0;;i++){
        long long h = (h1(key, M) + i*h2(key, M)) % M;
        if(strcmp(H[h], str)==0) return 1;
        else if(strlen(H[h])==0) return 0;
    }
    return 0;
}
int insert(char str[], char H[][14]){
    long long key = getKey(str);
    for(long long i =0;; i++){
        long long h = (h1(key, M) + i*h2(key, M)) % M;
        if(strcmp(H[h], str)==0) return 1;
        else if(strlen(H[h])==0){
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;
}

int main(){
    int n;
    char str[14], com[9];
    char H[M][14];

    for(int i=0;  i<M;i++)H[i][0] = '\0';
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s %s", com, str);
        if(com[0] == 'i'){
            insert(str, H);
        }
        else{
            if(find(str, H)) printf("yes\n");
            else printf("no\n");
        }
    }

    return 0;
}