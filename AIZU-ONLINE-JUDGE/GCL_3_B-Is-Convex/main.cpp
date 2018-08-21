#include<cstdio>
#define MAX 100
struct Point{double x, y;};
Point T[MAX];

double cross(double x1, double y1, double x2, double y2){
    return x1*y2 - x2*y1;
}

double ccw(Point p1, Point p2, Point p3){
    return cross(p2.x-p1.x, p2.y-p1.y, p3.x-p2.x, p3.y-p2.y);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i =0; i<n; i++) scanf("%lf %lf", &T[i].x, &T[i].y);

    double result;
    bool flag = true;
    for(int i=0; i<n; i++){
        if(i==0){
            result = ccw(T[n-1], T[i], T[i+1]);
        }
        else if(i == n-1){
            result = ccw(T[i-1], T[i], T[0]);
        }else{
            result = ccw(T[i-1], T[i], T[i+1]);
        }
        if(result <0){
            flag = false;
            break;
        }
    }

    if(flag) printf("1\n");
    else printf("0\n");
    return 0;
}   
