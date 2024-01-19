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
const ll N=3*1e5;
struct Node{
    Node* link[26];
    bool vis=false;
};
struct Trie{
    private:Node* root;
    public:
    Trie(){
        root= new Node();
    }
    void insert(string s){
        int i;
        Node* t=root;
        int n=s.length();
        for(i=0;i<n;i++){
            if(t->link[s[i]-'a']==NULL){
                t->link[s[i]-'a']=new Node();
            }
            t=t->link[s[i]-'a'];
        }
        t->vis=true;
    }
    int search(string s){
        int i,n=s.length();
        Node* t=root;
        for(i=0;i<n;i++){
            if(t->link[s[i]-'a']==NULL){
               return false;
            }
            t=t->link[s[i]-'a'];
            
        }
        return t->vis;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string p;
    cin>>p;
    ll k;
    cin>>k;
    ll i;
    for(i=0;i<26;i++){
        if(p[i] == '1'){
            p[i]='0';
        }
        else{
            p[i]='1';
        }
    }
    Trie bap;
    ll j;
    ll n=s.length();
    ll ok=0;
    for(i=0;i<n;i++){
       string pk="";
       ll ans=0;
       for(j=i;j<n;j++){
           pk+=s[j];
           ans+=(p[s[j]-'a']=='1');
           if(ans<=k){
               if(bap.search(pk)){
                   continue;
               }
               bap.insert(pk);
               ok++;
           }
           else{
               break;
           }
       }
    }
    cout<<ok<<endk;
}