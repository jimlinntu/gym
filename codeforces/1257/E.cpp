#include <bits/stdc++.h> 
#include <complex>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <chrono>
#include <random>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define MOD 1000000007
#define MOD2 1000000009
#define INF 2000000000
#define DESPACITO 1000000000000000
#define PI acos(-1)
#define E 998244353
#define pb push_back
#define mp make_pair
#define double long double
#define pdd pair<double,double>
#define ll long long
 
using namespace std;

//using namespace __gnu_pbds;
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int tree[800001];
int lazy[800001];
int dp[4][200001];
int values[4][200001];
int n;
int k1,k2,k3;
int pre[200001];


void Create(int node,int start,int end)
{
    if(start == end)
        tree[node] = dp[3][start];
    else
    {
        int mid = (start+end)/2;
        Create(2*node,start,mid);
        Create(2*node+1,mid+1,end);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

void updateRange(int node,int start,int end,int l,int r,int val)
{
    if(lazy[node])
    {
        tree[node] += lazy[node];
        if(start != end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>end or start>r or end<l or l>r)
        return;
    if(start>=l && end<=r)
    {
        tree[node]+=val;
        if(start!=end)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    int mid = (start+end)/2;
    updateRange(2*node,start,mid,l,r,val);
    updateRange(2*node+1,mid+1,end,l,r,val);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}

int query(int node,int start,int end,int l,int r)
{
    if(lazy[node])
    {
        tree[node] += lazy[node];
        if(start != end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>end or start>r or end<l or l>r)
        return INF;
    if(start>=l && end<=r)
        return tree[node];
    int mid = (start+end)/2;
    int p = query(2*node,start,mid,l,r);
    int q = query(2*node+1,mid+1,end,l,r);
    return min(p,q);

}
int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    REP(j,1,n)
         values[1][j] = 1;
    REP(j,1,k1)
    {
        int x;
        cin >> x;
        values[1][x] = 0;
    }
    REP(j,1,n)
         values[2][j] = 1;
    REP(j,1,k2)
    {
        int x;
        cin >> x;
        values[2][x] = 0;
    }
    REP(j,1,n)
         values[3][j] = 1;
    REP(j,1,k3)
    {
        int x;
        cin >> x;
        values[3][x] = 0;
    }
    REP(i,1,n)
        pre[i] = pre[i-1] + values[1][i];
    int sum = 0;
    for(int i = n;i>=0;i--)
    {
        if(i == n)
            dp[3][i] = 0;
        else
        {
            sum += values[3][i+1];
            dp[3][i] = sum;
        }
    }
    Create(1,1,n);
    int minim = min(pre[n],dp[3][0]);
    for(int i = n-1;i>=0;i--)
    {
        updateRange(1,1,n,i+1,n,values[2][i+1]);
        int val;
        if(i == 0)
            val = min(dp[3][0],query(1,1,n,1,n));
        else
            val = query(1,1,n,i,n);
        dp[2][i] = pre[i]+val;
        minim =  min(minim,dp[2][i]);
    }
    cout << minim;
}   

