//leetcode 42 number.
//its only the logic part




int trap(vector<int> &height)
{

    if (height.size() == 0)
        return 0;
    vector<int> v1(height.size(), -1111);
    vector<int> v2(height.size(), -1111);
    vector<int> v3(height.size(), 0);

    int max = height[0];
    v1[0] = height[0];
    for (int i = 1; i < height.size(); i++)
    {
        if (max < height[i])
        {
            v1[i] = max;
            max = height[i];
        }
        else
            v1[i] = max;
    }
    max = height[height.size() - 1];

    for (int i = height.size() - 1; i >= 0; i--)
    {
        if (max < height[i])
        {
            v2[i] = max;
            max = height[i];
        }
        else
            v2[i] = max;
    }
    int sum = 0;

    for (int i = height.size() - 1; i >= 0; i--)
    {
        if (height[i] < min(v2[i], v1[i]))
            v3[i] = min(v2[i], v1[i]) - height[i];
        else
            v3[i] = 0;

        sum += v3[i];
    }
    return sum;
}

//code contributed by: narayan
//git: narayann7
//email: laxminarayanreddy432@gmail.com
//leetcode: narayann7