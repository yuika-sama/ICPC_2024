#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> ii;
int t;

void solve()
{
    string s;
    cin>>s;
    stack<char> st;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(st.empty()) st.push(s[i]);
        else{
            if(s[i]!=st.top()) st.pop(),ans+=2;
            else st.push(s[i]);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    solve();
}
