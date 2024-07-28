#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;
int mm,n;
int a[1000];
void solve()
{
    cin>>n>>mm;
    map<int,int> m;
    for(int i=1; i<=n; i++) cin>>a[i],m[a[i]]++;
    priority_queue<ii,vector<ii>,less<ii>> q;
    for(auto x:m)
    {
        q.push({x.se,x.fi});
    }
    int k=q.top().fi;
    while(!q.empty()&&q.top().fi==k)
        q.pop();
    if(q.size()==0)
    {
        cout<<"NONE"<<endl;
        return;
    }
    int ans=q.top().fi;
    int vt=q.top().se;
    q.pop();
    while(!q.empty()&&q.top().fi==ans)
    {

        vt=q.top().se;
        q.pop();

    }
    cout<<vt<<endl;

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
