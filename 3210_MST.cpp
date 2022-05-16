///Made by Arjun 3210
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int nodes,edges;
    int pat[100];

    vector< pair<int,pair<int,int> > > p;

    int a[100][100];

    bool VisitFlag[100];
public:
    Graph()
    {
        for(int i=0;i<100;i++)
        {
            pat[i]=i;
        }

        nodes = 0;
        edges = 0;
    }

    int f_root(int);

    void m_union(int, int);

    void InsertGraph();

    void KruxAlgo();

    void PrimsAlgo();
};

void Graph :: InsertGraph()
{
    cout << "Enter count of nodes and edges"<< endl;
    cin >> nodes >> edges;
    cout << "Enter Edges and Weight" << endl;
    for(int i=0 ; i<edges ; i++)
    {
        int edgex,edgey,weight;
        cin >> edgex >> edgey >> weight;
        p.push_back({weight,{edgex - 1,edgey - 1}});

        a[edgex-1][edgey-1] = weight;

        a[edgey-1][edgex-1] = weight;
    }
}

void Graph:: m_union(int x,int y)
{
    pat[x]=pat[y];
}

int Graph:: f_root(int x)
{
    if(pat[x]==(x))
        {return x;}
    else
        {return (f_root(pat[x]));}
}

void Graph::KruxAlgo()
{
    int CostMin = 0;
    sort(p.begin(),p.end());
    cout<<"MST:\n";
    for(int i=0;i<nodes + 1;i++)
        {
            if(f_root(p[i].second.first)!= f_root(p[i].second.second))
            {
                cout<<"Path Edges: "<<p[i].second.first+1<<" "<<p[i].second.second+1<<" Weight: "<<p[i].first<<"\n";
                CostMin += p[i].first;
                m_union(f_root(p[i].second.first),f_root(p[i].second.second));
        }
    }
    cout<<"Kruksal Min Span Tree Cost: "<<CostMin<<"\n";
}
void Graph::PrimsAlgo()
{
    cout<<"MST\n";
    memset(VisitFlag,false,sizeof(VisitFlag));
	VisitFlag[0] = true;
	int CostMin = 0;
	for(int k=0 ; k < nodes-1 ; k++)
        {
            int min = INT_MAX;
            int start,end;
            for(int i=0 ; i < nodes ; i++)
            {
                if(VisitFlag[i] == false)
                    continue;
                for(int j=0 ; j< nodes ; j++)
                {
                    if(a[i][j]==0 || VisitFlag[j]==true)
                        continue;
                    if(a[i][j] < min)
                    {
                        start = i;
                        end = j;
                        min = a[i][j];
	  			}
	  		}
	  	}
	  		cout << "Path Edges: " << start+1 << " " << end+1<<" Weight: " <<a[start][end] << endl;

	  		CostMin += a[start][end];

	  		VisitFlag[start] = true;

			VisitFlag[end] = true;
	}
  	cout << "Prim's Min Span Tree Cost: " << CostMin << endl;
}
int main()
{
    int choice;
    Graph mst;
    cout<<"\n Min Span Tree by Arjun 3210";
    while(1)
    {
        cout << "\n";
		cout << "1. Insert into Graph \n" ;
		cout << "2. Kruksal's Algorithm\n";
		cout << "3. Prim's Algorithm\n";
		cout << "4. Exit\n";

		cin >> choice;

		if(choice == 1)
                mst.InsertGraph();
        else if(choice == 2)
                mst.KruxAlgo();
        else if(choice == 3)
                mst.PrimsAlgo();
        else
               break;
    }
    return 0;
}
