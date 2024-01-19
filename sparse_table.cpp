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
vector<ll>dx={1,0,0,1};
vector<ll>dy={0,1,1,0};
vector<ll> a; // 1 - based a = vector<ll> (n+1);
vector<vector<ll>> dp; // 1 - based sp = vector<vector<ll>> (n+1 , vector<ll> (32 ,0));
vector<vector<ll>>pp;
void build1(){
    ll n = a.size(); n--;
    for(ll i=0;i<32;i++){
        for(ll j=1;j<=n-(1LL << i)+1;j++){
            if(i==0) dp[j][i] = a[j];
            else dp[j][i] = min(dp[j][i-1] ,dp[j + (1LL << (i-1))][i-1]); 
        }
    }
}
void build2(){
    ll n = a.size(); n--;
    for(ll i=0;i<32;i++){
        for(ll j=1;j<=n-(1LL << i)+1;j++){
            if(i==0) pp[j][i] = a[j];
            else pp[j][i] = max(pp[j][i-1] ,pp[j + (1LL << (i-1))][i-1]); 
        }
    }
}
ll query1(ll l , ll r){
    ll len = r - l + 1;
    ll min_pow = 0;
    while((1LL << (min_pow+1)) <= len) min_pow++;
    return min(dp[l][min_pow] , dp[r - (1LL << min_pow) + 1][min_pow]);
}
ll query2(ll l , ll r){
    ll len = r - l + 1;
    ll min_pow = 0;
    while((1LL << (min_pow+1)) <= len) min_pow++;
    return max(pp[l][min_pow] , pp[r - (1LL << min_pow) + 1][min_pow]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1="YES",s2="NO";
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        a.clear();
        a.resize(n+1);
        dp.clear();
        dp.resize(n+1,vector<ll>(32,0));
        pp.clear();
        pp.resize(n+1,vector<ll>(32,0));
        ll i;
        for(i=1;i<=n;i++){
            cin>>a[i];
        }
        build1();
        build2();
        vector<pair<ll,ll>>zf1,zf2;
        ll j;
        bool aman=false;
        pair<ll,ll>z1;
        map<ll,ll>ketla_che;
        map<ll,ll>second_last,last;
        for(i=n;i>=1;i--){
            ketla_che[a[i]]++;
            if(ketla_che[a[i]]==2){
                second_last[a[i]]=i;
            }
            if(ketla_che[a[i]]==1){
                last[a[i]]=i;
                second_last[a[i]]=i;
            }
        }
        for(i=1;i<=n;i++){
            ll fx=query2(1,i);
            ll hx=second_last[fx];
            // cout<<fx<<" "<<hx<<endk;
            if(i>=hx || ketla_che[fx]<=2){
                continue;
            }
            // cout<<i<<" ";
            // ketla_che[a[i]]--;
            ll index=last[fx];
            ll low=i+2;
            ll high=index;
            while(low<=high){
                ll mid=(low+high)/2;
                ll hp1=query2(mid,n);
                // if(i==2){
                //     cout<<mid<<endk;
                // }
                if(hp1>fx){
                    low=mid+1;
                }
                else if(hp1<fx){
                    high=mid-1;
                }
                else{
                    ll hp2=query1(i+1,mid-1);
                    if(hp2==fx){
                        z1.first=i;
                        z1.second=mid;
                        aman=true;
                        break;
                    }
                    else if(hp2<fx){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
            }
            if(aman){
                break;
            }
        }
        if(aman){
            cout<<s1<<endk;
            cout<<z1.first<<" "<<z1.second-z1.first-1<<" "<<n-z1.second+1<<endk;
        }
        else{
            cout<<s2<<endk;
        }
    }
}