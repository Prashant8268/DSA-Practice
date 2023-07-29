#include<iostream>
using namespace std;


void arrow(int n){
    int star = n/2+1;
    int space = star-1;
    int si = 1;
    for(int i =0; i<star; i++){
        for(int j = 1; j<si; j++){
            cout<<" ";
        }

        for(int k = 0 ; k<si; k++){
            cout<<"*";
        }
        cout<<endl;
        si++;
        
    }

      star = si-1;
    int t=star;
    space = star-1;
    for(int i=1; i<t; i++){
        for(int j=1; j<space; j++){
            cout<<" ";
        }
        space--;
        for(int p = 1; p<star; p++){
            cout<<"*";
        }
        star--;
        cout<<endl;
    }


    



}
int main(){

    int n ;
    cout<<"Enter the number";
    cin>>n ;
    arrow(n);
    return  0; 

}