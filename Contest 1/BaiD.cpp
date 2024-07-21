#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
int n,st,en,u,d;
const int maxn=1e6+5;
int a[maxn];
int cx[maxn];
void solve()
{
    cin>>n>>st>>en>>u>>d;
    for(int i=1;i<=n;i++) a[i]=maxn,cx[i]=1;
    priority_queue<ii,vector<ii>, greater<ii>> q;
    a[st]=0;
    cx[st]=0;
    q.push({0,st});
    while(!q.empty())
    {
        int k=q.top().se;
        int val=q.top().fi;
        q.pop();
        int tmp=k+u;
        if(tmp<=n&&tmp>=1)
        {
            if(val+1< a[tmp])
            {
                q.push({val+1,tmp});
                a[tmp]=val+1;
            }
        }
        tmp=k-d;
        if(tmp<=n&&tmp>=1)
        {
            if(val+1< a[tmp])
            {
                q.push({val+1,tmp});
                a[tmp]=val+1;
            }
        }
    }
    if(a[en]==maxn) cout<<"-1"<<endl;
    else cout<<a[en]<<endl;
}
int main()
{
    //freopen("test.inp","r",stdin);
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}
