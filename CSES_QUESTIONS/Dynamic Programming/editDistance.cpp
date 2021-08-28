#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<int>   vi;


int count(string str, string str1)
{
  int dp[str.length()+1][str1.length()+1];

  for (int i = 0; i <=str.length(); ++i)
  {
    for (int j = 0; j <= str1.length(); ++j)
    {

      if (i == 0)
        dp[i][j] = j;
      else if (j == 0)
        dp[i][j] = i;
      else if (str[i - 1] == str1[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));

      }
  }
  return dp[str.length()][str1.length()];


}

void solve() {

  string str, str1;
  cin >> str;
  cin >> str1;

  cout << count(str, str1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}