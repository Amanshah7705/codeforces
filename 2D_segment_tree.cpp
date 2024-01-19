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
vector<vector<ll>>arr,seg_tree;
ll n,m;
     void buildy(ll nodex, ll startx, ll endx, ll nodey, ll starty, ll endy){
        if(starty == endy){
            if(startx == endx){
                seg_tree[nodex][nodey] = arr[startx][starty];
            }else{
                seg_tree[nodex][nodey] = seg_tree[nodex*2][nodey] + seg_tree[nodex*2+1][nodey];
            }
        }else{
            ll mid = (starty+endy)/2;
            buildy(nodex, startx, endx, nodey*2, starty, mid);
            buildy(nodex, startx, endx, nodey*2+1, mid+1, endy);
            seg_tree[nodex][nodey] = seg_tree[nodex][nodey*2] + seg_tree[nodex][nodey*2+1];
        }
    }
    
     void buildx(ll nodex, ll startx, ll endx){
        if(startx == endx){
            buildy(nodex, startx, endx, 1, 1, m);
        }else{
            ll mid = (startx+endx)/2;
            buildx(nodex*2, startx, mid);
            buildx(nodex*2+1, mid+1, endx);
            buildy(nodex, startx, endx, 1, 1,m);
        }
    }

    static void updatey(ll nodex, ll startx, ll endx, ll nodey, ll starty,ll  endy, ll x, ll y, ll val){
        if(starty == endy){
            if(startx == endx){
                seg_tree[nodex][nodey] += val;
            }else{
                seg_tree[nodex][nodey] = seg_tree[nodex*2][nodey] + seg_tree[nodex*2+1][nodey];
            }
        }else{
            ll mid = (starty + endy)/2;
            if(starty <= y && y <= mid){
                updatey(nodex, startx, endx, nodey*2, starty, mid, x,y,val);
            }else{
                updatey(nodex, startx, endx, nodey*2+1, mid+1, endy, x,y,val);
            }
            seg_tree[nodex][nodey] = seg_tree[nodex][nodey*2] + seg_tree[nodex][nodey*2+1];
        }
    }
    
     void updatex(ll nodex, ll startx, ll endx, ll x, ll y, ll val){
        if(startx == endx){
            updatey(nodex, startx, endx, 1, 1, m, x, y, val);
        }else{
            ll mid = (startx+endx)/2;
            if(startx <= x && x <= mid){
                updatex(nodex*2, startx, mid, x,y,val);
            }else{
                updatex(nodex*2+1, mid+1, endx, x,y,val);
            }
            updatey(nodex, startx, endx, 1, 1, m, x, y, val);
        }
    }

    ll queryy(ll nodex, ll nodey, ll starty, ll endy, ll y1, ll y2){
        if(endy < y1 || y2 < starty)return 0;
        
        if(starty == endy){
            return seg_tree[nodex][nodey];
        }else if(y1 <= starty && endy <= y2){
            return seg_tree[nodex][nodey];
        }else{
            ll mid = (starty+endy)/2;
            ll la = queryy(nodex, nodey*2, starty, mid, y1,y2);
            ll ra = queryy(nodex, nodey*2+1, mid+1, endy, y1,y2);
            return la+ra;
        }
        
    }

     ll queryx(ll nodex, ll startx, ll endx, ll x1, ll x2, ll y1, ll y2){
        if(endx<x1 || x2 < startx)return 0;
        
        if(startx == endx){
            return queryy(nodex, 1, 1, m, y1, y2);
        }else if(x1 <= startx && endx <= x2){
            return queryy(nodex, 1, 1, m, y1, y2);
        }else{
            ll mid = (startx+endx)/2;
            ll la = queryx(nodex*2, startx, mid, x1,x2,y1,y2);
            ll ra = queryx(nodex*2+1, mid+1, endx, x1,x2,y1,y2);
            return la+ra;
        }
        
    }
    // one base indexing 
   int main() {
        
		cin>>n>>m;
        
        arr=vector<vector<ll>>(n+1,vector<ll>(m+1));
        
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>arr[i][j];
            }
        }
       seg_tree=vector<vector<ll>>(4*n,vector<ll>(4*m,0));
       buildx(1, 1, n);
        
        ll q;
		cin>>q;
        
        while(q--){
            string type;
			cin>>type;
            if(type=="q"){
                ll x1,y1,x2,y2;
				cin>>x1>>y1>>x2>>y2;
                ll ans = queryx(1, 1, n, x1,x2,y1,y2);
                cout<<ans<<endk;
            }else{
                ll x,y,val;
				cin>>x>>y>>val;
                updatex(1, 1,n, x,y,val);
            }
        }
  }
                                