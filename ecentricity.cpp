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
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL);
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
/*    orj8j8jdered_set ma insert karva
nam ordered_set aman;
aman.insert(x);
order find karva *(aman.find_by_order(x))--> ana vade index x medvava ama x 0 base 6;
 anathi nana find karva aman.order_of_key(x)
 */

int main(){
    ll n, m;
    cin >> n;
    cin >> m;
    vector<vector<ll>> graph;
    graph.resize(n+1);
    ll i;
    for( i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> ece(n+1);
    const ll N = 1e6+6;
    auto get = [&](ll start)->ll{
        vector<ll> d(n+1,N);
        queue<ll> q;
        q.push(start);
        d[start]=0;
        while(!q.empty()){
            ll u = q.front();
            q.pop();
            for(auto &child:graph[u]){
                if(d[child]==N){
                    d[child] = d[u] + 1;
                    q.push(child);
                }
            }
        }
        ll mx = 0 ;
        for( i=1 ; i<=n ; i++){
            mx = max(mx,d[i]);
            ece[i] = max(ece[i],d[i]);
        }
        for(i=1 ;i<=n ; i++){
            if(d[i]==mx)return i;
        }
    };
    ll farthest = get(1);
    ll second_farthest = get(farthest);
    ll diameter = 0 ;
    ll radius = N;
    for(i = 1 ; i<=n; i++){
        diameter = max(diameter,ece[i]);
        radius = min(radius,ece[i]);
    }
    set<ll> centi;
    for( i=1 ; i<=n ;i++){
        if(radius==ece[i]){
            centi.insert(i);
        }
    }
    for(ll i=1 ; i<=n ; i++){
        cout<<ece[i]<<" ";
    }
    cout<<endl;
    cout<<"Diameter : "<<diameter<<endl;
    cout<<"Radius : "<<radius<<endl;
    cout<<"Centre : ";
    for(auto &x:centi){
        cout<<x<<" ";
    }
    cout<<endl;
}