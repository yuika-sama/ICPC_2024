#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
int n;
int a[100005];
void solve()
{
    cin>>n;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        int x=a[i];
        while(x%2==0)
        {
            ans++;
            x=x/2;
        }
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
