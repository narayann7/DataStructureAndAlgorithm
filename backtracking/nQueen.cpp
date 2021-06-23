#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &v, int i, int j)
{

    int i1 = i, j1 = j;

    for (int k = i1; k >= 0; k--)
        if (v[k][j] == 'Q')
            return false;

    i1 = i, j1 = j;
    while (i1 >= 0 && j1 >= 0)
    {
        if (v[i1][j1] == 'Q')
            return false;
        i1--;
        j1--;
    }
    i1 = i, j1 = j;
    while (i1 >= 0 && j1 < v.size())
    {
        if (v[i1][j1] == 'Q')
            return false;
        i1--;
        j1++;
    }
    return true;
}
bool slove(vector<vector<char>> &v, int i, int n)
{
    if ((i) >= (n))
        return true;

    for (int j = 0; j < n; j++)
    {
        if (isSafe(v, i, j))
        {
            v[i][j] = 'Q';
            if (slove(v, i + 1, n))
                return true;

            v[i][j] = '.';
        }
    }
    return false;
}
//code contributed by: narayan
//git: narayann7
int main()
{

    int n;
    cout<<"enter the size "<<endl;

    cin >> n;
    vector<vector<char>> v(n, vector<char>(n, '.'));

    if (slove(v, 0, v.size()))
    {
        for (int i = 0; i < v.size(); i++)
        {

            for (int j = 0; j < v.size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "cant" << endl;
    }

    return 0;
}
