#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set_pair tree<pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_mutliset_pair tree<pair<int, int>, null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;
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
struct node{
    public:
    node* link[2];
    ll fre;
    node(){
        link[0]=NULL;
        link[1]=NULL;
        fre=0;
    }
};
void insert(node* root,ll num){
    ll i;
    node* it=root;
    for(i=60;i>=0;i--){
        bool bit=(1LL<<i)&num;
        if(it->link[bit] ==NULL){
            it->link[bit]=new node();
        }
        it=it->link[bit];
        it->fre++;
    }
}
void erase(node* root,ll num){
    ll i;
    node* it=root;
    for(i=60;i>=0;i--){
        bool bit=(1LL<<i)&num;
        it->link[bit]->fre--;
        it=it->link[bit];
    }
}
ll getmax(node* root,ll num){
    ll i;
    node* it=root;
    ll maxi=0;
    for(i=60;i>=0;i--){
        bool bit=(1LL<<i)&num;
        bit=(!bit);
        if(it->link[bit]==NULL){
            bit=(!bit);
        }
        else if(it->link[bit]->fre == 0){
            bit=(!bit);
        }
        else{
            maxi+=(1LL<<i);
        }
        it=it->link[bit];
    }
    return maxi;
}
int main(){
    ll n;
    cin>>n;
    node* root=new node();
    insert(root,0);
    while(n--){
        char c;
        cin>>c;
        ll a;
        cin>>a;
        // cout<<c<<" "<<a<<endk;
        if(c=='+'){
            insert(root,a);
        }
        else if(c=='-'){
            erase(root,a);
        }
        else{
            cout<<getmax(root,a)<<endk;
        }
    }
}

 