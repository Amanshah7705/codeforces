#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<ll, ll>, null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update>
#define ordered_mutliset_pair tree<pair<ll, ll>, null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
#define ll  long long int
#define dbg(x) cout << #x << " -> "; ppp(x); cout<<endl
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define endk '\n'
void ppp(int a)          { cout<<a; }
void ppp(ll a)           { cout<<a; }
void ppp(long double a)  { cout<<a; }
void ppp(double a)       { cout<<a; }
void ppp(char a)         { cout<<a; }
void ppp(string a)       { cout<<a; }
void ppp(bool a)         { cout<<a; }
//   priority_queue<ll,vector<ll>,greater<ll>>q;
template<class T , class V> void ppp(pair<T,V> p) {cout<<"{"; ppp(p.ff); cout<<','; ppp(p.ss); cout<<"}";}
template<class T> void ppp(vector<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
template<class T> void ppp(set<T> v){cout<<"[ ";for(T x:v) ppp(x) , cout<<" ";cout<<']';}
template<class T, class V> void ppp(map<T,V> m){cout<<endl;for(auto x:m){ppp(x.ff);cout<<" -> ";ppp(x.ss);cout<<endl;}cout<<endl;}
template<class T> void ppp(deque<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL);
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
/*    orj8j8jdered_set ma insert karva
nam ordered_set aman;
aman.insert(x);
order find karva *(aman.find_by_order(x))--> ana vade index x medvava ama x 0 base 6;
 anathi nana find karva aman.order_of_key(x)
 */
// TREAP OPERATIONS
ll cnt; // ETT node for each edge
vector<ll>pri,par;
vector<vector<ll>>c;
ll getRoot(ll x) {  // get top node in ETT
	while (par[x]) x = par[x];
	return x;
}
void link(ll x, ll d, ll y) {  // set d-th child of x to y
	assert(x);
	assert(d == 0 || d == 1);
	assert(!c[x][d]), c[x][d] = y;
	if (y) assert(!par[y]), par[y] = x;
}
ll dis(ll x, ll d) {  // disconnected d-th child of x
	assert(x);
	assert(d == 0 || d == 1);
	ll y = c[x][d];
	c[x][d] = 0;
	if (y) assert(par[y] == x), par[y] = 0;
	return y;
}
pair<ll,ll> split(ll x) {  // x and everything to right goes in p.s
	// everything else goes in p.f
	pair<ll,ll> p = {dis(x, 0), x};
	while (par[x]) {
		ll y = par[x];
		if (c[y][0] == x) {
			dis(y, 0), link(y, 0, p.second), p.second = y;
		} else {
			assert(c[y][1] == x);
			dis(y, 1), link(y, 1, p.first);
			p.first = y;
		}
		x = y;
	}
	return p;
}

ll merge(ll x, ll y) {
	assert(!par[x] && !par[y]);
	if (!x || !y) return max(x, y);
	if (pri[x] > pri[y]) {
		ll X = dis(x, 1);
		link(x, 1, merge(X, y));
		return x;
	} else {
		ll Y = dis(y, 0);
		link(y, 0, merge(x, Y));
		return y;
	}
}

// ll getFirst(ll x) {
// 	if (!x) return 0;
// 	while (c[x][0]) x = c[x][0];
// 	return x;
// }
ll makeFirst(ll x) {  // rotate ETT of x such that x is first
	assert(x);
	pair<ll,ll> p = split(x);
	return merge(p.second, p.first);
}
void remFirst(ll x) {  // remove first node of ETT rooted at x
	assert(x && !par[x]);
	while (c[x][0]) x = c[x][0];
	ll y = dis(x, 1), p = par[x];
	if (p) dis(p, 0), link(p, 0, y);
}

// ETT OPERATIONS
vector<map<ll,ll>>adj;
ll makeEdge(ll a, ll b) {
	adj[a][b] = ++cnt;
	pri[cnt] = rng();
	return cnt;
}
ll reroot(ll x) {  // make edge beginning with x
	if (!adj[x].size()) return 0;
	return makeFirst(begin(adj[x])->second);
}
bool con(ll a, ll b) {
	if ((!adj[a].size()) || (!adj[b].size())) return 0;
	a = begin(adj[a])->second, b = begin(adj[b])->second;
	return getRoot(a) == getRoot(b);
}
void add(ll a, ll b) {  // connect A and B with edge
	ll ta = reroot(a), tb = reroot(b);
	if (ta || tb) assert(ta != tb);
	ll x = makeEdge(a, b), y = makeEdge(b, a);  // make two nodes for new edge
	merge(merge(ta, x), merge(tb, y));
}
void rem(ll a, ll b) {
	ll x = adj[a][b], y = adj[b][a];
	makeFirst(x);
	pair<ll,ll> p = split(y);  // assert(getFirst(p.f) == x && getFirst(p.s) == y);
	remFirst(p.first), remFirst(p.second);
	adj[a].erase(b), adj[b].erase(a);
}

int main() {
	ll n, m;
    cin>>n>>m;
        pri.clear();
        pri.resize(n+1);
        par.clear();
        par.resize(n+1);
        c.clear();
        c.resize(n+1,vector<ll>(2));
        adj.clear();
        adj.resize(n+1);
	while(m--){
		string s;
		ll a,b;
		cin>>s>>a>>b;
		if (s == "add") {
			add(a, b);
		} else if (s == "cut") {
			rem(a, b);
		} else {
			if (con(a, b))
            {
                cout<<"YES"<<endk;
            }
			else{
                cout<<"NO"<<endk;
            }
		}
	}
}
