#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
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
struct segment
{
    vector<ll> tree;
    ll n;
    void build(vector<ll> &a)
    {
        n = a.size();
        tree.assign(3 * a.size(), 0);
        for (ll i = n; i < 2 * n; i++)
            tree[i] = a[i - n];
        for (ll i = n - 1; i >= 1; i--)
            tree[i] = max(tree[i << 1] , tree[i << 1 | 1]);
    }
    void build(ll x){
      n=x;
      ll ok = -1e12;
      tree.assign(3*n,ok);
    }
    void update(ll p, ll v)
    {
        for (tree[p += n] = v, p >>= 1; p; p >>= 1)
            tree[p] = max(tree[p << 1] , tree[p << 1 | 1]);
    }
 
    ll query(ll l, ll r)
    {
        ll ans = -1e15;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ans = max(ans , tree[l++]);
            if (r & 1)
                ans = max(ans , tree[--r]);
        }
        return ans;
    }
};
 int main(){
   IOS
   ll n;
   cin>>n;
   vector<ll>a(n+1),prefix(n+1,0);
   ll i;
   set<ll>sp;
   for(i=1;i<=n;i++){
     cin>>a[i];
     prefix[i]=prefix[i-1]+a[i];
     sp.insert(prefix[i]);
   }
   map<ll,ll>vp;
   ll lp=1;
   for(auto &x:sp){
      vp[x]=++lp;
   }
   segment aman;
   aman.build(n+10);
   vector<ll>dp(n+1);
   aman.update(vp[prefix[0]],0LL);
   ll ans=0;
   for(i=1;i<=n;i++){
     ll val=aman.query(1,vp[prefix[i]]);
     dp[i]=max(dp[i-1],val+i);
     aman.update(vp[prefix[i]],dp[i]-i);
   }
   cout<<dp[n];
}