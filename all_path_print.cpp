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
template<class T , class V> void ppp(pair<T,V> p) {cout<<"{"; ppp(p.ff); cout<<','; ppp(p.ss); cout<<"}";}
template<class T> void ppp(vector<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
template<class T> void ppp(set<T> v){cout<<"[ ";for(T x:v) ppp(x) , cout<<" ";cout<<']';}
template<class T, class V> void ppp(map<T,V> m){cout<<endl;for(auto x:m){ppp(x.ff);cout<<" -> ";ppp(x.ss);cout<<endl;}cout<<endl;}
template<class T> void ppp(deque<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
#define nline endl
ll mod=pow(10,9)+7;
const ll N=1001;
vector<vector<ll>>adj(N);
vector<vector<ll>>dis(N,vector<ll>(N,mod));
bool vis[N];
void bfs(vector<ll>parent[],ll n,ll st)
{
    vector<ll>dis(n,INT_MAX);
    queue<ll>q;
    q.push(st);
    parent[st]={-1};
    dis[st]=0;
    while(q.size()>0)
    {
        ll p=q.front();
        q.pop();
        for(auto x:adj[p])
        {
            if(dis[x]>dis[p]+1)
            {
                dis[x]=1+dis[p];
                q.push(x);
                parent[x].clear();
                parent[x].push_back(p);
            }
            else if(dis[x]==1+dis[p])
            {
                parent[x].push_back(p);
            }
        }
    }
}
void find_path(vector<vector<ll>>&paths,vector<ll>&path,vector<ll>parent[],ll n,ll u)
{
    if(u == -1)
    {
        paths.push_back(path);
        return;
    }
    for(auto x:parent[u])
    {
        path.push_back(u);
        find_path(paths,path,parent,n,x);
        path.pop_back();
    }
}
void print_path(ll n,ll st,ll en)
{
    vector<vector<ll>>paths;
    vector<ll>path;
    vector<ll>parent[n];
    bfs(parent,n,st);
    find_path(paths,path,parent,n,en);
    for(auto x:paths)
    {
        reverse(x.begin(),x.end());
    }
    /// for print path ------------------------------------------------------------------------upper is-----------------------
    ll i,j;
    ll ans=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            ll aman=0,aman1=0,chaman=0;
            for(auto x:paths)
            {
                ll pre=-1,curr=-1;
                for(auto y:x)
                {
                    if(pre == -1)
                    {
                        pre =y;
                    }
                    else{
                        pre=curr;
                        curr=y;
                        if((pre ==i && curr == j)||(pre == j && curr==i))
                        {
                            chaman=1;
                        }
                    }
                    if(y == i)
                    {
                        aman=1;
                    }
                    if(y == j)
                    {
                        aman1=1;
                    }
                }
                if(aman1 && aman)
                {
                    continue;
                }
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll m,n,s,t;
cin>>n>>m>>s>>t;
s--;
t--;
ll i,k,j,l,r;
for(i=0;i<m;i++)
{
    ll u,v;
    cin>>u>>v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
ll src=s;
ll des=t;
print_path(n,src,des);
}