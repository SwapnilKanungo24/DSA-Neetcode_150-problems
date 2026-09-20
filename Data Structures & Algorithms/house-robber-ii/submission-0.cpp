#include<bits/stdc++.h>
class Solution {
    int t[101];
private:
    int solve(vector<int> &nums, int i, int n){
        if(i > n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        return t[i] = max((nums[i] + solve(nums, i + 2, n)), solve(nums, i + 1, n));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        memset(t, -1, sizeof(t));
        int byZeroIndex = solve(nums, 0, n-2);
        memset(t, -1, sizeof(t));
        int byOneIndex = solve(nums, 1, n-1);

        return max(byZeroIndex, byOneIndex);
    }
};