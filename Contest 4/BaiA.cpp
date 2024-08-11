#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
ii a[10];
ii b[10];
bool cmp(ii x,ii y)
{
    if(x.se==y.se)
        return x.fi<y.fi;
    else return x.se<y.se;
}
int solve()
{
    for(int i=0;i<3;i++)
    {
        cin>>a[i].fi>>a[i].se;
        if(a[i].fi>a[i].se) swap(a[i].fi,a[i].se);
        b[i].fi=a[i].se;
        b[i].se=a[i].fi;
    }
    sort(a,a+3,cmp);
    //for(int i=0;i<3;i++) cout<<a[i].fi<<" "<<a[i].se<<endl;
    if(a[0].se==a[1].se&&a[2].se &&a[0].se ==a[0].fi+a[1].fi+a[2].fi) return a[0].se;
    if(a[0].se==a[1].se&& a[2].fi+a[0].se==a[2].se&&a[0].fi+a[1].fi==a[2].se) return a[2].se;
    if(a[0].se==a[1].fi&&a[0].fi+a[1].se==a[2].se&& a[2].fi+a[0].se==a[2].se) return a[2].se;
    return 0;
}

int main()
{
    //freopen("test.inp","r",stdin);
    //cin>>t;
    t=1;
    while(t--)
    {
        cout<<solve()<<endl;
    }
}
