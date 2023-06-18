class Solution {
public:

    bool valid(string temp){
        stack<char> st;
        for(auto it : temp){
            if(it == '(')
                st.push(it);
            else{
                if(st.empty())  
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }

    void solve(vector<string> &res, string &temp, int n){

        if(temp.length() > 2*n){
            return ;
        }
        if(temp.size() == 2*n && valid(temp)){
            res.push_back(temp);
            return;
        }
        
        temp += "(";
        solve(res,temp,n);
        temp.pop_back();
        temp += ")";
        solve(res,temp,n);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp="(";
        solve(res,temp,n);
        return res;
    }
};
