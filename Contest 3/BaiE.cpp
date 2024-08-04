#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
const int maxn=1e6+5;
int a[maxn];
int l[maxn];
int r[maxn];
void solve()
{
    int n;
    cin>>n;
    vector<int>ans;
    for(int i=1;i<=n;i++) cin>>a[i];
    l[0]=0;
    for(int i=1;i<=n;i++)
        l[i]=max(l[i-1],a[i]);
    r[n+1]=100000000;
    for(int i=n;i>=1;i--)
        r[i]=min(r[i+1],a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]>l[i-1]&& a[i]<r[i+1]) ans.push_back(a[i]);
    }
    int leng=ans.size();
    cout<<leng<<" ";
    for(int i=0;i<min(100,leng);i++)
        cout<<ans[i]<<" ";
    cout<<endl;
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
