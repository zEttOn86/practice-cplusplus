#ifndef   VECTOR_HPP
#define   VECTOR_HPP
#include<cmath>

#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b))<EPS)

class Point{
    public:
    double x, y;

    Point(double x=0, double y=0):x(x), y(y){}

    Point operator + (Point p) {return Point(x+p.x, y+p.y); }
    Point operator - (Point p) {return Point(x-p.x, y-p.y); }
    Point operator * (double a) {return Point(a*x, a*y); }
    Point operator / (double a) {return Point(a*x, a*y); }

    double abs() {return sqrt(norm());}
    double norm() {return x*x+y*y; }

    bool operator < (const Point &p) const{
        return x != p.x ? x<p.x: y<p.y;
    }

    bool operator == (const Point &p) const{
        return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
    }
};

typedef Point Vector;

double dot(Vector a, Vector b){
    return a.x * b.x+a.y*b.y;
}

double cross(Vector a, Vector b){
    return a.x*b.y -a.y*b.x;
}

bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a,b), 0.);
}

bool isOrthogonal(Point a1, Point a2, Point b1, Point b2){
    return isOrthogonal(a1-a2, b1-b2);
}

bool isParallel(Vector a, Vector b){
    return equals(cross(a,b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2){
    return isParallel(a1-a2, b1-b2);
}

#endif // VECTOR_HPP