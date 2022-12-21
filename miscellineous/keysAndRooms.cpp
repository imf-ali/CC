class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int p, vector<bool> &vis){
        vis[p] = true;

        for(auto it : rooms[p]){
            if(!vis[it])
                dfs(rooms,it,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        dfs(rooms,0,vis);

        for(auto it : vis){
            if(!it)
                return false;
        }
        return true;
    }
};
