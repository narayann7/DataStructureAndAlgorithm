//gfg
//only the the logic part

/*
struct Item{
    int value;
    int weight;
};
*/
bool comp(pair<double, pair<int, int>> a, pair<double, pair<int, int>> b)
{

    return (a.first > b.first);
}

// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    vector<pair<double, pair<int, int>>> v;

    for (int i = 0; i < n; i++)
        v.push_back({(double)arr[i].value / arr[i].weight, {arr[i].value, arr[i].weight}});

    sort(v.begin(), v.end(), comp);

    double vv = 0;
    int w2 = 0;
    for (int i = 0; i < n; i++)
    {

        if (w2 + v[i].second.second <= W)
        {
            vv = vv + v[i].second.first;
            w2 = w2 + v[i].second.second;
        }
        else
        {
            int y = W - w2;
            vv += v[i].second.first * ((double)y / v[i].second.second);
            break;
        }
    }
    return vv;
}