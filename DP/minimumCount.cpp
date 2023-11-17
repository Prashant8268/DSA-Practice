#include<iostream>
#include <cmath>
using namespace std;




// Problem Description:
// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
// Input format :
// The first and the only line of input contains an integer value, 'N'.

// Output format :
// Print the minimum count of numbers required.

// Constraints :
// 0 <= n <= 10 ^ 4

// Time Limit: 1 sec

// Sample Input 1 :
// 12

// Sample Output 1 :
// 3



// using recursion 
int minimumCount(int n){
    if(n<=1){
        return n;
    }

    int ans = n;
    for(int i = 1; i<=sqrt(n); i++){
        int output = minimumCount(n-(i*i)) + 1; 
        ans = min(ans, output);
    }
    return ans; 

}



// using memoization 
int memoHelper(int n , int  * arr){
        if(n<=1){
        return n;
    }

if (arr[n] != -1) {
        return arr[n];
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        int output = memoHelper(n - (i * i), arr) + 1;
        ans = min(ans, output);
    }

    arr[n] = ans;
    return ans;
}

int minimumCountMemo(int n ){
    int * arr = new int[n+1];
    for(int i =0; i<=n; i++){
        arr[i] = -1; 
    }

    int output = memoHelper(n , arr);
    delete arr; 
    return output;

}


// using dp 



int main(){
    int n; 
    cout<<"Enter the number : ";
    cin>>n;
    int output = minimumCountMemo(n);
    cout<<"Answer : "<< output;
}