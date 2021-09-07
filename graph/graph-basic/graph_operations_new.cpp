#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<ll>  vl;


template<typename T>
class Graph{

    int v;
    list<int> *L;
    /*
         L is list of int , but we want array of list

         so list<int> l[size]; 
         but we dont know the size size in given in runtime

         L=new list<int>[size] //dynamic creating array of list

         so we create a pointer to list of array in constructor.

         L[0] -----> [1,2,3] //will have a linkedList
         L[1] , L[2]...... will have same

    */
public:

    Graph(int v)
    {
        this->v=v;
        L=new list<int>[v];//initializing the sizeof the array of list
    }


    void addEdge(int x,int y)
    {
        L[x].push_back(y);
        L[y].push_back(x);
    }

    void printAdjList(){


        for(int i=0;i<v;i++)
        {
            for(auto listElement:L[i])
                cout<<listElement<<" ";

            cout<<endl;

        }

    }


};

template<typename T>
class WeightedGraph{

    int v;
    unordered_map<T,list<pair<T,int>>> graph;

    unordered_map<T,int> isVisted;

public:
    WeightedGraph(int v)
    {
        this->v=v;
    }

    void addEdge(T from ,T to ,int weight,bool biDirectional)
    {

        graph[from].push_back(make_pair(to,weight));

        if(!biDirectional)
            graph[to].push_back(make_pair(from,weight));


    }
    void makeNil(){

     for(auto i:graph)
        isVisted[i.first]=0;
}


void printWeightAdjList()
{
    for(auto i:graph)
    {
        cout<<i.first<<"--> ";

        for(auto j:i.second)
        {
            cout<<"("<<j.first<<","<<j.second<<")"<<" , ";
        }
        cout<<endl;
    }
}

void BFS(T start)
{
   makeNil();

   queue<T> qu;

   qu.push(start);


   isVisted[start]=1;

   while(!qu.empty())
   {


    string top=qu.front();


    for(auto i:graph[top])
    {

        if(isVisted[i.first]==0){

            qu.push(i.first);

            isVisted[i.first]=1;
        }

    }
    cout<<top<<" , ";
    qu.pop();

}
}

void dfsRecurvise(T start)
{
    cout<<start<<" , ";
    isVisted[start]=1;


    for(auto i:graph[start])
    {
        if(isVisted[i.first]==0)
            dfsRecurvise(i.first);
    }

}

void DFS(T start){
    makeNil();
    dfsRecurvise(start);

}


    
};


int main() {

}


/*
notes

BFS is ittreative way , DFS is rrecursion

topological sort

class Solution
{
    public:
    map<int,int>mp;
    list<int>l;
    
    void dfs(int n,vector<int> adj[])
    {
        mp[n]=1;
        
        for(auto i: adj[n])
        {
            if(mp[i]==0)
            {
                dfs(i,adj);
          
            }
        }
         l.push_front(n);
    }
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<int> v;
        for(int i=0;i<V;i++)
        mp[i]=0;
        for(int i=0;i<V;i++)
         if(mp[i]==0)
        dfs(i,adj);
        for(auto i:l)
        v.push_back(i);
        return v;
           
           
        
        // code here
    }
};


*/




/*
dump


    //Graph<int> gp(3);
    // gp.addEdge(0,1);
    // gp.addEdge(0,2);
    // gp.addEdge(1,2);
    // gp.printAdjList();


    // WeightedGraph<string> wg(4);
    // wg.addEdge("a","b",20,false);
    // wg.addEdge("a","d",30,false);
    // wg.addEdge("a","c",10,false);
    // wg.addEdge("c","d",40,false);
    // wg.addEdge("c","e",40,false);
    // wg.addEdge("b","e",40,false);
    // wg.addEdge("d","e",40,false);
    // wg.printWeightAdjList();
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;

    // wg.BFS("b");

    // cout<<endl;
    // cout<<endl;


    // wg.DFS("b");







*/

