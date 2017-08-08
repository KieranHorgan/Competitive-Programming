#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll n, m, k;
string grid[2000];
ll visited[2000][2000];
ll cycle = 0;

ll checkCycle(ll i, ll j) {
	if(i<0||i>=n) return 0;
	if(j<0||j>=m) return 0;
	if(grid[i][j]=='#'||grid[i][j]=='X') return 0;
	if(visited[i][j]) return 1;
	visited[i][j]=1;

	ll curr = 0;
	curr += checkCycle(i+1, j  );
	curr += checkCycle(i-1, j  );
	curr += checkCycle(i  , j+1);
	curr += checkCycle(i  , j-1);
	if(curr >= 2) cycle = 1;

	return 0;
}

int main() {
	ld result = 0;

	for(int test = 1; test <= 10; test++) {
		memset(grid,0,sizeof(grid));
		memset(visited,0,sizeof(visited));
		cycle = 0;

		string currTest;
		if(test<10) currTest = "0" + to_string(test);
		else currTest = to_string(test);
		
		ifstream ain("tests/"+currTest+".in");
		ifstream sin("sol1/"+currTest+".out");
		cerr << currTest << ": " << endl;
		ain >> n >> m >> k;
		cerr << n << " " << m << " " << k << endl;

		string s;
		int i = 0;
		while(sin >> s) {
			grid[i]=s;
			i++;
		}

		for(int i = 0; i < m; i++) {
			if(grid[0][i]=='.') {
				checkCycle(0,i);
				break;
			}
		}
		if(cycle) {
			cerr << "CYCLE DETECTED\n";
			continue;
		}

		bool allVisited = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(grid[i][j]=='.')
					if(!visited[i][j]) {
						cerr << grid[i-1][j] << " " << i << " " << j << "  ";
						allVisited=0;
					}

		if(allVisited==0) {
			cerr << "NOT ALL VISITED\n";
			continue;
		}

		ll hidingSpots = 0;

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(grid[i][j]=='.') {
					ll x = 0;
					if(i<n-1) x += grid[i+1][j  ]=='.'?1:0;
					if(i>0  ) x += grid[i-1][j  ]=='.'?1:0;
					if(j<m-1) x += grid[i  ][j+1]=='.'?1:0;
					if(j>0  ) x += grid[i  ][j-1]=='.'?1:0;
					if(x==1) hidingSpots++;
				}
			}
		}

		hidingSpots = min(hidingSpots, k);

		cout << setprecision(5);
		cerr << "\t" << (ld)hidingSpots/k*100 << endl;

		result += (ld)hidingSpots/k*10;

		ain.close();
		sin.close();
	}

	cout << "RESULT: " << result << endl;
}