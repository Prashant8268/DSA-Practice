#include<iostream>
using namespace std;


// using recursio 
int stairCase(int n){
    if(n<=1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }

    return stairCase(n-1)+stairCase(n-2)+stairCase(n-3);

}


// using memoization
int memoHelper(int n, int * arr){
        if(n<=1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }

    if(arr[n]!=-1){
        return arr[n];
    }

    int ans1 = memoHelper(n-1,arr);
    int ans2 = memoHelper(n-2,arr);
    int ans3 = memoHelper(n-3,arr);
    int output = ans1+ans2+ ans3;
    arr[n]=output;
    return output;

} 
int stairCaseMemo(int n){
    int * arr = new int[n+1];
    for(int i=0; i<=n; i++){
        arr[i]=-1;
    }
    int ans = memoHelper(n,arr);
    delete arr;
    return ans;

}


// staircase using dp 

int stairCaseDp(int n ){
    int  * arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2; 
    arr[3] = 4;
    if(n<4){
        return arr[n];
    }
    for(int i = 4; i<=n; i++){
        arr[i] = arr[i-1]  + arr[i-2] + arr[i-3];
    }
    return arr[n];
}


int main(){
    int n;
    cout<<"Enter the number of staircase : ";
    cin>>n;
    cout<<"Answer : "<< stairCaseDp(n);
}