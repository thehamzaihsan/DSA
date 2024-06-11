#include <iostream>
using namespace std;
class Graph
{
    int V;
    int **adj;
    int *sizes;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new int *[V];
        sizes = new int[V];
        for (int i = 0; i < V; ++i)
        {
            adj[i] = new int[V];
            sizes[i] = 0;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < V; ++i)
        {
            delete[] adj[i];
        }
        delete[] adj;
        delete[] sizes;
    }

    void addEdge(int v, int w)
    {
        adj[v][sizes[v]++] = w;
    }

    void BFS(int s)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i)
            visited[i] = false;
        int *queue = new int[V];
        int front = 0, back = 0;
        visited[s] = true;
        queue[back++] = s;
        while (front != back)
        {
            s = queue[front++];
            cout << s << " ";
            for (int i = 0; i < sizes[s]; ++i)
            {
                int v = adj[s][i];
                if (!visited[v])
                {
                    visited[v] = true;
                    queue[back++] = v;
                }
            }
        }
        delete[] visited;
        delete[] queue;
    }

    void DFS(int s)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i)
            visited[i] = false;
        DFSUtil(s, visited);
        delete[] visited;
    }

private:
    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";
        for (int i = 0; i < sizes[v]; ++i)
        {
            int adj_v = adj[v][i];
            if (!visited[adj_v])
            {
                DFSUtil(adj_v, visited);
            }
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Breadth First Traversal (starting from vertex 0): ";
    g.BFS(0);
    cout << "\nDepth First Traversal (starting from vertex 0): ";
    g.DFS(0);
    cout << endl;
    return 0;
}
