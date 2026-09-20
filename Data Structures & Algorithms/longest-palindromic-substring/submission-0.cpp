class Solution {
public:
    bool t[1000][1000];
    string longestPalindrome(string s) {
        int maxlen = INT_MIN, idx = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            t[i][i] = true;
            maxlen = 1;
        }
        //len 1 vala palindrome hai check for len>= 2 and onwards 
        for(int len = 2; len <= n; len++){
            for(int i=0; i < n - len + 1; i++){
                int j = i+len-1;
                if(s[i] == s[j] && len == 2){
                    t[i][j] = true; 
                    maxlen = 2;
                    idx = i;
                }
                else if(s[i] == s[j] && t[i+1][j-1] == true){
                    t[i][j] = true;
                    if(maxlen < j-i+1){
                        maxlen = j-i+1;
                        idx = i;
                    }
                }
                else{
                    t[i][j] = false;
                }
            }
        }
        return s.substr(idx, maxlen);
    }
};