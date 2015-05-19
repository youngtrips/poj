#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 655;
const double PI = acos(-1.0);
double dis[MAXN][MAXN];
int x[MAXN], y[MAXN];
double distance(double x1, double y1, double x2, double y2) {
     return sqrt((double)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
double triangleArea(int i, int j, int k) {
     return fabs((double)(x[i] - x[k]) * (y[j] - y[k]) - (x[j] - x[k]) * (y[i] - y[k])) / 2;
}
double radiusOfCircumcircleOfTriangle(int i, int j, int k) {
     double radius = dis[i][j] * dis[i][k] * dis[j][k] / triangleArea(i, j, k) / 4;
     return radius;
}
int main() {
     int casn;
     scanf("%d", &casn);
     while(casn --) {
          int i, j, k, n;
          scanf("%d", &n);
          for(i = 0; i < n; i ++) {
               scanf("%d%d", &x[i], &y[i]);
          }
          for(i = 0; i < n; i ++)
               for(j = i + 1; j < n; j ++)
                    dis[i][j] = dis[j][i] = distance(x[i], y[i], x[j], y[j]);
          double maxRadius = 0;
          for(i = 0; i < n; i ++)
               for(j = i + 1; j < n; j ++)
                    for(k = j + 1; k < n; k ++) {
                        double radius = radiusOfCircumcircleOfTriangle(i , j, k);
                        if(radius > maxRadius) maxRadius = radius;
                    }
          printf("%.3lf\n", maxRadius);
     }
     return(0);
}