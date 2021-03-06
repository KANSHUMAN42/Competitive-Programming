
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v) ((int)((v).size()))
#define V vector
#define MP make_pair
#define all(v)  ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(v, d) memset(v, d, sizeof(v))
#define sf(x) scanf("%d", &x)
#define sf2(x, y) scanf("%d %d", &x, &y)
#define sf3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfll(x) scanf("%I64d", &x)
#define sfll2(x, y) scanf("%I64d %I64d", &x, &y)
#define sfll3(x, y, z) scanf("%I64d %I64d %I64d", &x, &y, &z)
typedef long long ll;
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
ll suf(ll x) { return max(0LL, (x * (x + 1)) / 2); }
V<V<pair<int, int> > > adj;
const ll mod = (ll) 1e13 + 7, oo = (ll) 1e8;
ll n, m, k;

int main()
{
	
	Emsawy();
	int t,c = 0; cin >> t;
	while (t--){
		sf3(n, m, k);
		n *= n;
		ll ch = 1;
		for (int i = 0; i < m; i++){
			ch = (ch * (n - i)) % mod;
		}
		ll ans = 0;
		for (int i = m; i <= k; i++){
			ans = (ans + ch) % mod;
			ch = (ch * (n - i)) % mod;
		}
		printf("Case %d: %lld\n", ++c , ans);
	}
	return 0;
}
