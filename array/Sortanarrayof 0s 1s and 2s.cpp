//gfg 

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n;
        cin >> n;
        int a = 0, b = 0, c = 0;
        int arr[n];
        int i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        for (i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                a++;
            if (arr[i] == 1)
                b++;
            if (arr[i] == 2)
                c++;
        }
        for (i = 0; i < n; i++)
        {
            if (c != 0 && b == 0 && a == 0)
            {
                arr[i] = 2;
                c--;
            }
            if (b != 0 && a == 0)
            {
                arr[i] = 1;
                b--;
            }
            if (a != 0)
            {
                arr[i] = 0;
                a--;
            }
        }
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        t--;
    }
}

//code contributed by: narayan
//git: narayann7
