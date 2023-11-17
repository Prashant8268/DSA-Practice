#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(vector<int> nums){
    unordered_map<int, bool > ourmap;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++){
        if(ourmap.count(nums[i])>0){
            continue;
        }

        ourmap[nums[i]]= true;

        ans.push_back(nums[i]);

    }

    return ans;


// for looping over a unordered map 
    //     for (const auto& pair : myMap) {
    //     const std::string& key = pair.first;
    //     const int& value = pair.second;
    //     std::cout << "Key: " << key << ", Value: " << value << std::endl;
    // }
}


int maximumFrequency(vector<int> nums){
    unordered_map<int,int> ourmap;
    int max= 1;
    int ans=nums[0];
    for(int i=0 ; i<nums.size(); i++){
        if(ourmap.count(nums[i])>0){
            ourmap[nums[i]]= ourmap[nums[i]]+1;
            if(ourmap[nums[i]]>max){
                max= ourmap[nums[i]];
                ans=nums[i];
            }

        }
        else{
            ourmap[nums[i]]=1;
        }

    }
    
    // for (const auto& pair : ourmap) {
    //     if(pair.second>max){
    //         max=pair.second;
    //         ans=pair.first;

    //     }

    // }
    return ans;

}

vector<int> intersection(vector<int> nums1, vector<int> nums2){
    unordered_map<int, int > ourmap;
    vector<int> ans;
    for(int i=0; i<nums1.size(); i++){
        if(ourmap[nums1[i]]>0){
            ourmap[nums1[i]]=ourmap[nums1[i]]+1;
            continue;
        }
        ourmap[nums1[i]]=1;
    }
    for(int i =0 ;i< nums2.size(); i++){
        if(ourmap.count(nums2[i])>0){
            ans.push_back(nums2[i]);
            ourmap[nums2[i]]= ourmap[nums2[i]]-1;

        }

    }

    return ans;
}


int Sum(vector<int> nums){
    unordered_map<int,int> ourmap;
    int ans =0;

    for(int i=0; i<nums.size(); i++){
        ourmap[nums[i]]++;        
    }

    for(const auto &pair: ourmap){

        if(pair.first>0){

        if(ourmap.count(-pair.first)>0){
            int p = min(pair.second,ourmap[-pair.first]);
            ans = ans+p;
            ourmap[-pair.first]= ourmap[-pair.first]-p;
            ourmap[pair.first]=ourmap[pair.first]-p;


        }

        }

    }

    return ans;
}




int main(){

    vector<int> nums;
    int size;
    cout<<"Enter the size of array: ";
    cin>> size; 
    for(int i=0; i< size; i++){
        int temp; 
        cin>>temp;
        nums.push_back(temp);
    }



}