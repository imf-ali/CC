#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE() 	freopen("input.txt", "r", stdin); \
						freopen("output.txt", "w", stdout)
#define int 			long long int 
#define pii 			pair<int,int>	
#define vi 				vector<int>
#define vii				vector<pii>
#define vvi             vector<vector<int>>
#define endl			"\n"
#define debug(...)      __f (#__VA_ARGS__, __VA_ARGS__)
#define FASTIO			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define print(a)		for(auto it : a) cout<<it<<" ";	cout<<endl;
#define printpii(a)		for(auto it : a) cout<<it.first<<" "<<it.second<<", ";	cout<<endl;


// ----------DEBUGGING CODE----------
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
// ----------DEBUGGING CODE----------


int tsp(vector<vector<int>> dist, int setOfCities, int city, int n, vvi &dp){

    if(setOfCities == (1<<n)-1){
        return dist[city][0];
    }

    if(dp[setOfCities][city] != -1)
        return dp[setOfCities][city];

    int ans = INT_MAX;
    for(int choice = 0; choice < n ; choice++){
        if(!(setOfCities & (1<<choice))){
            int subProb = dist[city][choice] + tsp(dist, (setOfCities | (1<<choice)), choice, n, dp);
            ans = min(ans, subProb);
        }
    }
    return dp[setOfCities][city] = ans;
}


int32_t main(){

	ONLINE_JUDGE();

    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };

    int setOfCities = (1<<4);

    vvi dp(setOfCities, vi (4, -1));

    int x = tsp(dist, 0, 0, 4, dp);
    cout<<x<<endl;

	return 0;
}
