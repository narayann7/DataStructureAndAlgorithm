#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr1, int i, int j, int n)
{

    if ((arr1[i][j] == 1) && i < n && j < n)
        return true;
    else
    {
        return false;
    }
}

bool micePro(int **arr1, int i, int j, int n, int **sol1)
{

    if (i > n || j > n)
        return false;

    if ((i == (n - 1)) && (j == (n - 1)) && i == j)
    {
        if (arr1[i][j] == 1)
            sol1[i][j] = 1;
        return true;
    }

    if (isSafe(arr1, i, j, n))
    {
        
        sol1[i][j] = 1;
        if (micePro(arr1, i, j + 1, n, sol1))
        {
            return true;
        }
        if (micePro(arr1, i + 1, j, n, sol1))
        {
            return true;
        }

        sol1[i][j] = 0;
        return false;
    }
    return false;
}
//code contributed by: narayan
//git: narayann7
int main()
{

    int n;
    cout << "enter the size" << endl;
    cin >> n;

    int **arr = new int *[n];   //dynamic 2d array;
    for (int i = 0; i < n; i++) //to allocate memory in each row
        arr[i] = new int[n];
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int **sol = new int *[n];   //dynamic 2d array;
    for (int i = 0; i < n; i++) //to allocate memory in each row
    {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
    }
    if (arr[n - 1][n - 1] != 1) //if arr[n][n]!=1 then its not poss.
        cout << "cant" << endl;
    else if (micePro(arr, 0, 0, n, sol))
    {
        // cout << "yes" << endl;
        cout << "the pattern" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "cant" << endl;

    return 0;
}
// 5
// 1 0 0 0 0
// 1 1 0 0 0
// 1 1 1 0 1
// 0 0 1 1 0
// 1 1 1 1

// 3
// 1 0 0
// 1 1 0
// 0 1 1
