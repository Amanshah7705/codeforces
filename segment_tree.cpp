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
const ll N=3*1e5;
const ll mod=pow(10,9)+7;
vector<ll>a(N);
vector<ll>segment_tree(4*N);
void built(ll node,ll st,ll en)
{
    if(st == en)
    {
        segment_tree[node]=a[st];
        return;
    }
    ll mid=(st+en)/2;
    built(2*node,st,mid);
    built(2*node+1,mid+1,en);
    segment_tree[node]=__gcd(segment_tree[2*node],segment_tree[2*node+1]);/*for sum we need to perform
     (segment_tree[node]=segment_tree[2*node]+segment_tree[2*node+1]);*/
}
ll query(ll node,ll st,ll en, ll l,ll r)
{
    if(st>r || en<l)
    {
        return 0;
    }
    if(l<=st && en<=r)
    {
        return segment_tree[node];
    }
    ll mid=(st+en)/2;
    ll q1=query(2*node,st,mid,l,r);
    ll q2=query(2*node+1,mid+1,en,l,r);
    /* for sum we need to perform
    return q1+q2*/
    return __gcd(q1,q2);
}
void update(ll node,ll st,ll en,ll index,ll value)
{
    if(st == en)
    {
        a[st]=value;
        segment_tree[node]=value;
        return;
    }
    ll mid=(st+en)/2;
    if(index<=mid)
    {
        update(2*node,st,mid,index,value);
    }
    else{
        update(2*node+1,mid+1,en,index,value);
    }
    segment_tree[node]=__gcd(segment_tree[2*node],segment_tree[2*node+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll i;
        a.clear();
        a.resize(n);
        segment_tree.clear();
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        built(1,0,n-1);
        ll ans=0;
        for(i=0;i<n;i++){
            ll hx;
            if(i==0){
                 hx=query(1,0,n-1,1,n-1);
            }
            else if(i==n-1){
                hx=query(1,0,n-1,0,n-2);
            }
            else{
                ll p1=query(1,0,n-1,0,i-1);
                ll p2=query(1,0,n-1,i+1,n-1);
                hx=__gcd(p1,p2);
            }
            // cout<<hx<<endk;
            if(hx != 1){
                ans++;
            }
        }
        cout<<ans<<endk;
    }
  }
 