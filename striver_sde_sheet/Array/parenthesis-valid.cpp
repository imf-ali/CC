class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() & 1)
            return false;
        
        int unlocked=0, open=0, closed=0, unpair;
        for(int i=0;i<s.size();i++){
            if(locked[i] == '0')
                unlocked++;
            else if(s[i] == '(')
                open++;
            else if(s[i] == ')')
                closed++;
            unpair = closed - open;
            if(unlocked < unpair)
                return false;
        }

        unlocked=0, open=0, closed=0;
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i] == '0')
                unlocked++;
            else if(s[i] == '(')
                open++;
            else if(s[i] == ')')
                closed++;
            unpair = open - closed;
            if(unlocked < unpair)
                return false;
        }

        return true;
    }
};
