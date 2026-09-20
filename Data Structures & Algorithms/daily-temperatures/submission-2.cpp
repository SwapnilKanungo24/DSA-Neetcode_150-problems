#include<bits/stdc++.h>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n,0);
        stack<int> st; //monotonic stack

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){ //deletion of element 
                st.pop();
            }
            if(st.empty())
            {
                st.push(i);
            }
            else{
                if(temperatures[st.top()] >= temperatures[i]){
                    answer[i] = st.top() - i;
                    st.push(i);
                }
            }
        }
        return answer;
    }
};