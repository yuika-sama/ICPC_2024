#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
int n,k;
const int maxn=105;
double a[maxn];
void solve()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    double ans=0,p;
    if(k==1)
    {
        sort(a+1,a+n+1);
        if(n%2==1) p=a[n/2+1];
        else p=(a[n/2]+a[n/2+1])/2;
        for(int i=1; i<=n; i++)
        ans+=abs(a[i]-p);
    }
    else
    {
        double tmp=0;
        for(int i=1; i<=n; i++) tmp+=a[i];
        p=tmp/n;
            for(int i=1; i<=n; i++)
        ans+=(a[i]-p)*(a[i]-p);
    }


    printf("%.2f",ans);
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
