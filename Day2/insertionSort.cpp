#include<iostream>

using namespace std;

void insertionSort(int arr[],int n ){
    int max = arr[0];

    for(int i = 1; i<=n ;i++){

        int cmp = i-1;
        while(cmp!=0){
            if(arr[cmp-1]>arr[cmp]){
                int temp = arr[cmp];
                arr[cmp]= arr[cmp-1];
                arr[cmp-1]= temp;
                cmp--;
            }
            else{
                break;
            }
        }

    }


 return ;
}

int main(){
    int arr[10];
    int n = 10;
    for(int i = 0 ;i<10 ; i++){
        cin>>arr[i];
    }
    insertionSort(arr,n);
    for(int i =0 ;i<n; i++){
        cout<<arr[i]<<" "; 
    }

}