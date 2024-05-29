#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix
{
public:
    vector<vector<bool>> adj;
    int n;
    int m;
    GraphMatrix(int n, int m)
    {
        this->n = n;
        this->m = m;
        adj = vector<vector<bool>>(n, vector<bool>(n, 0));
    }
    GraphMatrix() {}
    void addedges(vector<int> location)
    {
        adj[location[0]][location[1]] = true;
        adj[location[1]][location[0]] = true;
        
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void deleteEdges(vector<int> location)
    {
        adj[location[0]][location[1]] = false;
        adj[location[1]][location[0]] = false;
    }
};