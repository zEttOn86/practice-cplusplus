#include<cstdio>

int main(int argc, char const *argv[])
{
    int H, W;
    while(1){
        scanf("%d %d", &H, &W);

        if(H==0 && W==0) break;

        for(int j=0; j<H; j++){
            for(int i=0; i<W; i++){
                if(j%2 == 0){
                    if(i%2 == 0) printf("#");
                    else printf(".");
                }
                else{
                    if(i%2 == 0) printf(".");
                    else printf("#");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}
