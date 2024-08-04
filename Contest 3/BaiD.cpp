#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
const int maxn=1e5+5;
ll a[maxn];
ll s[maxn];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++ ){
        cin>>a[i];
        a[i]=a[i]%m;
    }
    s[0]=0;
    map<int,int> mp;
    ll ans=0;
    mp[0]=1;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        s[i]=s[i]%m;
        ans+=mp[s[i]];
        mp[s[i]]++;
    }

    cout<<ans<<endl;
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
