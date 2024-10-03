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
struct Node{
    ll val;
    ll prior;
    Node *left,*right;
    ll size;
    ll minVal,maxVal;
    ll lazy;
    Node(ll v){
        this->val=v;
        this->prior=rand();
        this->left  = this->right = nullptr;
        this->size = 1;
        this->minVal = this->maxVal=v;
        this->lazy=0;
    }
};

// Pushes the lazy updates down the tree
void push(Node *t){
    if(t && t->lazy != 0){
        t->val += t->lazy;
        t->minVal += t->lazy;
        t->maxVal += t->lazy;
        if( t->left){
            t->left->lazy+=t->lazy;
        }
        if(t->right){
            t->right->lazy+=t->lazy;
        }
        t->lazy=0;
    }
}

// Updates the node's size, minVal, and maxVal
void update(Node *t){
    if(t){
        t->size = 1;
        t->minVal = t->val;
        t->maxVal = t->val;
        if(t->left){
            t->size+=t->left->size;
            t->minVal = min(t->minVal, t->left->minVal+t->left->lazy);
            t->maxVal = max(t->maxVal, t->left->maxVal+t->left->lazy);
        }
        if(t->right){
            t->size+=t->right->size;
            t->minVal = min(t->minVal, t->right->minVal+t->right->lazy);
            t->maxVal = max(t->maxVal, t->right->maxVal+t->right->lazy);
        }
    }
}

// Splits the treap into two treaps l and r based on the position k
void split(Node *t,ll k, Node *&l, Node *&r){
    if(!t){
        l=r=nullptr;
        return;
    }
    push(t);
    ll leftSize = t->left ? t->left->size : 0;
    if(k<=leftSize){
        split(t->left,k,l,t->left);
        r=t;
    }
    else{
        split(t->right,k-leftSize-1,t->right,r);
        l=t;
    }
    update(t);
}

// Merges two treaps l and r into one treap t
void merge(Node *&t, Node *l, Node *r){
    push(l);
    push(r);
    if(!l || !r){
        t = l ? l : r;
    }
    else if(l->prior > r->prior){
        merge(l->right,l->right,r);
        t=l;
    }
    else{
        merge(r->left,l,r->left);
        t=r;
    }
    update(t);
}

// Inserts a new node with value val at position pos
void insert(Node *&t,ll pos,ll val){
    Node *newNode = new Node(val);
    Node *t1,*t2;
    split(t,pos,t1,t2);
    merge(t1,t1,newNode);
    merge(t,t1,t2);
}

// Adds value x to all nodes in the range [l, r)
void rangeAdd(Node *&t, ll l,ll r,ll x){
    Node *t1,*t2,*t3;
    split(t,l,t1,t2);  // Split at position l
    split(t2,r-l,t2,t3); // Split at position r
    if(t2){
        t2->lazy +=x;
        t2->minVal += x;
        t2->maxVal += x;
    }
    merge(t,t1,t2);
    merge(t,t,t3);
}

// Returns the count of nodes with values in the range [L, R]
ll rangeQuery(Node *t,ll l,ll r){
    if(!t){
        return 0;
    }
    ll tMin = t->minVal + t->lazy;
    ll tMax = t->maxVal + t->lazy;
    if(tMin > r || tMax < l){
        return 0;
    }
    if(tMin >= l && tMax <= r){
        return t->size;
    }
    push(t);
    ll cnt=0;
    if(t->val >= l && t->val<=r){
        cnt++;
    }
    cnt+=rangeQuery(t->left,l,r);
    cnt+=rangeQuery(t->right,l,r);
    return cnt;
}

// Counts the number of nodes with values less than X
ll countLessThan(Node *t, ll x){
    if(!t){
        return 0;
    }
    ll tMin = t->minVal + t->lazy;
    ll tMax = t->maxVal + t->lazy;

    if(tMin >= x){
        return 0;
    }
    if(tMax < x){
        return t->size;
    }
    push(t);
    ll cnt=0;
    if(t->val < x){
        cnt++;
    }
    cnt += countLessThan(t->left,x);
    cnt += countLessThan(t->right,x);
    return cnt;
}

// Performs an inorder traversal of the treap and stores the result in res
void inOrder(Node *t , vector<ll>&res){
    if(!t){
        return;
    }
    push(t);
    inOrder(t->left,res);
    res.push_back(t->val);
    inOrder(t->right,res);
}
void main_()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1="YES",s2="NO";
    ll t;
    cin>>t;
    ll f=0;
    while(t--){
         f++;
         cout<<"Case #"<<f<<": ";
        ll n,k;
        cin>>n>>k;
        vector<ll>a(n);
        ll i;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        Node * treap = nullptr;
        ll maxi = *max_element(a.begin(),a.end());
        ll cnt=0;
        for(i=0;i<n;i++){
            ll low = a[i] , high = 2*maxi+1;
            ll ans = low;
            while(low<=high){
                ll mid=(low+high)/2;
                // ama 0 thi mid sudhi no count search kare
                ll curSize = rangeQuery(treap,0,mid);
                if(curSize + a[i] > mid){
                    low = mid + 1;
                }
                else if( curSize + a[i] < mid){
                     high = mid - 1;
                }
                else{
                    ans = mid;
                    high=mid-1;
                }
            }
            // cout<<ans<<" ";
            // ama 0 thi ans-a[i] postion sushi val ghatade
            rangeAdd(treap,0,ans - a[i],-1);
            // ama ans-a[i] postion par aa value add kare
            insert(treap,ans-a[i],ans);
        }
        vector<ll>vp;
        inOrder(treap,vp);
        sort(vp.begin(),vp.end());
        ll valx = 1e18,index=0;
        for(i=0;i<n;i++){
            if(abs(k-vp[i])<=valx){
                valx = abs(k-vp[i]);
                index = n-i;
            }
        }
        swap(index,valx);
        cout<<valx<<" "<<index<<endk;
    }
}
 
static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%esp, (%0)\n"
        "mov %0, %%esp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%esp\n" : : "r"(send));
    free(stack);
}
int main() {
    freopen("line_of_delivery_part_2_input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    run_with_stack_size(main_, 1024 * 1024 * 1024);
    return 0;
}