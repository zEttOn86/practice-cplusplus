#include<cstdio>
struct Point{double x, y;};

int main(int argc, char const *argv[])
{
    Point p0, p1, p2;
    Point a, b, x;
    int q;
    scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
    a.x = p2.x - p1.x;
    a.y = p2.y - p1.y;

    scanf("%d", &q);

    for(int i=0; i<q; i++){
        scanf("%lf %lf", &p0.x, &p0.y);
        b.x = p0.x - p1.x;
        b.y = p0.y - p1.y;
        x.x = (a.x*b.x+a.y*b.y)/(a.x*a.x+a.y*a.y) * a.x;
        x.y = (a.x*b.x+a.y*b.y)/(a.x*a.x+a.y*a.y) * a.y;
        printf("%.10lf %.10lf\n", x.x + p1.x, x.y+p1.y);
    }
    return 0;
}
