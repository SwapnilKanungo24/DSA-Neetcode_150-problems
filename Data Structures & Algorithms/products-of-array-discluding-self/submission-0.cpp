class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            prod *= nums[i];
        }
        int i = 0;
        while(i < nums.size()){
            int temp = prod;
            if(nums[i] != 0){
                //cout << temp/nums[i] << "\n";
                result.push_back(temp/nums[i]);
            }
            else{
                int mult = 1;
                for(int l = 0; l < nums.size(); l++){
                    if(i != l) mult *= nums[l];
                }
                result.push_back(mult);
            }
            i++;
        }
        return result;
    }
};