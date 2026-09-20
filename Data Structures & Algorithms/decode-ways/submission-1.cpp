#include<bits/stdc++.h>
class Solution {
public:
    int t[101];
    int solve(string s, int i, int n){
        if(t[i] != -1){
            return t[i]; //state definition => it contain no. of ways of split on that index 
        }

        if(i == n) {
            return t[i] = 1;
        }
        if(i < n && s[i] == '0') return t[i] = 0;

        int oneSplit = solve(s, i+1, n);

        int secSplit = 0;
        if(i+1 < n){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
            secSplit = solve(s, i+2, n);
            }
        }

        return t[i] = oneSplit + secSplit;
    }
    int numDecodings(string s) {
        memset(t, -1, sizeof(t));
        int n = s.length();
        return solve(s, 0, n);
    }
};