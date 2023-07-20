class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto it : asteroids){
            if(it > 0)  st.push(it);
            else{
                if(st.empty() || (!st.empty() && st.top() < 0)){
                    st.push(it);
                    continue;
                }
                int temp;
                while(!st.empty()){
                    temp = st.top();
                    if(temp > 0 && temp <= abs(it))  st.pop();
                    if(temp > 0 && temp >= abs(it)) break;
                    if((st.empty() && temp != abs(it)) || temp < 0){
                        st.push(it);
                        break;
                    }
                }

            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};
