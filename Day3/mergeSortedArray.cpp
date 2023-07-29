#include<iostream>
#include<vector>
using namespace std;


vector<int> merge(vector<int> arr1, int n, vector<int> arr2, int m){
    int i =0;
    int j = 0;
    int newsize = n+m;
    vector<int> ans;
    int p=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i++]);

        }
        else{
            ans.push_back(arr2[j++]);
        }
    }

while(i<n){
    ans.push_back(arr1[i++]);
}

while(j<m){
     ans.push_back(arr2[j++]);

}


return ans;
}

int main(){
    vector<int> arr1;
    int n;
    cout<<"Enter the size of array1 ";
    cin>>n;


    cout<<"Enter the elements of array1";
    for(int i =0; i<n; i++){
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }
    cout<<endl;

    vector<int> arr2;
    cout<<"Enter the size of array 2: ";
    int m;
    cin>>m;
        for(int i =0; i<m; i++){
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }

    vector<int> ans = merge(arr1,n,arr2,m);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }



}