#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
const int mod= 1e9+7;
int n,t;
ll a[55];
ll c[102][102];
void solve()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++) cin>>a[i];
    c[0][0]=1;
    c[0][1]=1;
    c[1][1]=1;
    for(int i=1;i<=100;i++) c[i][0]=1,c[i][i]=1;
    for(int i=2;i<=100;i++)
    {
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j]%mod+c[i-1][j-1]%mod)%mod;
    }
    int d1=0;
    int d2=0;
    for(int i=1;i<=n;i++){
        if(a[i]%2==1) d1++;
        else d2++;
    }
    ll ans=0;
    if(t==0){
        ans++;
        for(int len=1;len<=n;len++){
            ll tmp=0;
            for(int i=0;i<=len;i+=2){
                if(d2>=len-i){
                    tmp=(tmp%mod+(c[d1][i]*c[d2][len-i])%mod)%mod;
                }
            }
            ans=(ans+tmp)%mod;
        }
    }
    else {
        for(int len=1;len<=n;len++){
            ll tmp=0;
            for(int i=1;i<=len;i+=2){
                if(d2>=len-i){
                    tmp=(tmp%mod+(c[d1][i]*c[d2][len-i])%mod)%mod;
                }
            }
            ans=(ans+tmp)%mod;
        }

    }
    cout<<ans<<endl;
}

int main()
{

        solve();

}
