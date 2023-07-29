#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> &arr, int size){
    int i = 0 ;
    int j = size-1;
    int t=0;


    while(i<j){
        if(arr[i]==2){
            swap(arr[i],arr[j]);
            j=j-1;
            while(arr[j]==2){
                j=j-1;
            }
        }
        if(arr[i]==0){
            swap(arr[i],arr[t]);

            t=t+1;
            i=i+1;


        }
        if(arr[i]==1){
            i++;
        }


    }
}

int main(){
   vector<int> arr;
   cout<<"Enter the size of array: ";
   int size ;
   cin>>size;
    cout<<endl;
    
    for(int i =0; i<size; i++){
        
        int temp;
         cin>>temp;
         arr.push_back(temp);
    }
    sort(arr,size);
    cout<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

}