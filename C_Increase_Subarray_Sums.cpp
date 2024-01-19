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
#define cpp_int long long int
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
// vector<ll>dx={0,1,0,-1};
// vector<ll>dy={-1,0,1,0};
const ll N=3*1e5+1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
       ll n,k;
       cin>>n>>k;
       vector<ll>v(n+1,0);
       vector<ll>a;
       ll i,j;
       ll cum=0;
       for(i=1;i<=n;i++)
       {
           cin>>v[i];
           cum+=v[i];
       }
       //dbg(v);
       vector<ll>sufix(n+1,0);
       vector<ll>pre(n+1,0);
       for(i=1;i<=n;i++)
       {
           pre[i]=pre[i-1]+v[i];
       }
       dbg(pre);
       for(i=0;i<=n;i++)
       {
           ll low=1,high=1;
           ll sum=0,ans=0;
          while(high<n && low<n);
          {
              sum=(pre[high]-pre[low-1])+min(high-low+1,i)*k;
              ans=max(ans,sum);
              while(sum<0 && low<=high)
              {
                  sum-=v[low];
                  low++;
                  if(low != high)
                  {
                      ans =max(ans,sum+min(high-low+1,i)*k);
                  }
              }
              high++;
          }
          a.push_back(ans);
       }
       sort(a.begin(),a.end());
       for(auto x:a)
       {
           cout<<max(0LL,x)<<" ";
       }
       cout<<endk;
    }
}