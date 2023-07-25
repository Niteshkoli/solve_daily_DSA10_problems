#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// naive approach
// time complexity : O(n*n)
// space complexity : O(1)

vector<int> twoSum(vector<int> &arr,int target){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == target){
                return {i,j};
            }
        }
    }

    return {-1,-1};
}

// better approach - using hashing
// time complexity : O(n) note-> unordered_map's find function can take O(n) time and overall t.c. can become O(n*n)
// better to use map it only take O(log n)
// space complexity : O(n) - becoz of unordered_map

vector<int> twoSum1(vector<int> &arr,int target){
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        int num = arr[i];
        int neededNum = target - num;
        if(mp.find(neededNum) != mp.end()){
            return {mp[neededNum],i};
        }
        mp[num] = i;
    }
    return {-1,-1};
}

// optimal approach using left & right pointer
// but in this case order of the elements is change as we are sorting the elements so can only tell sum is present or not
// time complexity : O(n) + O(nlogn)
// space complexity : O(1)

vector<int> twoSum2(vector<int> &arr,int target){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int left = 0 , right = n-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target) return {left,right};
        else if(sum < target) left++;
        else right--;
    }
    return {-1,-1};
}

int main(){
    vector<int> arr = {2,6,5,8,11};
    int target = 14;
    vector<int> ans = twoSum2(arr,target);

    for(int x:ans){
        cout<<x<<" ";
    }

    return 0;

}
