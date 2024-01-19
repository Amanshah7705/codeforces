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
vector<ll>dx={-1,1,-1,1};
vector<ll>dy={-1,-1,1,1};
const ll N=2*1e5+10;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0;
        return 0;
    }
    ll loka=0;
    ll i;
    for(i=60;i>=0;i--){
        if((1LL<<i)&b){
            loka+=(1LL<<i);
        }
        else{
            if(loka){
                loka+=(1LL<<i);
            }
        }
    }
    ll first=-1;
    ll fx=b,gx=a;
    ll l1=0,l2=0;
    ll mc=0;
    // ll first=0;
    for(i=60;i>=0;i--){
        ll ok=(1LL<<i);
       if((a&ok) && (b&ok)){
           if(first==-1 || first==1){
               first=1;
               l1+=ok;
               l2+=ok;
           }
       }
       else{
           if((a&ok) ==0 && (b&ok)==0){
               if(first==1){
                   first=1;
               }
           }
           else{
               first=2;
           }
       }
    }
    for(i=60;i>=0;i--){
        ll ok=(1LL<<i);
        if(ok&loka){
            if(l1<l2){
                if(l1+ok<=b){
                    l1+=ok;
                }
            }
            else{
                if(l2+ok<=b){
                    l2+=ok;
                }
            }
        }
    }
    cout<<(l1^l2);
}