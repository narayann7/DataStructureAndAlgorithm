#include<bits/stdc++.h>
using namespace std;


//=======================
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
typedef vector<int>   vi;
typedef vector<ll>    vl;
const int mod = 1000000007;
//=======================


void solve() {

  vl v;
  ll n;
  cin >> n;
  if (n == 0)
  {
    cout << "0" << "\n";
    return;
  }

  while (1)
  {
    if (n == 1)
    {
      v.push_back(1);
      break;

    }
    v.push_back(n);

    if (n % 2 == 0)
      n = n / 2;
    else
    {
      n = n * 3;
      n += 1;
    }

  }

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << "\n";




}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}

