// Scores 100 points

#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> find_subset(int lo, int hi, vector<int> w) {
	vector<pair<ll,ll>> v;
	for(int i = 0; i < w.size(); i++)
		v.push_back({w[i], i});

	sort(v.begin(), v.end());

	ll l = 0, r = 0;
	sort(v.begin(), v.end());
	ll sum = v[0].first;
	for(; sum<lo || sum>hi;) {
		if(sum>hi) {
			sum-=v[l].first;
			l++;
		}
		if(sum<lo) {
			r++;
			sum+=v[r].first;
		}
		if(r==w.size()) {
			return {};
		}
		if(l>r) {
			r=l;
			sum = v[l].first;
		}	}

	vector<int> result;
	for(int i = l; i <= r; i++) {
		result.push_back(v[i].second);
	}
	return result;
}
