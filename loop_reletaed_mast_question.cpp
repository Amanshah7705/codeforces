
// link:https://atcoder.jp/contests/abc280/tasks/abc280_f

#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set_pair tree<pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>
#define ordered_mutliset_pair tree<pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
#define ll long long int
#define dbg(x) cout << #x << " -> "; ppp(x); cout<<endl
#pragma GCC optimize("Ofast")
#define mere_pas_ek_scheme_he_21_din_me_rating_double ios_base::sync_with_stdio(false);cin.tie(NULL);
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
/*    ordered_set ma insert karva
nam ordered_set aman;
aman.insert(x);
order find karva *(aman.find_by_order(x))--> ana vade index x medvava ama x 0 base 6;
 anathi nana find karva aman.order_of_key(x)
 */
 vector<ll>parent,szn;
 void make(ll n){
     ll i;
     for(i=1;i<=n;i++){
         parent[i]=i;
         szn[i]=1;
     }
 }
 vector<vector<pair<ll,ll>>>adj;
 ll fset(ll v){
     if(parent[v]==v){
         return v;
     }
     return parent[v]=fset(parent[v]);
 }
 void uni(ll a,ll b){
     ll x=fset(a);
     ll y=fset(b);
     if(x!=y){
         if(szn[x]<szn[y]){
             swap(x,y);
         }
         parent[y]=x;
         szn[x]+=szn[y];
     }
 }
int main()
{
    mere_pas_ek_scheme_he_21_din_me_rating_double
    string s1="Yes",s2="No";
    ll n,m,k;
    cin>>n>>m>>k;
    parent.resize(n+1);
    szn.resize(n+1);
    make(n);
    ll i;
    adj.resize(n+1);
    for(i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,-w});
        uni(u,v);
    }
    vector<ll>dis(n+1,0),vis(n+1,0),loop(n+1,0);
    for(i=1;i<=n;i++){
        if(fset(i)==i){
            queue<ll>q;
            q.push(i);
            while(q.size()>0){
                ll p=q.front();
                q.pop();
                for(auto &x:adj[p]){
                    if(!vis[x.first]){
                        vis[x.first]=1;
                        dis[x.first]=dis[p]+x.second;
                        q.push(x.first);
                    }
                    else{
                        if(dis[x.first]!=dis[p]+x.second){
                            loop[i]=true;
                        }
                    }
                }
            }
        }
    }
    while(k--){
        ll u,v;
        cin>>u>>v;
        if(fset(u) != fset(v)){
            cout<<"nan"<<endk;
        }
        else if(loop[fset(u)]){
            cout<<"inf"<<endk;
        }
        else{
            cout<<dis[v]-dis[u]<<endk;
        }
    }
}
 