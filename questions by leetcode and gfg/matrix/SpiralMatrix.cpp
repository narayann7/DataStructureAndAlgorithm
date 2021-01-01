//leetcode no. :54
//only the code part

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &v)
    {

        int mm = v[0].size();
        int n = v.size();

        int n1 = 1, n2 = n, n3 = mm, m = 0, m1 = 0, xx = n;
        n = n * mm;

        n1 = 1;
        vector<int> vv;

        do
        {
            if (vv.size() == n)
                break;
            for (int i = m; i < n3; i++)
            {
                int x;
                x = v[m][i];
                vv.push_back(x);
            }
            m++;
            if (vv.size() == n)
                break;
            for (int i = m; i < n2; i++)
            {
                int x;
                x = v[i][n3 - 1];
                vv.push_back(x);
            }
            if (vv.size() == n)
                break;
            for (int i = n3 - 2; i >= m1; i--)
            {
                int x;
                x = v[n2 - 1][i];
                vv.push_back(x);
            }
            n2--;

            for (int i = n2 - 1; i >= m; i--)
            {
                int x;
                x = v[i][m1];
                vv.push_back(x);
            }
            m1++;
            n3--;

        } while (vv.size() != n);

        for (int i = 0; i < vv.size(); i++)
            cout << vv[i] << " ";

        return vv;
    }
};