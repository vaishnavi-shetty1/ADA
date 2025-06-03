#include <iostream>
#include <vector>
using namespace std;
void warshall(vector<vector<int>>& graph, int V) {
vector<vector<int>> reach = graph;
for (int k = 0; k < V; k++) {
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
}
}
}
cout << "Transitive Closure Matrix:\n";
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
cout << reach[i][j] << " ";
}
cout << endl;
}
}
int main() {
int V;
cout << "Enter the number of vertices: ";
cin >> V;
vector<vector<int>> graph(V, vector<int>(V));
cout << "Enter the adjacency matrix (0 or 1):\n";
for (int i = 0; i < V; ++i) {
for (int j = 0; j < V; ++j) {
cin >> graph[i][j];
}
}
warshall(graph, V);
return 0;
}