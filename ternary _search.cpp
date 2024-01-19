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
vector<ll>dx={1,0,0,1};
vector<ll>dy={0,1,1,0};
const ll N=2*1e5+1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1="YES",s2="NO";
   ll n,m;
   cin>>n>>m;
   vector<ll>a(n),b(m);
   ll i;
   for(i=0;i<n;i++){
       cin>>a[i];
    //   low=min(low,a[i]);
   }
   for(i=0;i<m;i++){
       cin>>b[i];
    //   high=max(high,b[i]);
   }
   ll ans=1e17;
  ll low=1,high=1e9;
   ll pre=-1,j;
  for(j=0;j<100;j++){
       ll mid1=low+(-low+high)/3;
       ll mid2=high-(-low+high)/3;
    //   if(mid2<mid1){
    //       break;
    //   }
       ll ans1=0,ans2=0;
       for(i=0;i<n;i++){
           ans1+=max(0LL,mid1-a[i]);
           ans2+=max(0LL,mid2-a[i]);
       }
       for(i=0;i<m;i++){
           ans1+=max(0LL,b[i]-mid1);
           ans2+=max(0LL,b[i]-mid2);
       }
       ans=min({ans,ans1,ans2});
       if(ans1<=ans2){
       high=mid2;
       }
       else{
          low=mid1;
       }
   }
   cout<<ans<<endk;
}