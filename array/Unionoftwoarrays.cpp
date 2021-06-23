//gfg

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;
        int arr[n], brr[m];

        unordered_set<int> s;

        // for each element in the array
        // insert the element in the set
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            s.insert(arr[i]);
        }

        // for each element in another array
        // insert the elements in set
        // Keep in mind set does not contains duplicates
        for (int i = 0; i < m; i++)
        {
            cin >> brr[i];
            s.insert(brr[i]);
        }

        // now the set contains the elements which are there in both the arrays (distinct elements)
        cout << s.size() << endl;
    }

    return 0;
}
//code contributed by: narayan
//git: narayann7
