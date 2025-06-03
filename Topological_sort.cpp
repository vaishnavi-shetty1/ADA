#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack, 
vector<vector<int>> &adj) {
 cout << "Visiting vertex " << v << endl;
 visited[v] = true;
 for (int u : adj[v]) {
 if (!visited[u]) {
 cout << "Vertex " << v << " -> going to vertex " << u << endl;
 topologicalSortUtil(u, visited, Stack, adj);
 }
 }
 cout << "Pushing " << v << " to stack\n";
 Stack.push(v);
}
void topologicalSort(int V, vector<vector<int>> &adj) {
 vector<bool> visited(V, false);
 stack<int> Stack;
 for (int i = 0; i < V; i++) {
 if (!visited[i]) {
 cout << "\nStarting DFS from vertex " << i << "\n";
 topologicalSortUtil(i, visited, Stack, adj);
 }
 }
 cout << "\nTopological Order:\n";
 while (!Stack.empty()) {
 cout << Stack.top() << " ";
 Stack.pop();
 }
 cout << endl;
}
int main() {
 int V, E;
 cout << "Enter number of vertices: ";
 cin >> V;
 cout << "Enter number of edges: ";
 cin >> E;
 vector<vector<int>> adj(V);
 cout << "Enter edges (u v) where u -> v:\n";
 for (int i = 0; i < E; i++) {
 int u, v;
 cin >> u >> v;
 adj[u].push_back(v);
 }
 topologicalSort(V, adj);
 return 0;
}