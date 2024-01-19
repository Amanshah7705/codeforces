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

/*  
nam ordered_set aman;
aman.insert(x);
order find karva *(aman.find_by_order(x))--> ana vade index x medvava ama x 0 base 6;
 anathi nana find karva aman.order_of_key(x)
 */
 vector<vector<ll>>adj;
 vector<ll>vis;
 vector<ll>pare,dg;
 bool aman;
 vector<pair<ll,ll>>land;
 void dfs(ll v){
      if(aman){
           return;
      }
      pare[v]=1;
      for(auto &x:adj[v]){
           if(pare[x]==0){
                vis[x]=v;
                dfs(x);
           }
           else if(pare[x] == 1 && x != vis[v]){
                  vector<pair<ll,ll>>land1;
                  set<ll>sp;
                  land1.push_back({x,v});
                  ll trace=v;
               //    cout<<x<<" "<<v<<" ";
               //    dbg(vis);
               // cout<<x<<" "v<<" ";
                  while(trace != x){
                       ll dop=vis[trace];
                    //    cout<<dop<<" ";
                       land1.push_back({dop,trace});
                       trace=dop;
                  }
               //    cout<<endk;
                  for(auto &y:land1){
                       sp.insert(y.first);
                       sp.insert(y.second);
                  }
               //    dbg(sp);
                  queue<ll>q;
                  ll bc=0;
                  for(auto &y:sp){
                       q.push(y);
                  }
                  while(q.size()){
                       ll p=q.front();
                       q.pop();
                        bc=0;
                       for(auto &y:adj[p]){
                            if(sp.find(y) == sp.end()){
                                 bc++;
                            }
                       }
                       if(bc>=2){
                            bc=2;
                            for(auto &y:adj[p]){
                                 if(bc==0){
                                      break;
                                 }
                                 if(sp.find(y) == sp.end()){
                                      land1.push_back({p,y});
                                      bc--;
                                 }
                            }
                            bc=2;
                            break;
                       }
                  }
                  if(bc>=2){
                       land=land1;
                       aman=true;
                  }
           }
      }
      pare[v]=2;
 }
int main(){
     IOS
     string s1="YES",s2="NO";
     ll t;
     cin>>t;
     while(t--){
          ll n,m;
          cin>>n>>m;
          adj.clear();
          adj.resize(n+1);
          dg.clear();
          dg.resize(n+1);
          ll i;
          land.clear();
          pare.clear();
          vis.clear();
          pare.resize(n+1,0);
          vis.resize(n+1,-1);
          for(i=1;i<=m;i++){
               ll u,v;
               cin>>u>>v;
               dg[u]++;
               dg[v]++;
               adj[u].push_back(v);
               adj[v].push_back(u);
          }
           aman=false;
          for(i=1;i<=n;i++){
               if(aman){
                    break;
               }
               if(!pare[i]){
                    dfs(i);
               }
          }
          if(aman){
               cout<<s1<<endk;
               cout<<land.size()<<endk;
               for(auto &x:land){
                    cout<<x.first<<" "<<x.second<<endk;
               }
          }
          else{
               cout<<s2<<endk;
          }
     }
    
}