class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for(auto it : tokens){
            if(it == "+" || it == "-" || it == "/" || it == "*"){
                long long int x = st.top();
                st.pop();
                long long int y = st.top();
                st.pop();
                long long int ans = 0;
                if(it == "+")   ans = x + y;
                else if(it == "-")   ans = y - x;
                else if(it == "/")   ans = y / x;
                else   ans = y * x;
                st.push(ans);
            }
            else{
                long long int num = stoi(it);
                st.push(num);
            }
        }
        return st.top();
    }
};
