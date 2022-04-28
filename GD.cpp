#include <bits/stdc++.h>//cho nhiều bài toán, dùng phương pháp optimization để giải quyết
#include<math.h>
#include <fstream> 
using namespace std;

//Chương trình tìm cực tiểu của hàm f(x)
int derivative(int a[], int bac, int x){//Lấy đạo hàm của hàm 
    int sum=0;
    int temp;
    for (int i=0; bac!=0; i++){ 
        temp=bac*a[i]*pow(x, (bac-1));
        bac--;
        sum=sum+temp;
    }
    return sum;
};
double gradient_descent(double learning_rate, double x0, int a[], int bac) {
    double temp=x0;
    for (double i = 0; i < 10000000000000; ++i)
    {
        x0 = temp - learning_rate * derivative(a, bac, x0);//learning rate 0.001 là hợp lý
        if(abs(derivative(a, bac, x0)) <=0.00000001)
            break;
        temp = x0;
    }
    return x0;
};
int main(){
    ifstream filein;
    filein.open("text.txt", ios_base::in);
    int bac, i;
    if (filein.fail()==true){
        cout<<"File not found"<<endl;
        return 0;
    };
    
    filein>>bac;//bậc của hàm
    int heso[bac];
    for (i=0; i<=bac; i++){
        filein>>heso[i];
    }
    filein.close();
    

    
    double xmin=gradient_descent(0.05, 2, heso, bac);
    cout<<"x local min = "<<xmin<<endl;
    double ymin=0;
    double temp;
    for (i=0; bac!=-1; i++){
        temp=heso[i]*pow(xmin, bac);
        bac--;
        ymin=temp+ymin;
    }
    cout<<"y local min = "<<ymin<<endl;
    return 0;
}