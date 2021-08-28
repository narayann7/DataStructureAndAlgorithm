#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>> &v, int size) // breadth for search
{
    queue<int> q;
    vector<int> ver(size + 1, 0);
    q.push(1);
    ver[1] = 1;
    //starting from first element try to figure it out
    while (!(q.empty()))
    {
        int x;

        x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 1; i < size + 1; i++)
        {
            if (v[x][i] == 1 && ver[i] == 0)
            {
                q.push(i);
                ver[i] = 1;
            }
        }
    }
}
void DFS(int x, vector<vector<int>> &v, int vis[], int size)
{
    //where x is the first node
    //vis[] is for checking the node is visted or not
    if (vis[x] == 0)
    {
        cout << x << " ";
        vis[x] = 1;
    }

    for (int i = 1; i < size + 1; i++)
        if (v[x][i] == 1 && vis[i] == 0)
        {
            DFS(i, v, vis, size);
        }
}
void displayAdMatrix(vector<vector<int>> &v, int size) //for displaying the adjacent matrix
{
    for (int i = 0; i < size + 1; i++)
    {
        v[0][i] = i;
    }
    for (int i = 0; i < size + 1; i++)
    {
        v[i][0] = i;
    }
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            cout << v[i][j] << " ";
        }

        cout << endl;
    }
}

void WeightedAdjMatrix(vector<vector<int>> &v, int size, int e)
{
    for (int i = 0; i < e; i++)
    {
        // cout << "enter two edges " << endl;
        int a, b, w;
        cin >> a >> b;
        // cout << "enter the weight" << endl;
        cin >> w;
        v[a][b] = w;
        v[b][a] = w;
    }
    // displayAdMatrix(v, size);
}
void PrimsAlgo(vector<vector<int>> &v, int size) //need to debug
{

    /*
    1.first find the min coast edge
    2.
    */
    vector<pair<int, int>> vp(size - 1);
    int max = INT_MAX;
    for (int i = 1; i < size + 1; i++)
    {

        for (int j = i; j < size + 1; j++)
        {
            if (v[i][j] < max)
            {
                max = v[i][j];
                vp[0].first = i;
                vp[0].second = j;
            }
        }
    }
    vector<int> near(size + 1, 10);
    near[vp[0].first] = 0;
    near[vp[0].second] = 0;

    for (int i = 1; i < near.size(); i++)
    {
        if (near[i] != 0)
        {
            if (v[i][vp[0].first] < v[i][vp[0].second])
                near[i] = vp[0].first;
            else
                near[i] = vp[0].second;
        }
    }

    int ed = 1;
    while (ed != (size - 1))
    {
        for (int i = 0; i < near.size(); i++)
        {
            cout << near[i] << " ";
        }
        cout << endl;

        int min = INT_MAX;
        for (int i = 1; i < near.size(); i++)
        {
            if (near[i] != 0)
            {
                if (v[i][near[i]] < min)
                {
                    min = v[i][near[i]];
                    vp[ed].first = i;
                    vp[ed].second = near[i];
                }
            }
        }
        near[vp[ed].first] = 0;
        near[vp[ed].second] = 0;

        for (int i = 1; i < near.size(); i++)
        {
            if (near[i] != 0)
            {
                if (v[i][vp[ed].first] < v[i][vp[ed].second])
                    near[i] = vp[ed].first;
                else
                    near[i] = vp[ed].second;
            }
        }
        ed++;
    }
    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }
}

// bool detectCycle(vector<vector<int>> &v, int size) // breadth for search
// {
//     //assuming first node as 1
//     queue<int> q;
//     int par = 1, flag = 0;
//     vector<int> ver(size + 1, 0);
//     q.push(1);
//     ver[1] = 1;

//     //starting from first element try to figure it out
//     while (!(q.empty()))
//     {
//         int x;

//         x = q.front();
//         par = x;
//         q.pop();

//         for (int i = 1; i < size + 1; i++)
//         {
//             if (v[x][i] == 1)
//             {
//                 if (ver[i] == 0)
//                 {
//                     q.push(i);
//                     ver[i] = 1;
//                 }
//                 else
//                 {
//                     if (par != i)
//                         return true;
//                 }
//             }
//         }
//     }

//     return false;
// }
void displayAdList(vector<int> arr[], int size) //for displaying the adjacent list
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " ";
        for (int x : arr[i])
        {
            cout << x << " ";
        }

        cout << endl;
    }
}

void AdMatrixToList(vector<vector<int>> &v, vector<int> arr[], int size) //converting adjacent matrix to list
{

    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < size + 1; j++)
        {
            if (v[i][j] == 1)
            {
                arr[i - 1].push_back(j);
            }
        }
    }
}
vector<vector<int>> AdLIstToAdMatrix(vector<int> arr[], int size) //converting adjacent list to matrix
{
    vector<vector<int>> v(size + 1, vector<int>(size + 1, 0));
    for (int i = 0; i < size + 1; i++)
    {
        v[0][i] = i;
    }
    for (int i = 0; i < size + 1; i++)
    {
        v[i][0] = i;
    }
    for (int i = 0; i < size; i++)
    {

        for (int x : arr[i])
        {
            v[i + 1][x] = 1;
        }
    }
    return v;
}

void adjList(vector<int> arr[], int size, int e) //creating adjacent list
{

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a - 1].push_back(b);
        arr[b - 1].push_back(a);
    }
    displayAdList(arr, size);
}
void adjMatrix(vector<vector<int>> &v, int size, int e) //creating adjacent matrix
{

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    // displayAdMatrix(v, size);
    // cout << endl;
    // cout << endl;
    // BFS(v, size);
    // if (detectCycle(v, size))
    //     cout << "cycle is present" << endl;
    // else
    //     cout << "cycle is not present" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    //just to take input faster
    int s;

    cout << "enter number of nodes" << endl;
    cin >> s;
    cout << "enter the no. edges" << endl;
    int e;
    cin >> e;
    vector<int> ar[s];
    vector<vector<int>> v(s + 1, vector<int>(s + 1, 10));
    int vis[s + 1] = {0};
    // adjList(ar, s,e);
    // adjMatrix(v, s, e);
    WeightedAdjMatrix(v, s, e);
    PrimsAlgo(v, s);

    // DFS(1, v, vis, s);

    return 0;
}
