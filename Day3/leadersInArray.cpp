#include<iostream>
#include<vector>
using namespace std;

void leaders(vector<int> &nums){
    int i =0;
    int j = nums.size()-1;
    vector<int> ans;
    while(i<nums.size()){



        while(i<=j){
            if(i==j){
                ans.push_back(nums[i]);
                j = nums.size()-1;
                i++;
                break;
            }
            if(nums[i]>nums[j]){
                j--;
            }
            else if(nums[i]<nums[j]){
                i++; 
                j = nums.size()-1;
                break;
            }

        }

    }


    for(int k=0; k<ans.size(); k++){
        cout<<ans[k]<<" ";
    }
}

int main(){
    vector<int> nums;
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    for(int i=0; i<size; i++){
        int temp; 
        cin>>temp; 
        nums.push_back(temp);
    }
    leaders(nums);
}