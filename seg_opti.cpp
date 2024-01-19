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
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL);

/*    ordered_set ma insert karva
nam ordered_set aman;
aman.insert(x);
order find karva *(aman.find_by_order(x))--> ana vade index x medvava ama x 0 base 6;
 anathi nana find karva aman.order_of_key(x)
 */
 vector<ll>a;
 vector<ll>dp,segment_tree;
ll n;
void built(){
   ll i;
   for(i=0;i<n;i++){
    segment_tree[i+n]=dp[i];
   }
   for(i=n-1;i>0;i--){
    segment_tree[i]=max(segment_tree[i<<1],segment_tree[i<<1 | 1]);
   }
}
void update(ll index,ll val){
  segment_tree[index+n]=val;
  index+=n;
  ll i;
  for(i=index;i>1;i>>=1){
    segment_tree[i>>1]=max(segment_tree[i],segment_tree[i^1]);
  }
}
ll query(ll l,ll r){
    ll ans=-1e15;
    r++;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1){
            ans=max(ans,segment_tree[l++]);
        }
        if(r&1){
            ans=max(ans,segment_tree[--r]);
        }
    }
    return ans;
}
bool cmp(pair<ll,ll>&a,pair<ll,ll>&b){
      if(a.second == b.second){
           return a.first<b.first;
      }
      else{
           return a.second>b.second;
      }
}
int main(){
   IOS
   cin>>n;
   a=vector<ll>(n);
   dp=vector<ll>(n+1);
   segment_tree=vector<ll>(4*n+11);
   ll i;
   ll ola=0;
   for(i=0;i<n;i++){
        cin>>a[i];
   }
   vector<ll>prefix(n+1,0);
   for(i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i-1];
   }
   built();
   map<ll,ll>vp;
   for(i=0;i<=n;i++){
        vp[prefix[i]]=0;
   }
   ll cnt=1;
   for(auto &x:vp){
        x.second=cnt;
        cnt++;
   }
   update(vp[prefix[0]],dp[0]);
   for(i=1;i<=n;i++){
        ll qu=query(0,vp[prefix[i]]-1);
        dp[i]=max(dp[i-1],i+qu);
        update(vp[prefix[i]],dp[i]-i);
   }
   cout<<dp[n];
   
}