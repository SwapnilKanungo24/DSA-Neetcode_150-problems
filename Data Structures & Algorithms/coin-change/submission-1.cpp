#include<bits/stdc++.h>
class Solution {
public:
    int t[13][10000+1];
    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int n = coins.size();
        int m = amount;
        int INF = 1e9;
        //initialization 
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < m+1; j++){
                if(i == 0) t[i][j] = INF;
                if(j == 0) t[i][j] = 0;
            }
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(coins[i-1] <= j){
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]); 
                }
                else{
                    t[i][j] = t[i-1][j]; //nahi liya 
                }
            }
            if(t[n][m] == INF){
                return -1;
            }
        }
        return t[n][m];
    }
};