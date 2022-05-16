#include<bits/stdc++.h>

using namespace std;

class graph{

public:

    map <int, list<int>>adj;

    map <int, bool>vis;

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
    void DFS(int v)
    {
        vis[v] = true;

        cout<<v;

        list<int>::iterator i;
        for(i = adj[v].begin(); i!=adj[v].end();  i++)
        {
            if(!vis[*i])
                DFS(*i);
        }
    }
};

int main()
{
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
}
