#include<iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream filein;
    int w0, w1,i;
    int x[20], y[20];
    filein.open("HATT.txt", ios_base::in);
    if (filein.fail()==true){
        cout<<"File not found"<<endl;
        return 0;
    };
    for (i=0; i<20; i++){
        filein>>x[i];
        filein>>y[i];
    }
    filein.close();
    
    return 0;
}
