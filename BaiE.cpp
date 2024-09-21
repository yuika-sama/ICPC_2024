#include <bits/stdc++.h>
#define fi first
#define l first.first
#define r first.second 
#define idx second  
#define pii pair<int,int>
#define piii pair< pii, int> 
#define ll long long
#define pb1(x,y,z) push_back({{x,y},z});
using namespace std;

void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
template <class T> class BIT {
  private:
    int size;
    vector<T> bit;
    vector<T> arr;
    vector<T> v;

  public:
    BIT(int size) : size(size), bit(size + 1),v(size+1,0), arr(size+1) {}
    void add(int ind, T val) {
        for (; ind <= size; ind += ind & -ind) { bit[ind] ^= val; }
    }
    T pref_xorr(int ind) {
        T total = 0;
        for (; ind > 0; ind -= ind & -ind) { total ^= bit[ind]; }
        return total;
    }
};
bool cmp(piii & a , piii & b){
    return a.r < b.r;
}
void sol(){
    int n,q;
    cin >>n;
    BIT<int> bit(n);
    vector<int> v(n+2),pref_xor(n+1);
    map<int, int> mp, vs;
    for(int i =1 ;i<=n;i++){
        cin >>v[i];
        vs[v[i]] =-1;
        if(!mp[v[i]]){
            mp[v[i]] =i;
        }
        if(i==1) pref_xor[i] =v[i];
        else {
            pref_xor[i] = pref_xor[i-1] ^v[i];
        }
    }
    cin >>q;
    vector< pair<pii, int> > query;
    for(int i =0 ;i<q;i++){
        int x, y;
        cin >> x>>y;
        query.pb1(x,y,i);
    }
    sort(query.begin(),query.end(), cmp);
    vector<int> ans(q);
    int j =0;
    for(int i =1 ;i<=n;i++){
        if(vs[v[i]]!=-1){
            bit.add(vs[v[i]], v[i]);
        }
        vs[v[i]]= i;
        bit.add(i,v[i]);
        while(j< q&&i == query[j].r){
            int all = pref_xor[query[j].l-1]^pref_xor[query[j].r];
            int ld= bit.pref_xorr(query[j].l-1),rd=bit.pref_xorr(query[j].r);
            int distinct= ld^rd;
            ans[query[j].idx] = all ^ distinct;
            j++;
        }
    }
    for(int i = 0 ;i<q;i++) cout<<ans[i]<<'\n';
}
int32_t main(){
    fastio();
    int t=1;
    //cin >> t;
    while(t--) {
        sol();
    }
}