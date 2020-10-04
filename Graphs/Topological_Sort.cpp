#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;
class Graph
{
    private:
        vector<string>colour;//WHITE==NOT VISITED,GREEN=VISITED WORK IN PROGRESS,BLACK=VISITED WORK COMPLETED
        vector<int>start_time;
        vector<int>end_time;
        vector<int>parent;//PARENT NODE
        int n;
        int time;
        list<int> *graph;//CONTAINER FOR GRAPH
    public:
        Graph(int n)
        {
            this->n=n;
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
        }
        void dfs_helper(int source,stack<int>& ans)
        {
            time=time+1;
            start_time[source]=time;
            colour[source]="Green";
            parent[source]=-1;
            list<int>::iterator i;
            for(i=graph[source].begin();i!=graph[source].end();i++)
            {
                if(colour[*i]=="White")
                {
                    colour[*i]="Green";
                    parent[*i]=source;
                    dfs_helper(*i,ans);
                }
            }
            time=time+1;
            colour[source]="Black";
            ans.push(source);//PUSHING IN STACK TO REVERSE THE ORDER VISITED BY DFS
            end_time[source]=time;

        }
        void dfs()//DFS MODIFIED FOR TOPOLOGICAL SORT,WOULD PROVIDE EXTRA COVERAGE FOR DISJOINTED GRAPHS
        {
            stack<int>ans;
            for(int i=0;i<n;i++)
            {
                if(colour[i]=="White")
                {
                    dfs_helper(i,ans);
                }
            }
            while(!ans.empty())
            {
                cout<<ans.top()<<" ";
                ans.pop();
                
            }
            cout<<endl;
            
        }
};

int main()
{
    Graph g(6); 
    g.add_edge(5, 2); 
    g.add_edge(5, 0); 
    g.add_edge(4, 0); 
    g.add_edge(4, 1); 
    g.add_edge(2, 3); 
    g.add_edge(3, 1); 
    g.dfs();
    
}
