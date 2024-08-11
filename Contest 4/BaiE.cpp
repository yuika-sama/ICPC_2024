#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;

void solve()
{
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=k+1;i<=n;i++)
    {
        int tmp=n/i;
        ans+=(i-1-k+1)*tmp;
        tmp=i*tmp;
        if(tmp+k<=n) ans+=(n-(tmp+k)+1);
        //cout<<ans<<endl;
    }
    if(k==0) ans-=n;
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
