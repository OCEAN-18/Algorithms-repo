//Implementation of bfs
#include<iostream>
#include<queue>
#include<list>
#include<vector>

using namespace std;

class Graph
{
    private:
        vector<string>colour;//WHITE==NOT VISITED,GREEN=VISITED WORK IN PROGRESS,BLACK=VISITED WORK COMPLETED
        vector<int>distance;//DISTANCE FOR SOURCE TO NODE(CONSIDERED 1 FOR EACH EDGE IN BETWEEN)
        vector<int>parent;//PARENT NODE
        list<int> *graph;//CONTAINER FOR GRAPH
        int n;
    public:
        Graph(int n)//CONSTRUCTOR JUST ASSIGNS
        {
            n=n;
            colour.assign(n,"White");
            distance.assign(n,0);
            parent.assign(n,-1);
            graph=new list<int>[n];
        }
        void add_edge(int vertex1,int vertex2)
        {
            graph[vertex1].push_back(vertex2);
            graph[vertex2].push_back(vertex1);
        }
        void bfs_helper(int source)//THIS FUNCTION WOULD WORK AS A BFS IF WE DONT HAVE DISJOINTED GRAPHS
        {
            queue<int>q;
            q.push(source);
            colour[source]="Green";
            distance[source]=0;//SOURCE DISTANCE IS 0
            parent[source]=-1;//SOURCE DOESNT HAVE PARENTS
            while(!q.empty())
            {
                int ans=q.front();
                q.pop();
                cout<<ans<<endl;
                list<int>::iterator i;
                for(i=graph[ans].begin();i!=graph[ans].end();i++)
                {
                    if(colour[*i]=="White")
                    {
                        colour[*i]="Green";
                        distance[*i]=distance[ans]+1;
                        parent[*i]=ans;
                        q.push(*i);
                    }
                }
                colour[ans]="Black";
            }  
        }
        void bfs(int source)//WOULD PROVIDE EXTRA COVERAGE FOR DISJOINTED GRAPHS
        {
            for(int i=source;i<n;i++)
            {
                if(colour[i]=="White")
                {
                    bfs_helper(i);
                }
            }
        }
};

int main()
{
    Graph g(7);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(2,5);
    g.add_edge(2,6);
    g.bfs(1);

}
