#include<cstdio>
#include<cmath>
struct Point{double x, y;};

int main(){
    Point a, b;
    scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);

    double dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));

    printf("%.8f\n", dist);

    return 0;
}