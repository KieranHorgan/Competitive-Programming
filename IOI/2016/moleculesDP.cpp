// Scores 31 points

#include <bits/stdc++.h>

using namespace std;

#define ll int

vector<ll> ans;
vector<ll> w;
bool dp[10005][10005];
ll l, u, n;

bool knapsack(ll i, ll remaining) {
	if(dp[i][remaining]) return 0;
	if(remaining<0) return dp[i][remaining]=1,0;
	if(remaining >= 0 && remaining <= u-l) {
		return 1;
	}
	if(i<n-1) {
		bool x = knapsack(i+1, remaining-w[i+1]);
		if(x) {
			ans.push_back(i+1);
			return 1;
		}
		x = knapsack(i+1, remaining);
		if(x) {
			return 1;
		}
	}
	return dp[i][remaining]=1,0;
}

vector<int> find_subset(int L, int U, vector<int> W) {
	l = L, u = U, n = W.size();
	w = W;
//	cout << l << " " << u << " " << n << endl;
	bool x = knapsack(0, u-w[0]);
	if(x) {
		ans.push_back(0);
	} else
		x = knapsack(0, u);
	
	for(auto i: ans) {
//		cout << i << " ";
	}
	return ans;
}
