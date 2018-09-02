#include<iostream>
#include"vector.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    int q;
    Point p0, p1, p2, p3;
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        if(isParallel(p0, p1, p2, p3)){
            printf("2\n");
        }
        else if(isOrthogonal(p0, p1, p2, p3)){
            printf("1\n");
        }
        else printf("0\n");
    }
    return 0;
}
