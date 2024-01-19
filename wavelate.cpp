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
const ll n1=5*1e5+1;
ll a[n1];
struct wavelet_tree
{
    ll lo, hi;
    wavelet_tree *l=0, *r=0;
    vector<ll>b,c;
    // c holds the prefix sum of elements

    //nos are in range [x,y]
    //array indices are [from, to)
    wavelet_tree(ll *from, ll *to, ll x, ll y)
    {
        lo = x, hi = y;
        if( from >= to)
            return;
        if( hi == lo )
        {
            b.reserve(to-from+1);
            b.push_back(0);
            c.reserve(to-from+1);
            c.push_back(0);
            for(auto it = from; it != to; it++)
            {
                b.push_back(b.back() + 1);
                c.push_back(c.back()+*it);
            }
            return ;
        }
        ll mid = (lo+hi)/2;
        auto f = [mid](ll x)
        {
            return x <= mid;
        };
        b.reserve(to-from+1);
        b.push_back(0);
        c.reserve(to-from+1);
        c.push_back(0);
        for(auto it = from; it != to; it++)
        {
            b.push_back(b.back() + f(*it));
            c.push_back(c.back() + *it);
        }
        //see how lambda function is used here
        auto pivot = stable_partition(from, to, f);
        l = new wavelet_tree(from, pivot, lo, mid);
        r = new wavelet_tree(pivot, to, mid+1, hi);
    }

    // swap a[i] with a[i+1]  , if a[i]!=a[i+1] call swapadjacent(i)
    void swapadjacent(ll i)
    {
        if(lo == hi)
            return ;
        b[i]= b[i-1] + b[i+1] - b[i];
        c[i] = c[i-1] + c[i+1] - c[i];
        if( b[i+1]-b[i] == b[i] - b[i-1])
        {
            if(b[i]-b[i-1])
                return this->l->swapadjacent(b[i]);
            else
                return this->r->swapadjacent(i-b[i]);
        }
        else
            return ;
    }

    //kth smallest element in [l, r]
    ll kth(ll l, ll r, ll k)
    {
        if(l > r)
            return 0;
        if(lo == hi)
            return lo;
        ll inLeft = b[r] - b[l-1];
        ll lb = b[l-1]; //amt of nos in first (l-1) nos that go in left
        ll rb = b[r]; //amt of nos in first (r) nos that go in left
        if(k <= inLeft)
            return this->l->kth(lb+1, rb, k);
        return this->r->kth(l-lb, r-rb, k-inLeft);
    }

    //count of nos in [l, r] Less than or equal to k
    ll LTE(ll l, ll r, ll k)
    {
        if(l > r or k < lo)
            return 0;
        if(hi <= k)
            return r - l + 1;
        ll lb = b[l-1], rb = b[r];
        return this->l->LTE(lb+1, rb, k) + this->r->LTE(l-lb, r-rb, k);
    }

    //count of nos in [l, r] equal to k
    ll count(ll l, ll r, ll k)
    {
        if(l > r or k < lo or k > hi)
            return 0;
        if(lo == hi)
            return r - l + 1;
        ll lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
        if(k <= mid)
            return this->l->count(lb+1, rb, k);
        return this->r->count(l-lb, r-rb, k);
    }

    //sum of nos in [l ,r] less than or equal to k
    ll sumk(ll l, ll r, ll k)
    {
        if(l > r or k < lo)
            return 0;
        if(hi <= k)
            return c[r] - c[l-1];
        ll lb = b[l-1], rb = b[r];
        return this->l->sumk(lb+1, rb, k) + this->r->sumk(l-lb, r-rb, k);
    }

    ~wavelet_tree()
    {
        if(l)
        delete l;
        if(r)
        delete r;
    }
};
int main(){
   IOS
    string s1="YES",s2="NO";
        ll n;
        cin>>n;
        ll i;
        for(i=1;i<=n;i++){
            cin>>a[i];
        }
        wavelet_tree T(a+1, a+n+1, 1LL,n);
        ll q;
        cin>>q;
        while(q--){
            ll l,r,k;
            cin>>l>>r>>k;
            cout<<T.count(l,r,k)<<endk;
        }
}
