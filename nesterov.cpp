#include <bits/stdc++.h>
#include <fstream> 
#include<math.h>
using namespace std;
double derivative(double x){
    return 2*x+10*cos(x);
};
double nesterov(double x0, double alpha, double beta, unsigned long int loops){
    int i=1;
    double x=x0;
    double  x_lookahead;
    int k;
    double v[loops];   
    v[0]=0;
    while (i<=loops && (derivative(x)>=0.001||derivative(x)<0)){
        k=i-1;
        x_lookahead=x-(alpha*v[k]);
        v[i]=alpha*v[k]+(beta*derivative(x_lookahead));
        x=x-v[i];
        i++;
    };
    cout<<"So lan lap:"<<i-1<<endl;;
    return x;
};
int main(){
    double x=nesterov(5, 0.1, 0.9, 10000);
    cout<<"x="<<x;
    return 0;
}