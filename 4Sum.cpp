#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// naive solution using four loops
// time complexity : O(n4)
// space complexity : O(2* no. of quadruplets)

vector<vector<int>> fourSum(vector<int> &nums,int target){
    int n = nums.size();
    // using set to store unique quadruplets
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l = k+1;l<n;l++){
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }

                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

// Better solution : using 3 loops and set data structures
// time complexity : O(n3) + O(log m) m = size of hashset
// space complexity : O(2* no. of quadruplets) + O(n)

vector<vector<int>> fourSum1(vector<int> &nums,int target){
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long> hashset;
            for(int k=j+1;k<n;k++){
                long long sum = nums[i]+nums[j];
                sum+= nums[k];
                long long fourth = target-sum;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {nums[i],nums[j],nums[k],(int)(fourth)};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

// optimal solution
// time complexity : O(n3)
// space complexity : O(no. of  quadruplets)

vector<vector<int>> fourSum2(vector<int> &nums,int target){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        //avoid duplicates while moving i
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j = i+1;j<n;j++){
            //avoid duplicates while moving j
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            //2 pointers
            int k = j+1,l = n-1;
            while(k<l){
                long long sum = nums[i]+nums[j];
                sum+=nums[k]+nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    //skip duplicates
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while (k<l && nums[l] == nums[l+1]) l--;
                }
                else if(sum<target) k++;
                else l--;  
            }
        }
    }
    return ans;
}




int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> res = fourSum2(arr,target);
    for(auto x:res){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}