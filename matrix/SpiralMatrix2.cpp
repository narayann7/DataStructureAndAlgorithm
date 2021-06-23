//leetcode no. :59
//only the code part

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> v(n, vector<int>(n, 0));

        int n1 = 1, n2 = n, n3 = n, m = 0, m1 = 0, xx = n;
        n = n * n;

        do
        {
            for (int i = m; i < n2; i++)
                v[m][i] = n1++;
            m++;
            for (int i = m; i < n2; i++)
                v[i][n2 - 1] = n1++;

            n2--;

            for (int i = n2 - 1; i >= m1; i--)
                v[n3 - 1][i] = n1++;

            for (int i = n2 - 1; i >= m; i--)
                v[i][m1] = n1++;
            m1++;
            n3--;

        } while (n1 != n + 1);

        return v;
    }
};