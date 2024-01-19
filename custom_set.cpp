
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
 vector<vector<ll>>vis;
int main(){
   IOS
   ll n;
   cin>>n;
   vector<ll>a(n);
   ll i;
   ll sum=0;
   for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
   }
   auto cmp = [](pair<ll,ll>a1,pair<ll,ll>b1) { 
         if(a1.first == b1.first){
              return a1.second>b1.second;
         }
         else{
              return a1.first<b1.first;
         }
        };
   set<pair<ll,ll>,decltype(cmp)>v;
   set<pair<ll,ll>>v2;
   for(i=0;i<n;i++){
        v.insert({a[i],i});
        v2.insert({a[i],i});
   }
   ordered_set aman;
   for(i=0;i<n;i++){
        aman.insert(i);
   }
   ll jp=n-1;
   ll left=n;
   while(jp--){
         auto it=v.end();
         it--;
         pair<ll,ll>p=*it;
         left--;
        //   cout<<p.first<<" "<<sum<<" ";
        // dbg(a);
        
         if((sum-p.first)>=p.first){
              cout<<p.second+1<<" "<<p.first<<endk;
              v.erase(it);
              v2.erase({p.first,p.second});
              sum-=p.first;
              ll up=aman.order_of_key(p.second);
              up--;
              a[p.second]=0;
              if(up>=0){
                   ll lo=*(aman.find_by_order(up));
                   sum+=(p.first)/2;
                   v.erase({a[lo],lo});
                   v2.erase({a[lo],lo});
                   a[lo]+=(p.first)/2;
                   v.insert({a[lo],lo});
                   v2.insert({a[lo],lo});
              }
              up+=2;
              if(up<=left){
                   ll lo=*(aman.find_by_order(up));
                   sum+=(p.first)/2;
                   v.erase({a[lo],lo});
                   v2.erase({a[lo],lo});
                   a[lo]+=(p.first)/2;
                   v.insert({a[lo],lo});
                   v2.insert({a[lo],lo});
              }
              aman.erase(p.second);
              
         }
         else{
              it=v2.begin();
              p=*it;
             cout<<p.second+1<<" "<<p.first<<endk;
              v2.erase(it);
              v.erase({p.first,p.second});
              sum-=p.first;
              ll up=aman.order_of_key(p.second);
              up--;
              a[p.second]=0;
              if(up>=0){
                   ll lo=*(aman.find_by_order(up));
                   sum+=(p.first)/2;
                   v.erase({a[lo],lo});
                   v2.erase({a[lo],lo});
                   a[lo]+=(p.first)/2;
                   v2.insert({a[lo],lo});
                   v.insert({a[lo],lo});
              }
              up+=2;
              if(up<=left){
                   ll lo=*(aman.find_by_order(up));
                   sum+=(p.first)/2;
                   v.erase({a[lo],lo});
                   v2.erase({a[lo],lo});
                   a[lo]+=(p.first)/2;
                   v.insert({a[lo],lo});
                   v2.insert({a[lo],lo});
              }
              aman.erase(p.second);
         }
   }
   pair<ll,ll>z1=*v.begin();
   cout<<z1.second+1<<" "<<z1.first<<endk;
}