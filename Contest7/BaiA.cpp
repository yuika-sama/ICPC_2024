#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,int> ii;
int t;
const int maxn=1e5+5;
ll a[maxn],b[maxn];
ii c[maxn];
int n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],c[i].fi=a[i]-b[i],c[i].second=i;
    sort(c+1,c+n+1);
    ll sum_a=0;
    ll sum_b=0;
    for(int i=1;i<=n;i++){
        sum_a+=a[i];
        sum_b+=b[i];
    }
    int d=0;
    int j=1;
    while(sum_a<sum_b){
        d++;
        sum_a-=a[c[j].se];
        sum_b-=b[c[j].se];
        j++;
    }
    cout<<n-d<<endl;
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
