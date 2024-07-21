#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
const int maxn=1e5+5;
int a[maxn],n,m;
string s;
void solve()
{
    cin>>s>>m;
    n=s.size();
    for(int i=1;i<=m;i++)
    {
        int u;
        cin>>u;
        a[u]++;
    }
    a[0]=0;
    for(int i=1;i<=m;i++) {
        a[i]=a[i-1]+a[i];
    }
    for(int i=1;i<=m;i++)
    {
        if(a[i]%2==1){
            swap(s[i-1],s[n-i]);
        }
    }
    cout<<s<<endl;
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
