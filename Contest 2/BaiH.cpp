#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
int n;
int a[50];
map<int,vector<int>>m;
set<int> ss;
bool bit(int x,int i)
{
    return (x>>i)&1;
}
void solve()
{
    cin>>n;
    int s=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    s=s/2;

    for(int mask =1; mask<(1<<n); mask++)
    {
        int sum1=0;
        for(int i=0; i<n; i++)
        {
            if(bit(mask,i))
            {
                sum1+=a[i];
                if(sum1>s) break;
            }
        }
        if(sum1>s) continue;
        int oke =0;
        if(m.find(sum1)==m.end()){
            m[sum1].push_back(mask);
        }
        else
        {
            for(int x:m[sum1])
            {
                if((x&mask)==0)
                {
                    ss.insert(sum1);
                    break;
                }
            }
            m[sum1].push_back(mask);
        }
    }
    cout<<ss.size()<<endl;
    for(auto x:ss)
        cout<<x<<" ";
    cout<<endl;
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
