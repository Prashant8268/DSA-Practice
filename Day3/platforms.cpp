// no of platform required 

#include<iostream>
#include<vector>
using  namespace std;

int platforms(vector<int> nums1, vector<int> nums2){

    int p1=nums1[0];
    int p2 = nums2[0];

    int count = 1;

    for(int i=1; i<nums1.size(); i++){

        if(nums1[i]>p2){
            count++;
            p1=nums1[i];
            p2=nums2[i];
        }
        if(nums1[i]<p2 && nums2[i]>p1){
            count++;

        }



    }

    return count;

}

int main(){
    vector<int> nums1;
    int size;
    cout<<"Enter the size of array 1: ";
    cin>>size;
    for(int i=0; i<size; i++){
        int temp ;
        cin>>temp;
         nums1.push_back(temp);
    }
    vector<int> nums2;
cout<<endl;
    cout<<"Enter the size of array 2: ";
 
    for(int i=0; i<size; i++){
        int temp ;
        cin>>temp;
         nums2.push_back(temp);
    }
    cout<<platforms(nums1,nums2);

}