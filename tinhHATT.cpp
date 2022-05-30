#include<iostream>
#include <math.h>
#include <fstream>
using namespace std;


int main(){
    ifstream filein;
    int i;
    double w0=0, w1=0;
    double alpha=0.0003;
    double x[18], y[18];
    filein.open("HATT.txt", ios_base::in);
    if (filein.fail()==true){
        cout<<"File not found"<<endl;
        return 0;
    };
    for (i=0; i<18; i++){
        filein>>x[i];
        filein>>y[i];
    }
    filein.close();
    double pd0, pd1;
    while(true){
        pd0=0;
    for (i=0; i<18; i++){
        pd0 = pd0+(0.055 * (w0 + (w1 * x[i]) - y[i]));
    };
    pd1=0;
    for (i = 0; i < 18; i++) {
        
        pd1 += (0.055 * (w0 + (w1 * x[i]) - y[i])) * x[i];
    };
    w0 = w0-(alpha * pd0);
    w1 = w1-(alpha * pd1);
    if ((pd0 * pd0 + pd1 * pd1) < 0.01)
          break;
    };

    
    int tuoi=0;
    cout<<"Nhap tuoi cua nguoi muon do HATT: ";
    cin>>tuoi;
    double hatt=w0 + w1 * tuoi;
   
    cout<<"HATT cua nguoi "<<tuoi<<" la:"<<round(hatt);

    return 0;

}
