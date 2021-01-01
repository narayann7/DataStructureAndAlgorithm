//leetcode no. : 1143 
// only the logic part
//dp


int longestCommonSubsequence(string s1, string s2)
{
    vector<vector<int>> v(s1.length() + 1, vector<int>(s2.length() + 1, 1));
    for (int i = 0; i < s1.length() + 1; i++)
        v[i][0] = 0;
    for (int i = 0; i < s2.length() + 1; i++)
        v[0][i] = 0;

    for (int i = 0; i < s1.length(); i++)
    {

        for (int j = 0; j < s2.length(); j++)
        {
            if (s1[i] == s2[j])
                v[i + 1][j + 1] = v[i][j] + 1;
            else
                v[i + 1][j + 1] = max(v[i + 1][j], v[i][j + 1]);
        }
    }
    return v[s1.length()][s2.length()];
}