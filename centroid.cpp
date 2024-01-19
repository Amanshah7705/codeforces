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
 /* --------------------DUSRE KE CODE DEKHANA ACCHI BAT NAHI NAHI HE AB AAHI GAYE HOTO DEKHLO JARA-------------------- */
vector<ll>dx={-1,1,-1,1};
vector<ll>dy={-1,-1,1,1};
vector<vector<int>>adj;
vector<ll>centroids;
vector<bool>vis;
vector<ll>sz;
ll n;
void dfs(ll child){
    sz[child] = 1;
    vis[child] = true;
    bool is_centroid = true;
    for(auto ele:adj[child]){
        if(!vis[ele]) {
            dfs(ele);
            sz[child] += sz[ele];
            // cout<<ele<<" "<<sz[ele]<<endl;
            if(sz[ele] > (n/2)) is_centroid = false;
        }
    }
    if((n - sz[child]) > (n/2)) is_centroid = false;
    if(is_centroid) centroids.push_back(child);
}
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        // ll n;
        cin>>n;
        adj.clear();
        sz.clear();
        sz.resize(n+1,0);
        adj.resize(n+1);
        centroids.clear();
        vis.clear();
        vis.resize(n+1,false);
        ll i;
        for(i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            // u--;
            // v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         dfs(1);
        //  dbg(centroids);
      if(centroids.size() == 1){
          cout<<centroids[0]<<" "<<adj[centroids[0]][0]<<endk;
          cout<<centroids[0]<<" "<<adj[centroids[0]][0]<<endk;
      }
      else{
          for(auto x:adj[centroids[0]]){
              if(x != centroids[1]){
                  cout<<centroids[0]<<" "<<x<<endk;
                  cout<<centroids[1]<<" "<<x<<endk;
                  break;
              }
          }
      }
    }
      
}