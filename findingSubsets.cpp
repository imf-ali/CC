#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE() 	freopen("input.txt", "r", stdin); \
						freopen("output.txt", "w", stdout)
#define int 			long long int 
#define pii 			pair<int,int>	
#define vi 				vector<int>
#define vii				vector<pii>
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

string overlay(int i,string s){
    string temp = "";

    int j = 0;
    while(i > 0){
        if(i & 1){
            temp+=s[j];
        }
        j++;
        i >>=1;
    }
    return temp;
}

void findingSubsets(string s){

    int n = s.size();
    int limit = 1<<n;

    vector<string> ans;

    for(int i=0; i< limit; i++){
        ans.push_back(overlay(i,s));
    }

    for(auto it: ans)
        cout<<it<<endl;
}


int32_t main(){

	ONLINE_JUDGE();

    string arr = "abc";
    // int n = arr.size();
    findingSubsets(arr);

	return 0;
}
