#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
int a[2];
ll n;
int k;
set<ll> s;
void xuly(int x,ll val)
{
    if(val>n)return;
    if(val<=n)
        s.insert(val);
    if(x>k) return ;
    for(int i=0; i<=1; i++)
    {
        xuly(x+1,val*10+a[i]);
    }
}
void solve()
{
    cin>>n;
    string ss=to_string(n);
    k=ss.size();
    s.clear();
    for(int i=0; i<=9; i++)
    {
        for(int j=i; j<=9; j++)
        {
            a[0]=i;
            a[1]=j;
            xuly(1,ll(0));
        }
    }
    cout<<s.size()-1<<endl;
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
