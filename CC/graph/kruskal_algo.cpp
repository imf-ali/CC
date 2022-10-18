#include<bits/stdc++.h>
using namespace std;
#define int 			long long int 
#define pii 			pair<int,int>	
#define vi 				vector<int>
#define vii				vector<pii>
#define endl			"\n"
#define debug(...)       	__f (#__VA_ARGS__, __VA_ARGS__)
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

void init(int root[],int rank[],int n){
	for(int i=0;i<n;i++){
		root[i] = i;
		rank[i] = 1;
	}
}

int find(int v, int root[]){
	if (v == root[v])
        return v;
    return root[v] = find(root[v],root);
}

void Union(int a,int b,int root[],int rank[], string &s){
	int x = find(a,root);
	int y = find(b,root);

	if(s[x] == 'R' || s[y] == 'R'){
		s[x] = 'R';
		s[y] = 'R'; 
	}

	if(rank[x] > rank[y]){
		root[y] = root[x];
		rank[x] += rank[y];
	}
	else{
		root[x] = root[y];
		rank[y] += rank[x];
	}
}

void kruskalMST(pair<int,pii> edges[],int m,int n,string s){

	int root[n],rank[n];

	init(root,rank,n);
	sort(edges,edges + m);

	int ans = 0;

	// for(int i=0;i<n;i++){
	// 	cout<<find(i,root)<<endl;
	// }

	for(int i = 0;i<m;i++){
		int wt = edges[i].first;
		int x = edges[i].second.first;
		int y = edges[i].second.second;

		if(wt <= 0){

			Union(x,y,root,rank,s);
			ans += wt;
		}

		int a = find(x,root);
		int b = find(y,root);

		if((s[a] == 'H' || s[b] == 'H') && (a != b)){
			Union(x,y,root,rank,s);
			ans += wt;
		}
	}

	cout<<ans<<endl;
}

void solve(){
	int n,m;
	cin>>n>>m;

	string s;
	cin>>s;

	pair<int,pii> edges[m];

	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edges[i] = {z, {x-1,y-1}};
	}

	kruskalMST(edges,m,n,s);
}

int32_t main(){
	
	int t=1;
	cin>>t;

	while(t--)	solve();
	return 0;
}
