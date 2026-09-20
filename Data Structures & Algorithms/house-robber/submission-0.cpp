#include<bits/stdc++.h>
using namespace std;

class Solution {
    int t[101];
public:
    int solve(vector<int> &nums, int i, int n){
        if(i >= n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        return t[i] = max(nums[i] + solve(nums, i + 2, n), solve(nums, i + 1, n));
    }
    int rob(vector<int>& nums) {
        memset(t, -1,  sizeof(t));
        int n = nums.size();
        return solve(nums, 0, n);
    }
};
