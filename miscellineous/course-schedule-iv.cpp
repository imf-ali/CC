class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it : prerequisites){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        vector<vector<bool>> check(numCourses,vector<bool>(numCourses,false));
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                check[node][it] = true;
                for(int i=0;i<numCourses;i++){
                    if(check[i][node])
                        check[i][it] = true;
                }
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }
        vector<bool> res;
        for(auto it : queries){
            if(check[it[0]][it[1]])
                res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
