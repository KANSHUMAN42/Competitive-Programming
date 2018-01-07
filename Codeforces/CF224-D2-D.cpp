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

V<V<pair<int,int> > > adj;
int n, m, k, w, h;
struct Node{
	V<int> ord;
	int cnt;
	Node(){
		ord = V<int>(26, -1);
		cnt = 0;
	}
	void Add(V<int>&v){
		ord = v;
	}
};

int main() {

	Emsawy();
	string a, b;
	while (cin >> a >> b){
		V<Node> L(a.size()), R(a.size());

		int po = 0;
		for (int i = 0; i < a.size(); i++){
			if (i > 0) L[i].Add(L[i - 1].ord);
			if (po < b.size() && b[po] == a[i]){
				L[i].ord[b[po]-'a'] = i;
				po++;
			}
			L[i].cnt = po;
		}
		po = b.size() - 1;
		for (int i = a.size() - 1; i >= 0; i--){
			if (i < a.size() - 1) R[i].Add(R[i + 1].ord);
			if (po >= 0 && b[po] == a[i]){
				R[i].ord[b[po]-'a'] = i;
				po--;
			}
			R[i].cnt = b.size() - po - 1;
		}
		bool ok = 1;
		for (int i = 0; i < a.size(); i++){
			int pl = L[i].ord[a[i] - 'a'];
			int pr = R[i].ord[a[i] - 'a'];
			if (pl == -1 && pr == -1){
				ok = 0;
				break;
			}
			int mx = 0;
			if (pl != -1){
				mx = max(mx, L[pl].cnt + R[i].cnt);
			}
			if (pr != -1){
				mx = max(mx, R[pr].cnt + L[i].cnt);
			}
			if (mx < b.size()){
				ok = 0;
				break;
			}
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
