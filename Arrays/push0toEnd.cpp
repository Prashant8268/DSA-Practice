#include<iostream>
#include<vector>
using namespace std;

void pushZero(vector<int> &nums){
    int size = nums.size();
    int nonZeroAt = 0;
    int i=0;
    while(i<size)
        if(nums[i]==0){
            i++;
        }
        else{
            swap(nums[i],nums[nonZeroAt]);
            nonZeroAt++;
            i++;
        }
    }


int main(){
    vector<int> nums;
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    for(int i=0; i<size;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    pushZero(nums);
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }

}