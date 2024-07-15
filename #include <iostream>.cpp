#include <iostream>
using namespace std;

int main(){

    int a;
    int b;
    cout << " ENTER the two numbers ";
    cin >> a;
    cin >> b;
    cout << " TYPE OF OPERATION";

 int sum;
    int diff;
    float divison;
    int mul;
    sum = a + b;
    mul = a*b;
    divison = a/b;
    diff = a -b;
    char name ;
   
    if (name == 'SUM'){
        cout<< sum;
    }

     if (name == 'MUL'){
        cout << mul;
    }
     if (name == 'DIFFERENCE'){
        cout<< diff;
    }
if(name == 'DIVISON'){
    cout << division;
}
    
   
    


    
    return 0;
}