#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMinVertex(vector<int> &key, vector<bool> &visited, int n) {
 int minKey = INT_MAX, minIndex = -1;
 for (int i = 0; i < n; i++) {
 if (!visited[i] && key[i] < minKey) {
 minKey = key[i];
 minIndex = i;
 }
 }
 return minIndex;
}
void primMST(vector<vector<int>> &graph, int n) {
 vector<int> parent(n, -1), key(n, INT_MAX);
 vector<bool> visited(n, false);
 key[0] = 0;
 for (int count = 0; count < n - 1; count++) {
 int u = findMinVertex(key, visited, n);
 visited[u] = true;
 for (int v = 0; v < n; v++) {
 if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
 parent[v] = u;
 key[v] = graph[u][v];
 }
 }
 }
 cout << "\nMinimum Cost Spanning Tree (MST):\n";
 int minCost = 0;
 for (int i = 1; i < n; i++) {
 cout << parent[i] << " -- " << i << " : " << graph[i][parent[i]] << "\n";
 minCost += graph[i][parent[i]];
}
 cout << "Total Minimum Cost: " << minCost << endl;
}
int main() {
 int n;
 cout << "Enter number of nodes: ";
 cin >> n;
 vector<vector<int>> graph(n, vector<int>(n));
 cout << "Enter adjacency matrix (0 for no edge):\n";
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 cin >> graph[i][j];
 primMST(graph, n);
 return 0;
}