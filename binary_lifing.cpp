#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dbg(x) cout << #x << " -> "; ppp(x); cout<<endl
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(v) v.begin(), v.end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rep(i, m, n) for (int i = m; i < n; i++)
#define INF (ll)5e18
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
void __print(int x)
{
    cerr << x;
}
void ppp(int a)          { cout<<a; }
void ppp(ll a)           { cout<<a; }
void ppp(long double a)  { cout<<a; }
void ppp(double a)       { cout<<a; }
void ppp(char a)         { cout<<a; }
void ppp(string a)       { cout<<a; }
void ppp(bool a)         { cout<<a; } 
//   priority_queue<ll,vector<ll>,greater<ll>>q;
/*priority_queue<pair<ll,ll>>q;
map<pair<ll,ll>,ll>z;
vector<pair<ll,ll>>t;*/
template<class T , class V> void ppp(pair<T,V> p) {cout<<"{"; ppp(p.ff); cout<<','; ppp(p.ss); cout<<"}";}
template<class T> void ppp(vector<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
template<class T> void ppp(set<T> v){cout<<"[ ";for(T x:v) ppp(x) , cout<<" ";cout<<']';}
template<class T, class V> void ppp(map<T,V> m){cout<<endl;for(auto x:m){ppp(x.ff);cout<<" -> ";ppp(x.ss);cout<<endl;}cout<<endl;}
template<class T> void ppp(deque<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
const ll N=2*1e5+10;
vector<vector<ll>>adj(N);
const ll ju=log2(N);
ll dp[N][19];
bool vis[N];
void binary_lifing(ll v, ll parent)
{
    dp[v][0]=parent;
    ll i;
    vis[v]=true;
    for(i=1;i<ju;i++)
    {
        if(dp[v][i-1] != -1)
        {
            dp[v][i]=dp[dp[v][i-1]][i-1];
        }
        else
        {
            dp[v][i]=-1;
        }
    }
    for(auto x:adj[v])
    {
        if(!vis[x])
        {
            binary_lifing(x,v);
        }
    }
}
ll qr(ll node,ll jump)
{
    ll i;
    if(node == -1 || jump ==0)
    {
        return node;
    }
    for(i=ju-1;i>=0;i--)
    {
        if(jump>= (1LL<<(i)))
        {
            return qr(dp[node][i],jump-(1LL<<(i)));
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,k;
    cin>>n>>k;
    for(i=2;i<=n;i++)
    {
        ll x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    binary_lifing(1,-1);
    while(k--)
    {
        ll node,parent;
        cin>>node>>parent;
        cout<<qr(node,parent)<<endl;
    }
}
