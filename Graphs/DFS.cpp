//DFS implementation
#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph
{
    private:
        vector<string>colour;
        vector<int>start_time;
        vector<int>end_time;
        vector<int>parent;
        int n;
        int time;
        list<int> *graph;
    public:
        Graph(int n)
        {
            n=n;
            time=0;
            colour.assign(n,"White");
            start_time.assign(n,-1);
            end_time.assign(n,-1);
            parent.assign(n,-1);
            graph=new list<int>[n];
        }
        void add_edge(int vertex1,int vertex2)
        {
            graph[vertex1].push_back(vertex2);
            graph[vertex2].push_back(vertex1);
        }
        void dfs_helper(int source)
        {
            time=time+1;
            start_time[source]=time;
            colour[source]="Green";
            parent[source]=-1;
            list<int>::iterator i;
            cout<<source<<endl;
            for(i=graph[source].begin();i!=graph[source].end();i++)
            {
                if(colour[*i]=="White")
                {
                    colour[*i]="Green";
                    parent[*i]=source;
                    dfs_helper(*i);
                }
            }
            time=time+1;
            colour[source]="Black";
            end_time[source]=time;

        }
        void dfs(int source)
        {
            for(int i=source;i<n;i++)
            {
                if(colour[i]=="White")
                {
                    dfs_helper(i);
                }
            }
        }
};

int main()
{
    Graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    g.dfs(2);
}