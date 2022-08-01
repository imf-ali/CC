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

void get2NonRepeatingNos(int arr[],int n){

    int bit = 0;
    for(int i=0;i<n;i++){
        bit ^= arr[i];
    }

    int right_bit_set = (bit & ~(bit - 1));

    int x = 0;
    int y = 0;

    for(int i=0; i<n; i++){

        if(arr[i] & right_bit_set)
            x^=arr[i];
    }

    for(int i=0; i<n; i++){
        if(!(arr[i] & right_bit_set))
            y^=arr[i];
    }
    cout<<x<<" "<<y<<endl;
}


int32_t main(){

	ONLINE_JUDGE();

    int arr[] = { 2, 3, 7, 9, 11, 2, 3, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    get2NonRepeatingNos(arr, n);

	return 0;
}
