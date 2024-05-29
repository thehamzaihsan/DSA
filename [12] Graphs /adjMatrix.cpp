#include <iostream>
#include <vector>
using namespace std;

void addedges(vector<vector<int>> &adj , vector<int> location){
    adj[location[0]][location[1]] = 1;
    adj[location[1]][location[0]] = 1;    
}

void display(vector<vector<int>> adj){
    for(int i = 0; i < adj.size(); i++){
        for(int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
void deleteEdges(vector<vector<int>> &adj, vector<int> location){
    adj[location[0]][location[1]] = 0;
    adj[location[1]][location[0]] = 0;
}
int main(){
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    addedges(adj, {0, 1});
    addedges(adj, {0, 2});
    addedges(adj, {1, 2});
    addedges(adj, {1, 3});
    display(adj);
}
