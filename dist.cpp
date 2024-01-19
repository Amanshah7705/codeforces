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
const ll N=1e5+10;
vector<vector<ll>>adj(N);
const ll ju=20;
ll dp[N][ju];
bool vis[N];
ll lev[N];
ll n;
void dfs(ll v)
{
    vis[v]=true;
    for(auto x:adj[v])
    {
        if(!vis[x])
        {
            lev[x]=lev[v]+1;
            dp[x][0]=v;
            dfs(x);
        }
    }
}
void binary_lifting()
{
    ll i,j;
    for(i=1;i<ju;i++)
    {
        for(j=1;j<=n;j++)
        {
         if(dp[j][i-1] != -1)
         {
             dp[j][i]=dp[dp[j][i-1]][i-1];
         }
        }
    }
}
ll knt(ll u, ll k)
{
    if(k>lev[u])
    {
        return (-2);
    }
    ll i;
    for(i=0;i<ju;i++)
    {
        if((k &(1LL<<i)))
        {
            u=dp[u][i];
        }
    }
    return u;
}
ll anc(ll u,ll v)
{
    if(lev[u]<lev[v])
    {
        swap(u,v);
    }
    u=knt(u,lev[u]-lev[v]);
    if(u==v)
    {
        return u;
    }
    ll i;
    for(i=ju-1;i>=0;i--)
    {
        ll n1=dp[u][i];
        ll n2=dp[v][i];
        if(n1!= n2)
        {
            u=n1;
            v=n2;
        }
    }
    return dp[u][0];
}
ll dis(ll u,ll v)
{
    ll aman=lev[u]+lev[v]-2*lev[anc(u,v)];
    return aman;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(i=2;i<=n;i++)
    {
         ll u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
    dfs(1);
    memset(vis,false,sizeof(vis));
    binary_lifting();
   while(k--)
   {
       ll u,v;
       cin>>u>>v;
       ll lord=dis(u,v);
       cout<<lord<<endl;
   }
}
