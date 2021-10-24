#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
typedef vector<int> vi;
typedef pair<int, int> pii;

void slove()
{
    string s = "happybirthday";
    int c = 3;
    int j = 0;
    int g = 5;
    while (1)
    {
        if (s.length() == 1)
            break;

        for (int i = 0; i < c; i++)
        {
            
            j++;
            if (j > s.length())
                j = 0;
        }
        cout<<j<<endl;
        string ss = "";
        j--;
        if(j==-1)
            j=0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i != j)
                ss += s[i];
        }
        s = ss;
        cout << s << endl;

    }
    // j=2;
    // cout<<s.substr(0,j)+s.substr(j+1,s.length())<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    //  cin >> t;
    while (t--)
    {
        vi v = {};
        //vector<vi> vv(n,vector<int>(n,0));
        slove();
    }

    return 0;
}
