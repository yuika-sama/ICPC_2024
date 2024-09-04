#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
const int maxn=2*1e5+5;
int n,a[maxn];
int vv[1000005];
void solve()
{
    for(int i=1; i<=1000000; i++) vv[i]=0;
    cin>>n;
    map<int,int> m;
    for(int i=1; i<=n; i++) cin>>a[i],m[a[i]]++;
    vector<int> f;

    for(auto x: m)
        f.push_back(x.fi);
    int ans=0;
    if(f.size()==0) {cout<<0<<endl;
    return ;}
    if(f[0]==1 && m[1]==1) cout<<1<<endl;
    else
    {
        int length= f.size();
        for(int i=0;i<length;i++){
            for(int j=2*f[i];j<=f.back();j+=f[i]){
                vv[j]=1;
            }
        }
        int ans=0;
        for(int i=0;i<length;i++) if(vv[f[i]]==0 && m[f[i]]==1) ans++;
        cout<<ans<<endl;
    }
}

int main()
{
    //freopen("test.inp","r",stdin);
    //cin>>t;
        solve();
}
