class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(int i = 0; i < nums.size(); i++){
            ump[nums[i]]++;
        }
        //sort the values
        //first store in vector and then sort 
        vector<pair<int, int>> temp = {ump.begin(), ump.end()}; //pair store the key with value
        //sort 
        sort(temp.begin(), temp.end(), [](auto &a, auto &b){
            return a.second > b.second; //sort values
        });
        //access top k elements 
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(temp[i].first);
        }
        return result;
    }
};
