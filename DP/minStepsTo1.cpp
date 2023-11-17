#include<iostream>
#include <climits>
using namespace std;


// min steps to calculate steps to reach 1 using recursion 
int minSteps(int n){

    if(n==1){
        return 0;
    }
    int ans1= minSteps(n-1);
    int ans2 = 100;
    int ans3= 100;
    if(n%2==0){
        ans2 = minSteps(n/2);
    }
    if(n%3==0){
        ans3 =minSteps(n/3);
    }

    return min(ans1,min(ans2,ans3)) + 1;
}


// min steps using memoization (up-down)
int memoHelper(int n, int *arr) {
    if (n <= 1) {
        return 0;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int ans1 = memoHelper(n - 1, arr);

    int ans2 = INT_MAX - 1;  // Adjusted to avoid overflow
    if (n % 2 == 0 ) {
        ans2 = memoHelper(n / 2, arr);
    }
    
    int ans3 = INT_MAX - 1;  // Adjusted to avoid overflow
    if (n % 3 == 0) {
        ans3 = memoHelper(n / 3, arr);
    } 

    int output = min(ans1, min(ans2, ans3)) + 1;
    arr[n] = output;
    return output;
}

int minStepMemo(int n) {
    int *arr = new int[n+1];

    for (int i = 0; i <= n; i++) {
        arr[i] = -1;
    }
    int result = memoHelper(n, arr);
    delete[] arr;
    return result;
}




int main(){
    int n ;
    cout<<"Enter the number : "; cin>>n;
    int ans = minStepMemo(n);
    cout<<"Answers : "<<  ans;
}