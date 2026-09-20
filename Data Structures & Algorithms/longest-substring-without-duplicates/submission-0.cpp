class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxlen = INT_MIN;
        int n = s.length();
        unordered_map<char, int> ump;
        if(n == 0) return 0;
        while(r < n){
            if(ump.find(s[r]) != ump.end()){
                if(ump[s[r]] >= l && ump[s[r]] < r){
                    l = ump[s[r]] + 1;
                }
                ump[s[r]] = r;
            }

            if(ump.find(s[r]) == ump.end()){
                ump[s[r]] = r;
            }
            
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;   
    }
};