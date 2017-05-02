// Scores 50 points

#include <bits/stdc++.h>
#include "boxes.h"

using namespace std;

#define ll long long

long long delivery(int N, int K, int L, int p[]) {
	int l = (L%2) ? L/2 : (L/2)-1;
	int r = (L%2) ? l+1 : l+2;
	r = min(r, L-1);
	ll result;

	cerr << "N:" << N << " K:" << K << " L:" << L << endl;
	cerr << L << ": " << l << " " << r << endl;
	for(int xx = 0; xx < 1; xx++) {
		vector<int> lSou, rSou;

		vector<int> remaining;
		for(int i = N-1; i >= 0; i--) {
			if(p[i]>0 && p[i]<=l) lSou.push_back(p[i]);
			if(L%2==0 && p[i]==L/2) {
				remaining.push_back(p[i]);
			}
		}
		for(int i = 0; i < N; i++) {
			if(p[i]>=r) rSou.push_back(p[i]);
		}

		//cerr << lSou.size() << endl;
//		for(auto i: lSou) //cerr << i << " ";
		//cerr << endl;
		//cerr << rSou.size() << endl;
//		for(auto i: rSou) //cerr << i << " ";
		//cerr << endl;


		ll ans = 0;
		while(lSou.size()>=K) {
			for(int i = 0; i < K-1; i++) lSou.pop_back();
			ans+=lSou.back()*2;
			lSou.pop_back();
		}
		while(rSou.size()>=K) {
			for(int i = 0; i < K-1; i++) rSou.pop_back();
			ans+=(L-rSou.back())*2;
			rSou.pop_back();
		}

		cerr << ans << endl << endl;
		cerr << remaining.size() << " " << lSou.size() << " " << 
rSou.size() << endl;

		if(remaining.size()||lSou.size()||rSou.size()) {
			if(remaining.size()+lSou.size() == 0) {
				ans+=(L-rSou[0])*2;
			} else if(remaining.size()+rSou.size() == 0) {
				ans+=lSou[0]*2;
			} else 
if(remaining.size()+lSou.size()+rSou.size()<=K) {
				if(remaining.size()>0)
					ans+=L;
				else
					ans+=min(L, 
(lSou[0]*2)+((L-rSou[0])*2));
			} else {
				int x = 
(remaining.size()+lSou.size()+rSou.size())-K;
				int smallerSide = L;
				if(lSou.size()>x) {
					smallerSide = min(smallerSide, 
lSou[lSou.size()-1-x]*2);
				}
				if(rSou.size()>x) {
					smallerSide = min(smallerSide, 
(L-rSou[rSou.size()-1-x])*2);
				}
				cerr << lSou[0] << " - " << lSou[0]*2 << 
endl;
				cerr << rSou[0] << " - " << 
(L+1-rSou[0])*2 << endl;
				if(remaining.size()==0)
					ans+=min(L+smallerSide, 
(lSou[0]*2)+((L-rSou[0])*2));
				else
					ans += L+smallerSide;
			}
		}
		result = ans;
		cerr << ans << endl << endl;
	}
	cerr << endl;
	//cerr << endl;

	for(int xx = 0; xx < 1; xx++) {
		vector<int> lSou, rSou;

		vector<int> remaining;
		for(int i = N-1; i >= 0; i--) {
			if(p[i]>0 && p[i]<=l) lSou.push_back(p[i]);
			if(L%2==0 && p[i]==L/2) {
				remaining.push_back(p[i]);
			}
		}
		for(int i = 0; i < N; i++) {
			if(p[i]>=r) rSou.push_back(p[i]);
		}
		reverse(lSou.begin(), lSou.end());
		reverse(rSou.begin(), rSou.end());

		//cerr << lSou.size() << endl;
//		for(auto i: lSou) //cerr << i << " ";
		//cerr << endl;
		//cerr << rSou.size() << endl;
//		for(auto i: rSou) //cerr << i << " ";
		//cerr << endl;


		ll ans = 0;
		while(lSou.size()>=K) {
			ans+=lSou.back()*2;
			lSou.pop_back();
			for(int i = 0; i < K-1; i++) lSou.pop_back();
		}
		while(rSou.size()>=K) {
			ans+=(L-rSou.back())*2;
			rSou.pop_back();
			for(int i = 0; i < K-1; i++) rSou.pop_back();
		}
		reverse(lSou.begin(), lSou.end());
		reverse(rSou.begin(), rSou.end());

		cerr << ans << endl << endl;
		cerr << remaining.size() << " " << lSou.size() << " " << 
rSou.size() << endl;

		if(remaining.size()||lSou.size()||rSou.size()) {
			if(remaining.size()+lSou.size() == 0) {
				ans+=(L-rSou[0])*2;
			} else if(remaining.size()+rSou.size() == 0) {
				ans+=lSou[0]*2;
			} else 
if(remaining.size()+lSou.size()+rSou.size()<=K) {
				if(remaining.size()>0)
					ans+=L;
				else
					ans+=min(L, 
(lSou[0]*2)+((L-rSou[0])*2));
			} else {
				int x = 
(remaining.size()+lSou.size()+rSou.size())-K;
				int smallerSide = L;
				if(lSou.size()>x) {
					smallerSide = min(smallerSide, 
lSou[lSou.size()-1-x]*2);
				}
				if(rSou.size()>x) {
					smallerSide = min(smallerSide, 
(L-rSou[rSou.size()-1-x])*2);
				}
				cerr << lSou[0] << " - " << lSou[0]*2 << 
endl;
				cerr << rSou[0] << " - " << 
(L+1-rSou[0])*2 << endl;
				if(remaining.size()==0)
					ans+=min(L+smallerSide, 
(lSou[0]*2)+((L-rSou[0])*2));
				else
					ans += L+smallerSide;
			}
		}
		result = min(result, ans);
		cerr << ans << endl << endl;
	}



	return result;
}
