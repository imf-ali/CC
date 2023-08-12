class Solution {
public:
    string search(string word, set<string> &st){
        string temp = "";
        for(int i=0;i<word.size();i++){
            temp += word[i];
            if(st.find(temp) != st.end())
                return temp;
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st;
        for(auto it : dictionary)
            st.insert(it);
        
        string res = "";
        string word = "";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i] == ' '){
                res += search(word,st);
                res += " ";
                word = "";
            }
            else word += sentence[i];
        }
        res += search(word,st);
        return res;
    }
};
