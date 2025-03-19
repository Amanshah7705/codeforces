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
ll N=20;
ll bita = (1LL<<N);
vector<ll>dp1(bita+1,0),dp2(bita+1,0);
void forword1(){
    // for x | y = x
    ll i,j;
      for(i=0;i<N;i++){
          for(j=0;j<bita;j++){
              bool ok = (1LL<<i)&j;
              if(ok){
                 dp1[j] += dp1[j ^ (1LL<<i)];
              }
          }
      }
}
void forword2(){
    ll i,j;
    // for x & y = x
    for(i=0;i<N;i++){
        for(j=0;j<bita;j++){
            bool ok = (1LL<<i)&j;
            if(ok){
               dp2[j ^ (1LL<<i)] += dp2[j];
            }
        }
    }
}
void backword1(){
    ll i,j;
      for(i=0;i<N;i++){
          for(j=0;j<bita;j++){
              bool ok = (1LL<<i)&j;
              if(ok){
                 dp1[j] -= dp1[j ^ (1LL<<i)];
              }
          }
      }
}

void backword2(){
    ll i,j;
    // for x & y = x
    for(i=0;i<N;i++){
        for(j=0;j<bita;j++){
            bool ok = (1LL<<i)&j;
            if(ok){
               dp2[j ^ (1LL<<i)] -= dp2[j];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1="YES",s2="NO";
    ll n;
    cin>>n;
    vector<ll>a(n);
    ll i;
    for(i=0;i<n;i++){
        cin>>a[i];
        dp1[a[i]]++;
        dp2[a[i]]++;
    }
    forword1();
    forword2();
    for(auto &x:a){
        ll moka = (bita - 1) ^ x;

        cout<<dp1[x]<<" "<<dp2[x]<<" "<<n-dp1[moka]<<endk;
    }
}
 