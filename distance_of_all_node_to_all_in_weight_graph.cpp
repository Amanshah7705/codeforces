/*
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution{
public:
     vector<ll>dis1,dis2;
     vector<vector<pair<ll,ll>>>adj;
     void dfs(ll v,ll parent){
         for(auto &x:adj[v]){
             if(x.first==parent){
                 continue;
             }
             dis1[x.first]=x.second+dis1[v];
             dfs(x.first,v);
         }
         
     }
     vector<long long> longDrive(int n, vector<vector<int>> edges, int q, vector<int> query){
        // adj=edges;
        // cout<<edges[0][1];
        ll i;
        adj.clear();
        adj.resize(n+1);
        for(i=1;i<=n-1;i++){
            adj[edges[i-1][0]].push_back({edges[i-1][1],edges[i-1][2]});
            adj[edges[i-1][1]].push_back({edges[i-1][0],edges[i-1][2]});
        }
        dis1.clear();
        dis1.resize(n+1,0);
        dfs(1,-1);
        ll maxi=*max_element(dis1.begin(),dis1.end());
        ll maxi1=0;
        for(i=1;i<=n;i++){
            if(maxi==dis1[i]){
                maxi1=i;
            }
        }
        dis1.clear();
        dis1.resize(n+1,0);
        dfs(maxi1,-1);
        dis2.clear();
        maxi=*max_element(dis1.begin(),dis1.end());
        ll maxi2=0;
        for(i=1;i<=n;i++){
            if(dis1[i]==maxi){
                maxi2=i;
            }
        }
        //  for(i=1;i<=n;i++){
        //     cout<<dis1[i]<<" ";
        // }
        // cout<<endl;
        // cout<<maxi2<<endl;
        dis2=dis1;
        dis1.clear();
        dis1.resize(n+1,0);
        dfs(maxi2,-1);
        // for(i=1;i<=n;i++){
        //     cout<<dis1[i]<<" ";
        // }
        // cout<<endl;
        for(i=1;i<=n;i++){
            dis1[i]=max(dis1[i],dis2[i]);
        }
        vector<ll>ret;
        for(auto &x:query){
            ret.push_back(dis1[x]);
        }
        return ret;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> edges(n - 1, vector<int>(3));
        for(int i = 0; i < n - 1; i++)
        {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }
        int q;
        cin >> q;
        vector<int> query(q);
        for(int i = 0; i < q; i++)
        {
            cin >> query[i];
        }
        Solution s;
        vector<long long> ans = s.longDrive(n, edges, q, query);
        for(long long x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
*/