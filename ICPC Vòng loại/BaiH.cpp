#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#define ll long long
#define fi first 
#define se second
#define ii pair<int,int>
#define faster() {ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);}
#define int long long
#define db long double
#define sqrt sqrtl
#define bit(n,i) ((n>>i)&1)

using namespace std;

int count_one(int mask) {
	int res = 0;
	while (mask) {
		if (mask & 1) res++;
		mask >>= 1;
	}
	return res;
}

class Point {
public:
	ll x, y, z;
	Point() : x(0), y(0), z(0){}
	friend istream& operator >> (istream& input, Point& a) {
		input >> a.x >> a.y >> a.z;
		return input;
	}
};

int cal(Point a, Point b) {
	ll dis = b.z - a.z;
	ll res = abs(b.x -a.x) + abs(b.y - a.y) + max(0LL, static_cast<ll>(dis));
	return res;
}

int n, dp[1 << 18][18];
Point C[18];

int32_t main() {
	faster();
	cin >> n;
	for (int i = 0; i < n; i++) cin >> C[i];
	memset(dp, 0x3f, sizeof dp);
	/*for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			dp[mask][i] = 1e9;
		}
	}*/
	dp[1][0] = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		if (count_one(mask) == 1 || !(mask & 1)) continue;  //loai bo cac hanh trinh chi co 1 diem va khong xuat phat tu 1
		for (int i = 0; i < n; i++) {
			if (i == 0) continue; //bat buoc phai di tu diem 1
			if (bit(mask, i)) {
				int pre_mask = mask ^ (1 << i); //loai bo diem i (dung ^ cho chuyen nghiep, khong thi dung dau tru)
				for (int j = 0; j < n; j++) {
					if (bit(pre_mask, j)) {
						dp[mask][i] = min(dp[mask][i], dp[pre_mask][j] + cal(C[j], C[i]));
					}
				}
			}
		}
	}
	int ans = 1e9;
	for (int i = 1; i < n; i++) ans = min(ans, dp[(1 << n) - 1][i] + cal(C[i], C[0]));
	cout << ans << endl;
}