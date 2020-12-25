#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define ll long long
typedef vector<int> vi;
vector<vi> ans;

void pre(vi &v, int ind)//main logic
{
    if (ind == v.size())
    {
        ans.push_back(v);
    }
    for (int i = ind; i < v.size(); i++)
    {
        swap(v[i], v[ind]);
        pre(v, ind + 1);
        swap(v[i], v[ind]);
    }
}

void solve()
{
    int i, j, n, m;
    vi v;
    cout << "enter the size" << endl;
    cin >> n;
    cout << "enter the elements" << endl;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    pre(v, 0);

    for (int i = 0; i < ans.size(); i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
//code contributed by: narayan
//git: narayann7
//email: laxminarayanreddy432@gmail.com

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
