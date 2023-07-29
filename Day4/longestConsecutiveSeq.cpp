#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> longestSeq(vector<int> nums){

    int maxi = 0; 
    int count =0; 
    int si=nums[0];
    int end = nums[0];

    unordered_map<int,int> ourmap;
    for(int i=0; i<nums.size(); i++){
        ourmap[nums[i]]++;
    }
    for(int i=0; i<nums.size(); i++){

        int temp=nums[i];
        while(ourmap.count(temp)>0){
            count++;
            temp= temp + 1;
        }
        int e = maxi;
        maxi = max(count, maxi);
        if(maxi>e){
            si = nums[i];
            end = si+count-1;
        }
        count =0;

    }
    vector<int> ans;
    ans.push_back(si);
    if(si!=end){
        ans.push_back(end);
    }

    return ans;

}

vector<int> longestSeq2(vector<int> nums){
    unordered_map<int,bool> ourmap;
    for(int i=0 ; i<nums.size(); i++){
        pair<int,bool> p(nums[i],true);
        ourmap.insert(p);
    }


    int si=nums[0];
    int end = si;
    int count = 0;
    int maxi = 0;

    for(const auto &pair : ourmap){
        int temp = pair.first;
        bool temp1 = pair.second;

        while(temp1 && ourmap.count(temp)>0){
            count++;
            ourmap[temp]=false;
            temp++;
            temp1 =ourmap[temp];
        }
        temp = pair.first-1;
        temp1 = ourmap[temp];
        
        while(temp && ourmap.count(temp)>0){
            ourmap[temp]=false;
            count++;
            temp--;
            temp =ourmap[temp];
        }
        int e = maxi;
        maxi = max(count, maxi);
        if(maxi>=e){
            si = pair.first;
            end = si+count-1;
        }
        count = 0;

    }
    vector<int> ans;
    ans.push_back(si);
    if(si!=end){
        ans.push_back(end);
    }

    return ans;
}


int largestDistance(vector<int> nums){
    unordered_map<int, int> ourmap;
    int maxi =0; 
    int count = 0;



}


// sum array sum to 0

bool sumArray(vector<int> nums){
    int sum =0 ;
    unordered_map<int,int> ourmap;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        
    }
}


int main(){
    vector<int> nums;
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    for(int i=0 ; i<size; i++){
        int temp; cin>>temp; nums.push_back(temp);
    }
    // vector<int> ans = longestSeq2(nums);
    //     for(int i=0 ; i<ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }
    cout<<largestDistance(nums);

}