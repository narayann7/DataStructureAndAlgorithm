#include<bits/stdc++.h>
using namespace std;


//=======================
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
typedef vector<int>   vi;
typedef vector<ll>    vl;
const int mod = 1000000007;
//=======================

vector<vector<int>> dp(10000, vector<int>(10000, -1));

int count(string str, string str1, ll l, ll l1)
{

if(l==0)
  return l1;
if(l1==0)
  return l;

if (dp[l][l1] != -1)
        return dp[l][l1];
    else
{
if(str[l-1]==str1[l1-1])
  return dp[l][l1]=count(str,str1,l-1,l1-1);
else
  return dp[l][l1]=min(count(str,str1,l,l1-1)+1,min(count(str,str1,l-1,l1)+1,count(str,str1,l-1,l1-1)+1));
}
}

void solve() {

  string str, str1;
  cin>>str;
  cin>>str1;

  cout << count(str, str1, str.length(), str1.length()) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}