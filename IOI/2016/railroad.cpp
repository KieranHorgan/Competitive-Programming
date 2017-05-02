// Scores 34 points

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1ll<<60

ll plan_roller_coaster(vector<int> s, vector<int> t) {
	int n = s.size();
	vector<vector<ll>> totalLen(1<<n, vector<ll>(n, 0));
	for(ll mask = 0; mask < (1<<n); mask++) {
		for(ll i = 0; i < n; i++) {
			if(mask == 1<<i) {
				totalLen[mask][i]=0;
			} else if(mask & (1<<i)) {
				totalLen[mask][i]=INF;
				for(ll j = 0; j < n; j++) {
					if((mask^(1<<i)) & (1<<j)) {
						totalLen[mask][i] = min(totalLen[mask][i], totalLen[mask^(1<<i)][j]+max(0,t[i]-s[j]));
					}
				}
			}
		}
	}

	ll ans = INF;
	for(ll i = 0; i < n; i++) ans = min(ans, totalLen[(1<<n)-1][i]);
	return ans;
}
