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

const int sz = 2;

struct Mat{
    int m[sz][sz];
    Mat(){
        memset(m,0,sizeof(m));
    }
    Mat operator * (Mat temp){
        Mat res;
        for (int i = 0; i < sz; i++){
            for(int j = 0; j <sz ; j++){
                for(int k = 0;k<sz ;k++){
                    res.m[i][j] += m[i][k]*temp.m[k][j];
                }
            }
        }
        return res;
    }
};

int fib(int n){
    if(n <= 2)
        return 1;

    n-=2;

    Mat T, res;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;
    res.m[0][0] = res.m[1][1] = 1;
    while(n){
        if(n & 1) res = res*T;
        T = T*T;
        n>>=1;
    }
    return res.m[0][0] + res.m[0][1];
}

int32_t main(){

	ONLINE_JUDGE();

    cout<<fib(6)<<endl;
	return 0;
}
