#include<iostream>
using namespace std;

int duplicate(int arr[],int size){

    int ans = arr[0];
    for(int i=0; i<size; i++){
        ans= ans xor arr[i];

    }
    return ans;
}

int main(){

    int a=8;
    int b=7;



    
}