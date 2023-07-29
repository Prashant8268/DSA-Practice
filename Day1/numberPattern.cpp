#include<iostream>
using namespace std;

void numberPatter(int n){
    for(int i =1; i<=n; i++){
        for(int j =1; j<=i ;j++){
            cout<<j;

        }
        int spaces = n-i;
        for(int k=spaces; k>0; k--){
            cout<<"-";
        }
        for(int k =0; k<spaces; k++){
            cout<<"-";
        }
        int number =i;
        while(number!=0){
            cout<<number;
            number--;
        }
        cout<<endl;


    }
}
int main(){
    int n; 
    cout<<"Enter the number : ";
    cin>>n; 
    numberPatter(n);
}