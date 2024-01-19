#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define dbg(x) cout << #x << " -> "; ppp(x); cout<<endl
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(v) v.begin(), v.end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rep(i, m, n) for (int i = m; i < n; i++)
#define INF (ll)5e18
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
void __print(int x)
{
    cerr << x;
}
void ppp(int a)          { cout<<a; }
void ppp(ll a)           { cout<<a; }
void ppp(long double a)  { cout<<a; }
void ppp(double a)       { cout<<a; }
void ppp(char a)         { cout<<a; }
void ppp(string a)       { cout<<a; }
void ppp(bool a)         { cout<<a; } 
//   priority_queue<ll,vector<ll>,greater<ll>>q;
/*priority_queue<pair<ll,ll>>q;
map<pair<ll,ll>,ll>z;
vector<pair<ll,ll>>t;*/
template<class T , class V> void ppp(pair<T,V> p) {cout<<"{"; ppp(p.ff); cout<<','; ppp(p.ss); cout<<"}";}
template<class T> void ppp(vector<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
template<class T> void ppp(set<T> v){cout<<"[ ";for(T x:v) ppp(x) , cout<<" ";cout<<']';}
template<class T, class V> void ppp(map<T,V> m){cout<<endl;for(auto x:m){ppp(x.ff);cout<<" -> ";ppp(x.ss);cout<<endl;}cout<<endl;}
template<class T> void ppp(deque<T> v)  {cout<<"[ ";for(T x:v) ppp(x), cout<<" ";cout<<']';}
const ll N=2*1e5+10;
vector<ll>bit;
ll n;
ll qury(ll i)
{
    ll ans=0;
    while(i>0)
    {
        ans+=bit[i];
        i-= (i & (-i));
    }
    return ans;
}
void update(ll index,ll val)
{
    while(index<=n)
    {
        bit[index]+=val;
        index+=(index &(-index));
    }
}
int main()
{
  cin>>n;
  bit=vector<ll>(n+1);
  vector<ll>a(n+1);
  ll i;
  for(i=1;i<=n;i++)
  {
      cin>>a[i];
      update(i,a[i]);
  }
  ll q;
  cin>>q;
  while(q--)
  {
      ll c;
      cin>>c;
      if(c==1)
      {
          ll l,r;
          cin>>l>>r;
          ll ans=qury(r)-qury(l-1);
          cout<<ans<<endl;
      }
      else{
            ll index;
            ll val;
            cin>>index>>val;
            update(index,-a[index]);
            a[index]=val;
            update(index,val);
      }
  }

}