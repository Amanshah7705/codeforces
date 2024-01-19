

// question : https://www.codechef.com/JAN231B/problems/COUNTING
//  yog-gan gechd gan no niyam 
// eki plus and beki minus

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
/*    ordered_set ma insert karva
nam ordered_set aman;
aman.insert(x);
order find karva *(aman.find_by_order(x))--> ana vade index x medvava ama x 0 base 6;
 anathi nana find karva aman.order_of_key(x)
 */
vector<ll>dx={-1,1,-1,1};
vector<ll>dy={-1,-1,1,1};
const ll N=3*1e5;
const ll mod=pow(10,9)+7;
vector<ll>po(10,1);
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll x,y,i;
   ll a,b;
   cin>>x>>y>>a>>b;
   vector<ll>dp;
//   ll i;
   ll fx=x;
   for(i=2;i*i<=fx;i++){
       ll op=0;
       while(fx%i==0){
           fx/=i;
           op++;
       }
       if(op){
           dp.push_back(i);
       }
   }
   if(fx>1){
       dp.push_back(fx);
   }
   ll m=dp.size();
   ll ans=0;
   for(i=1;i<(1LL<<m);i++){
       ll ola=1;
       ll jp=0;
       ll j;
       for(j=0;j<m;j++){
           if((1LL<<j)&i){
               ola*=dp[j];
               jp++;
           }
       }
       if(jp&1){
           ans+=b/ola-(a-1)/ola;
       }
       else{
           ans-=(b/ola-(a-1)/ola);
       }
   }
   dp.clear();
   fx=y;
    for(i=2;i*i<=fx;i++){
       ll op=0;
       while(fx%i==0){
           fx/=i;
           op++;
       }
       if(op){
           dp.push_back(i);
       }
   }
   if(fx>1){
       dp.push_back(fx);
   }
    m=dp.size();
   for(i=1;i<(1LL<<m);i++){
       ll ola=1;
       ll jp=0;
       ll j;
       for(j=0;j<m;j++){
           if((1LL<<j)&i){
               ola*=dp[j];
               jp++;
           }
       }
       if(jp&1){
           ans+=b/ola-(a-1)/ola;
       }
       else{
           ans-=(b/ola-(a-1)/ola);
       }
   }
   dp.clear();
   fx=(x*y)/__gcd(x,y);
    for(i=2;i*i<=fx;i++){
       ll op=0;
       while(fx%i==0){
           fx/=i;
           op++;
       }
       if(op){
           dp.push_back(i);
       }
   }
   if(fx>1){
       dp.push_back(fx);
   }
    m=dp.size();
   for(i=1;i<(1LL<<m);i++){
       ll ola=1;
       ll jp=0;
       ll j;
       for(j=0;j<m;j++){
           if((1LL<<j)&i){
               ola*=dp[j];
               jp++;
           }
       }
       if(jp&1){
           ans-=b/ola-(a-1)/ola;
       }
       else{
           ans+=(b/ola-(a-1)/ola);
       }
   }
   cout<<(b-a+1)-ans<<endk;
}  
      