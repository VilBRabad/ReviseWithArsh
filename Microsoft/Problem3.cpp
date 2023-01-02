#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void combinations(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int index, int k, int target){
        if(index == nums.size()){
            if(target==0 && k==0){
                ans.push_back(temp);
            }
            return;
        }
        if(nums[index] <= target){
            temp.push_back(nums[index]);
            combinations(nums, ans, temp, index+1, k-1, (target-nums[index]));
            temp.pop_back();
        }
        combinations(nums, ans, temp, index+1, k, target);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> temp;

        combinations(nums, ans, temp, 0, k, n);
        return ans;
    }
};