#include <bits/stdc++.h>
#include <fstream> 
#include<math.h>
using namespace std;
double dx(int x){
    return 10*cos(x);
};
double dy(int y){
    return 2*y;
};
void GD(double x0, double y0, double learningrate, unsigned long int loops){
    double tempx=x0;
    double tempy=y0;
    for(int i=0; i<loops; i++){
        x0=tempx-learningrate*dx(x0);
        y0=tempy-learningrate*dy(y0);
        if (abs(dx(x0))<0.001||abs(dy(y0))<0.001){
            cout<<"xmin="<<x0;
            cout<<"ymin="<<y0;
            break;
        };

    };
};
int main(){
    GD(4.72, 3.162, 0.1, 10000);
    return 0;
}