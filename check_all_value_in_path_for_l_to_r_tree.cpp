#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mutliset_pair tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
#define ll long long int
#define dbg(x)            \
    cout << #x << " -> "; \
    ppp(x);               \
    cout << endl
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define endk '\n'
void ppp(int a) { cout << a; }
void ppp(ll a) { cout << a; }
void ppp(long double a) { cout << a; }
void ppp(double a) { cout << a; }
void ppp(char a) { cout << a; }
void ppp(string a) { cout << a; }
void ppp(bool a) { cout << a; }
template <class T, class V>
void ppp(pair<T, V> p)
{
    cout << "{";
    ppp(p.ff);
    cout << ',';
    ppp(p.ss);
    cout << "}";
}
template <class T>
void ppp(vector<T> v)
{
    cout << "[ ";
    for (T x : v)
        ppp(x), cout << " ";
    cout << ']';
}
template <class T>
void ppp(set<T> v)
{
    cout << "[ ";
    for (T x : v)
        ppp(x), cout << " ";
    cout << ']';
}
template <class T, class V>
void ppp(map<T, V> m)
{
    cout << endl;
    for (auto x : m)
    {
        ppp(x.ff);
        cout << " -> ";
        ppp(x.ss);
        cout << endl;
    }
    cout << endl;
}
template <class T>
void ppp(deque<T> v)
{
    cout << "[ ";
    for (T x : v)
        ppp(x), cout << " ";
    cout << ']';
}
vector<ll> dx = {-1, 1, -1, 1};
vector<ll> dy = {-1, -1, 1, 1};
vector<vector<ll>> adj;
vector<vector<ll>> dp;
vector<bool> vis;
vector<ll> lev;
vector<ll> under;
vector<ll> bar;
set<ll> vachhe1;
set<ll> vachhe2;
vector<ll> col;
vector<ll> segment_tree;
vector<ll> segment;
ll n;
ll ttx = 1;
void dfs(ll v)
{
    under[v] = ttx;
    ttx++;
    vis[v] = true;
    for (auto x : adj[v])
    {
        if (!vis[x])
        {
            lev[x] = lev[v] + 1;
            dp[x][0] = v;
            dfs(x);
        }
    }
    bar[v] = ttx;
    ttx++;
}
void binary_lifting()
{
    ll i, j;
    for (i = 1; i < 21; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (dp[j][i - 1] != -1)
            {
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
            }
        }
    }
}
ll knt(ll u, ll k)
{
    if (k > lev[u])
    {
        return (-2);
    }
    ll i;
    for (i = 0; i < 21; i++)
    {
        if ((k & (1LL << i)))
        {
            u = dp[u][i];
        }
    }
    return u;
}
ll anc(ll u, ll v)
{
    if (lev[u] < lev[v])
    {
        swap(u, v);
    }
    u = knt(u, lev[u] - lev[v]);
    if (u == v)
    {
        return u;
    }
    ll i;
    for (i = 20; i >= 0; i--)
    {
        ll n1 = dp[u][i];
        ll n2 = dp[v][i];
        if (n1 != n2)
        {
            u = n1;
            v = n2;
        }
    }
    return dp[u][0];
}
ll dis(ll u, ll v)
{
    ll aman = lev[u] + lev[v] - 2 * lev[anc(u, v)];
    return aman;
}

ll query(ll node, ll st, ll en, ll l, ll r)
{
    if (st > r || en < l)
    {
        return 0;
    }
    if (l <= st && en <= r)
    {
        return segment_tree[node];
    }
    ll mid = (st + en) / 2;
    ll q1 = query(2 * node, st, mid, l, r);
    ll q2 = query(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
}
void update(ll node, ll st, ll en, ll index, ll value)
{
    if (st == en)
    {
        segment_tree[node] = value;
        return;
    }
    ll mid = (st + en) / 2;
    if (index <= mid)
    {
        update(2 * node, st, mid, index, value);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, index, value);
    }
    segment_tree[node] = (segment_tree[2 * node] + segment_tree[2 * node + 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1 = "Yes", s2 = "No";
    ll t;
    cin >> t;
    while (t--)
    {
        ttx = 1;
        adj.clear();
        dp.clear();
        vis.clear();
        lev.clear();
        under.clear();
        bar.clear();
        vachhe1.clear();
        vachhe2.clear();
        col.clear();
        segment.clear();
        segment.push_back(0);
        ll q;
        cin >> n >> q;
        adj.resize(n + 1);
        dp.resize(n + 1, vector<ll>(21, -1));
        lev.resize(n + 1, 0);
        vis.resize(n + 1, false);
        under.resize(n + 1, 0);
        bar.resize(n + 1, 0);
        col.resize(n + 1, 0);
        ll i;
        for (i = 1; i <= n; i++)
        {
            cin >> col[i];
        }
        for (i = 2; i <= n; i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        binary_lifting();
        ll big = *max_element(bar.begin(), bar.end());
        segment_tree.clear();
        segment_tree.resize((4 * big + 1), 0);
        segment.resize(big + 1, 0);
        ll tt = 0;
        for (i = 1; i <= n; i++)
        {
            segment[under[i]] = i;
            segment[bar[i]] = i;
            if (col[i] == 1)
            {
                tt++;
                update(1, 0, big, under[i], +1);
                update(1, 0, big, bar[i], -1);
                vachhe1.insert(under[i]);
                vachhe2.insert(bar[i]);
            }
        }
        while (q--)
        {
            ll x;
            cin >> x;
            if (col[x] == 1)
            {
                tt--;
                col[x] ^= 1;
                vachhe1.erase(under[x]);
                vachhe2.erase(bar[x]);
                update(1, 0, big, under[x], 0);
                update(1, 0, big, bar[x], 0);
            }
            else
            {
                tt++;
                col[x] ^= 1;
                vachhe1.insert(under[x]);
                vachhe2.insert(bar[x]);
                update(1, 0, big, under[x], +1);
                update(1, 0, big, bar[x], -1);
            }
            if (tt == 0)
            {
                cout << s2 << endk;
                continue;
            }
            ll l = *vachhe2.begin();
            ll r = *vachhe1.rbegin();
            l = segment[l];
            r = segment[r];
            if (l == r)
            {
                l = *vachhe1.begin();
                r = *vachhe1.rbegin();
                l = segment[l];
                r = segment[r];
                ll disx = dis(l, r);
                ll val = query(1, 0, big, under[l], under[r]);
                if (disx + 1 == val && val == tt)
                {
                    cout << s1 << endk;
                }
                else
                {
                    cout << s2 << endk;
                }
            }
            else
            {
                ll disx = dis(l, r);
                ll lift = anc(l, r);
                ll left = query(1, 0, big, under[lift], under[l]);
                ll right = query(1, 0, big, bar[r], bar[lift]);
                ll left_dis = dis(l, lift);
                ll right_dis = dis(lift, r);
                if ((left == left_dis + 1) && (abs(right) == right_dis + 1) && (left_dis + right_dis + 1 == tt))
                {
                    cout << s1 << endk;
                }
                else
                {
                    cout << s2 << endk;
                }
            }
        }
    }
}
