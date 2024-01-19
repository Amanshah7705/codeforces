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
const ll N=1e5;
vector<ll>a,segment_tree,lazy;
void built(ll node,ll st,ll en){
    if(st==en){
        segment_tree[node]=a[st];
        return;
    }
    ll mid=(st+en)/2;
    built(2*node,st,mid);
    built(2*node+1,mid+1,en);
    segment_tree[node]=segment_tree[2*node]+segment_tree[2*node+1];
}
void update(ll node,ll st,ll en,ll l,ll r,ll val){
    if(lazy[node] != 0){
        ll len=en-st+1;
        ll up=lazy[node];
        lazy[node]=0;
        segment_tree[node]+=up*len;
        if(st != en){
            lazy[2*node]+=up;
            lazy[2*node+1]+=up;
        }
    }
        if(st>r || en<l){
            return;
        }
         if(st>=l && en<=r){
           ll len=en-st+1;
           segment_tree[node]+=len*val;
           if(st != en){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
           }
           return;
         }
         ll mid=(st+en)/2;
         update(2*node,st,mid,l,r,val);
         update(2*node+1,mid+1,en,l,r,val);
         segment_tree[node]=segment_tree[2*node]+segment_tree[2*node+1];
}
ll query(ll node,ll st,ll en,ll l,ll r){
    if(lazy[node] != 0){
        ll len=en-st+1;
        ll up=lazy[node];
        lazy[node]=0;
        segment_tree[node]+=up*len;
        if(st != en){
            lazy[2*node]+=up;
            lazy[2*node+1]+=up;
        }
    }
    if(st>r || en<l){
            return 0;
    }
    if(st>=l && en<=r){
        return segment_tree[node];
    }
    ll mid=(st+en)/2;
    return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
}
int main(){
    ll n;
    cin>>n;
    a.resize(n);
    ll i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    segment_tree.resize(4*n+1,0);
    lazy.resize(4*n+1,0);
    built(1,0,n-1);
    ll q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        if(x==1){//update range
           ll val;
           cin>>val;
           ll l,r;
           cin>>l>>r;
           update(1,0,n-1,l,r,val);
        }
        else{
            ll x,y;
            cin>>x>>y;
            cout<<query(1,0,n-1,x,y)<<endk;
        }
    }
}