///Made by Arjun 3311
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int vertex;
    int **adj;

public:
    Graph(int vertex)
    {
        this->vertex = vertex;
        InitAdj();
    }
    Graph()
    {
        cout<<"\nEnter Number of Vertex: ";
        cin>>this->vertex;
        InitAdj();
    }

    void InitAdj()
    {
        adj = nullptr;
        adj = new int *[vertex];
        for(int i = 0; i< vertex; i++)
        {
            adj[i] = new int[vertex];
        }
        for(int i = 0; i<vertex; i++)
        {
            for(int j = 0; j<vertex; j++)
            {
                adj[i][j] = 0;
            }
        }

    }

    void CreateGraph()
    {
        int edge;
        cout<<"\nEnter Number of Edges: ";
        cin>>edge;

        for(int i = 0; i< edge; i++)
        {
            int x, y, w;
            cout<<"\nEnter edge "<<i<<" :";
            cin>>x>>y;
            cout<<"\nEnter weight :";
            cin>>w;
            adj[x][y] = w;
            adj[y][x] = w;
        }

    }
    void ShowGraph()
    {

        for(int i= 0;i <vertex; i++)
        {
            for(int j = 0; j< vertex; j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }

    }

    int isnot(int m, int a[])
    {

        for(int i = 0; i<vertex; i++)
        {
            if(m == a[i])
            {
                return 0;
            }
        }
        return 1;

    }

    void Dijkstra()
    {
        queue <int> nxt;
        int st;
        cout<<"\nEnter start vertex: ";
        cin>>st;
        nxt.push(st);
        int vis[vertex];
        for(int i = 0; i<vertex;i++)
        {
            vis[i]= -1;
        }
        int dis[vertex];
        for(int i = 0; i<vertex;i++)
        {
            dis[i]= INT_MAX;
        }
        dis[st] = 0;

        while(!nxt.empty())
        {
            int val = nxt.front();
            nxt.pop();

            if(isnot(val,vis) == 1)
            {
                for(int i = 0;i < vertex; i++)
                {
                    if(adj[val][i]!=0)
                    {
                        int sub = adj[val][i] + dis[val];

                        if(sub < dis[i])
                        {
                            dis[i] = sub;
                            nxt.push(i);
                        }
                    }

                }
            }
        }

        cout<<"\nDIJKSTRA'S SHORTEST PATH ALGORITHM";
        for(int i = 0;i < vertex; i++)
        {
            cout<<"\nDistance from Vertex "<<i<<": "<<dis[i]<<"\n";
        }
    }

};

int main()
{
    Graph Obj;
    Obj.CreateGraph();
    Obj.ShowGraph();
    Obj.Dijkstra();
}

