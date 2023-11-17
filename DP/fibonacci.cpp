#include <iostream>
using namespace std;



// reducing the time complexitiy of fibonacci using memoization (top down approach)

int fibo_helper(int n , int * arr){
    if(n<=1){
        return n;
    }
    // checking if fibo already exist 
    if(arr[n]!=-1){
        return arr[n];
    }
    // calling n-1 amd n-1 to get fibo

    int a = fibo_helper(n-1, arr);
    int b = fibo_helper(n-2,arr);

    // save ans before return 
    arr[n]= a+b;

    return a+b;
}

int fibo(int n){
    int * arr = new int[n+1];

    for(int i=0; i< n+1; i++){
        arr[i]=-1;
    }
    return fibo_helper(n, arr);
}

// avoid using recursion also called dynamic programming (bottom-up approach)

int getFibo(int n){
    int * arr = new int[n+1];

    arr[0]=0;
    arr[1]=1;

    for(int i=2; i<n+1; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }

    return arr[n];
}








int main(){
    int n ; 
    cout<<"Enter the number : ";
    cin>>n;
    int ans = getFibo(n);
    cout<<"Fibo number at n : "<< ans ;
}