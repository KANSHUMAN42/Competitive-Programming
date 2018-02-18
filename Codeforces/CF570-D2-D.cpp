#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(6);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 5e5 + 10;
ll n, m, k, w;

int cnt[N][26];
int sz[N], lvl[N];
char col[N];
void getsz(int lv = 1, int v = 0, int p = 0){
	sz[v] = 1;
	lvl[v] = lv;
	for (auto u : adj[v]){
		if (u != p){
			getsz(lv + 1, u, v);
			sz[v] += sz[u];
		}
	}
}
void add(int v, int p, int x, int bigChild){
	cnt[lvl[v]][col[v] - 'a'] += x;
	for (auto u : adj[v]){
		if (u != p && u != bigChild){
			add(u, v, x, bigChild);
		}
	}
}
V<int> res;
V<V<pair<int, int> > > ans;
void dfs(int v = 0, int p = 0, int keep = 0){
	int mx = -1, bigChild = -1;
	for (auto u : adj[v])
		if (u != p && mx < sz[u])
			mx = sz[u], bigChild = u;

	for (auto u : adj[v])
		if (u != p && u != bigChild)
			dfs(u, v, 0);

	if (bigChild != -1)
		dfs(bigChild, v, 1);
	add(v, p, 1, bigChild);
	for (int i = 0; i < ans[v].size(); i++){
		int ok = 0;
		for (int j = 0; j < 26; j++){
			if (cnt[ans[v][i].first][j] & 1){
				ok++;
				if (ok > 1) break;
			}
		}
		if (ok <= 1) res[ans[v][i].second] = 1;
	}
	if (keep == 0)
		add(v, p, -1, p);
}
int main() {

	Emsawy();
	while (cin >> n >> m){
		ans.resize(n + 1);
		adj.resize(n + 1);
		for (int i = 2; i <= n; i++){
			cin >> k;
			adj[k].push_back(i);
		}
		getsz(1, 1, 1);
		for (int i = 1; i <= n; i++)
			cin >> col[i];
		int u, v;
		for (int i = 1; i <= m; i++){
			cin >> u >> v;
			ans[u].push_back(MP(v,i));
		}
		res.resize(m + 1);
		dfs(1, 1, 0);
		for (int i = 1; i <= m; i++){
			if (res[i]) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
	}

	return 0;
}
