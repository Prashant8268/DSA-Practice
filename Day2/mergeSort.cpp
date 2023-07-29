#include<iostream>
using namespace std;

void merge(int arr[],int begin,int end){

int i = 0;
int mid = (begin+end)/2;
int p=0;
int j =mid;
int ans[begin+end];
while(i<mid && j <end){
    if(arr[i]<arr[j]){
        ans[p++]= arr[i++];
    }
    else{
        ans[p++] = arr[j++];
    }

}
while(i<mid){
    ans[p++]= arr[i++];

}
while(j<end){
    ans[p++] = arr[j++];

}

    for(int i =0; i<end; i++){
        arr[i] = ans[i];
    }
    
}

void mergeSort(int arr[],int begin, int end){

    if(begin>=end){
        return ;
    }
    mergeSort(arr, 0, (begin+end)/2);
    mergeSort(arr,(begin+end)/2+1, end);
    merge(arr,begin, end);

}

int main(){

    int arr[10];
    for(int i =0;i<10 ;i++){
    cin>>arr[i];


    }
    mergeSort(arr,0,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" "; 
    }


}