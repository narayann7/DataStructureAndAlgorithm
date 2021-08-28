#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll>    vl;
const int mod = 1000000007;

void solve() {
  ll n, c;

  cin >> n;

  vl v(n + 1, 0);

  v[0] = 1;
  for (ll i = 1; i <= n; i++)
  {

    if (i - 1 >= 0)
      v[i] += v[i - 1]%mod;
    if (i - 2 >= 0)
      v[i] += v[i - 2]%mod;
    if (i - 3 >= 0)
      v[i] += v[i - 3]%mod;
    if (i - 4 >= 0)
      v[i] += v[i - 4]%mod;
    if (i - 5 >= 0)
      v[i] += v[i - 5]%mod;
    if (i - 6 >= 0)
      v[i] += v[i - 6]%mod;

  }

  cout << v[n]%mod << "\n";

}

int main() {

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

}




