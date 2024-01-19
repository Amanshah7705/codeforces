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
 vector<ll>siv,next1;
 ll N=1e5+1;
 vector<vector<ll>>bts;
 void sev(){
      ll i,j;
      siv.resize(N+1,1);
      bts.resize(N+1);
      for(i=2;i<=N;i++){
           if(siv[i]){
                for(j=2*i;j<=N;j+=i){
                     siv[j]=0;
                     bts[j].push_back(i);
                }
           }
           bts[i].push_back(i);
      }
 }
int main(){
     IOS
     string s1="YES",s2="NO";
     ll n;
     cin>>n;
     ll k;
     ll j;
     next1.resize(N+1,n);
     cin>>k;
     vector<ll>a(n);
     ll i;
     sev();
     for(i=0;i<n;i++){
          cin>>a[i];
     }
     vector<vector<ll>>dp(n+1,vector<ll>(22));
     for(i=0;i<22;i++){
          dp[n-1][i]=n;
          dp[n][i]=n;
     }
     for(i=n-1;i>=0;i--){
          dp[i][0]=dp[i+1][0];
          for(auto &x:bts[a[i]]){
               dp[i][0]=min(dp[i][0],next1[x]);
               next1[x]=i;
          }
     }
     for(i=1;i<22;i++){
          for(j=n-2;j>=0;j--){
               dp[j][i]=dp[dp[j][i-1]][i-1];
          }
     }
     while(k--){
          ll l,r;
          cin>>l>>r;
          l--;
          r--;
          ll ans=0;
          for(i=21;i>=0;i--){
               if(dp[l][i]<=r){
                    ans+=(1LL<<i);
                    l=dp[l][i];
               }
          }
          cout<<ans+1<<endk;
     }
}