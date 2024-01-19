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

/*    orj8j8jdered_set ma insert karva
nam ordered_set aman;
aman.insert(x);
order find karva *(aman.find_by_order(x))--> ana vade index x medvava ama x 0 base 6;
 anathi nana find karva aman.order_of_key(x)
 */
struct Node {
	ll x;
	Node *l = 0;
	Node *r = 0;
	Node *p = 0;
	bool rev = false;

	Node() = default;

	Node(ll v) { x = v; }

	void push() {
		if (rev) {
			rev = false;
			swap(l, r);
			if (l) l->rev ^= true;
			if (r) r->rev ^= true;
		}
	}

	bool is_root() { return p == 0 || (p->l != this && this != p->r); }
};

struct LCT {
	vector<Node> a;

	LCT(ll n) {
		a.resize(n + 1);
		for (ll i = 1; i <= n; ++i) a[i].x = i;
	}

	void rot(Node *c) {
		auto p = c->p;
		auto g = p->p;

		if (!p->is_root()) (g->r == p ? g->r : g->l) = c;

		p->push();
		c->push();

		if (p->l == c) {  // rtr
			p->l = c->r;
			c->r = p;
			if (p->l) p->l->p = p;
		} else {  // rtl
			p->r = c->l;
			c->l = p;
			if (p->r) p->r->p = p;
		}

		p->p = c;
		c->p = g;
	}

	void splay(Node *c) {
		while (!c->is_root()) {
			auto p = c->p;
			auto g = p->p;
			if (!p->is_root()) rot((g->r == p) == (p->r == c) ? p : c);
			rot(c);
		}
		c->push();
	}

	Node *access(ll v) {
		Node *last = 0;
		Node *c = &a[v];
		for (Node *p = c; p; p = p->p) {
			splay(p);
			p->r = last;
			last = p;
		}
		splay(c);
		return last;
	}

	void make_root(ll v) {
		access(v);
		auto *c = &a[v];
		if (c->l) c->l->rev ^= true, c->l = 0;
	}

	void link(ll u, ll v) {
		make_root(v);
		Node *c = &a[v];
		c->p = &a[u];
	}

	void cut(ll u, ll v) {
		make_root(u);
		access(v);
		if (a[v].l) {
			a[v].l->p = 0;
			a[v].l = 0;
		}
	}

	bool connected(ll u, ll v) {
		access(u);
		access(v);
		return a[u].p;
	}
};


int main() {
	IOS
    ll n,m;
    cin>>n>>m;

	LCT lc(n+1);

	while (m--) {
		string a;
		cin >> a;
		ll b, c;
		cin >> b >> c;
		if (a == "add") { lc.link(b, c); }

		if (a == "cut") { lc.cut(b, c); }

		if (a == "connect") {
			cout << (lc.connected(b, c) ? "YES" : "NO") << "\n";
		}
	}
}