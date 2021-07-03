 #include<bits/stdc++.h>
using namespace std;

//Increasing Array

//=======================
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
typedef vector<int>   vi;
typedef vector<ll>    vl;
const int mod = 1000000007;
//=======================



void solve() {
  ll ans = 0;
  ll n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++)
    cin >> a[i];
  for (i = 1; i < n; i++)
  {
    if (a[i - 1] > a[i])
    {
      ans += a[i - 1] - a[i];
      a[i] += a[i - 1] - a[i];
    }
  }

  cout<<ans<<'\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}

