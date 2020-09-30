///IMPLEMENTATION OF DFS;
#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
    private:
        int V;
        list<int> *adj;
        int count;
        void dfs_helper(int s,bool visited [])
        {
            visited[s]=true;
            cout<<s<<" "<<endl;
            list<int>::iterator i;
            for(i=adj[s].begin();i!=adj[s].end();i++)
            {
                if(!visited[*i])
                {
                    dfs_helper(*i,visited);
                }
            }

        }
    public:
        Graph(int V)
        {
            count=0;
            this->V=V;
            adj=new list<int>[V];
        }
        void add_edge(int a,int b)
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        void dfs()
        {
            bool *visited=new bool [V];
            for(int i=0;i<V;i++)
            {
                visited[i]=false;
            }
            for(int i=0;i<V;i++)
            {
                if(!visited[i])
                {
                    dfs_helper(i,visited);
                    count++;
                }
            }
            cout<<"Count:"<<count;
            
        }

};

int main()
{
    Graph g(5); 
    g.add_edge(0,1);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(3,0);
    
  
    cout << "Following is Depth First Traversal"<<endl; 
    g.dfs(); 
  
    return 0; 
}