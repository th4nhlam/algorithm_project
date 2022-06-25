#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <fstream>
using namespace std;
double derivative(double x){
    return 2*x+10*cos(x);
}
double Gdmomentum(double x0, double alpha,double beta, unsigned long int loops){
    int i=1;
    double x=x0;
    int k;
    double v=0;
    
    while (i<=loops && derivative(x)>=0.001||derivative(x)<0){
        k=i-1;
        v=beta*v+alpha*derivative(x);
        x=x-v;
        i++;

    };
    
    cout<<"xmin tinh bang GD with Momentum:"<<x<<endl;
    double y=pow(x0,2)+10*sin(x0);
    cout<<"y min tinh bang GD with momentum:"<<y<<endl;
    cout<<"So lan lap GD with momentum:"<<i-1<<endl;
    return x;
}

double gradient_descent(double learning_rate, double x0) {
    double temp=x0;
    for (double i = 0; i < 10000000000000; ++i)
    {
        x0 = temp - learning_rate * derivative(x0);//learning rate 0.001 là hợp lý
        if(abs(derivative(x0)) <=0.00000001) {
            cout<<"Ket qua xmin bang pp Gradient Descent:"<<x0<<endl;
            double y=pow(x0,2)+10*sin(x0);
            cout<<"Ket qua ymin bang pp Gradient Descent:"<<y<<endl;
            cout << "So lan lap GD:" <<i<<endl;
            
            break;
        }
        temp = x0;
    }
    return x0;

};
int main() {
    double xmin;


    xmin=Gdmomentum(5, 0.1, 0.9, 10000);
    gradient_descent(0.05, 5);
    
    double ymin=pow(xmin,2)+10*sin(xmin);
    
    
    return 0;
}
