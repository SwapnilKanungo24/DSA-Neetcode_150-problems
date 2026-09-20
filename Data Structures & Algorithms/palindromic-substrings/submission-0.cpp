class Solution {
public:
    bool t[1000][1000];
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = n;
        for(int i = 0; i < n; i++){
            t[i][i] = true;
        }
        for(int len = 2; len<= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                if(s[i] == s[j] && len == 2){
                    t[i][j] = true;
                    cnt++;
                }
                else if(s[i] == s[j] && t[i+1][j-1] == true){
                    cnt++;
                    t[i][j] = true;
                }
                else{
                    t[i][j] = false;
                }
            }
        }
        return cnt;
    }
};