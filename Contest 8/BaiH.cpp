#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;

void solve()
{
    int a,b,k;
    cin>>a>>b>>k;
    int r=a%b;
    vector<int> uoc;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    for(int i=1;i<=b;i++) if(b%i==0) uoc.push_back(i);
    int m=uoc.size();
    cout<<uoc[m-k]<<endl;
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
