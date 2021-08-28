#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll>    vl;
const int mod = 1000000007;


void solve() {
  ll n, target;

  cin >> n;
  cin >> target;

  vl v(n), hash(target + 1, INT_MAX);
  for (ll i = 0; i < n; ++i)
    cin >> v[i];

  hash[0] = 0;
  for (ll j = 0; j < n; j++)
    hash[v[j]] = 1;
  ll ans = 0, count = 0;


  for (ll i = 1; i <= target; i++)
  {


    for (ll j = 1; j <= n; j++)
    {

      if (hash[i] > v[j])
      hash[i] = min(hash[i] , hash[i - v[j]] + 1);

    }

  }
  if (hash[target] != INT_MAX)
    cout << hash[target] << "\n";
  else
    cout << "-1" << "\n";
}

int main() {

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

}




