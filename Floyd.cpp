#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF 99999
void floydWarshall(vector<vector<int>>& graph, int V) {
vector<vector<int>> dist = graph;
for (int k = 0; k < V; k++) {
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (dist[i][k] != INF && dist[k][j] != INF)
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
}
}
cout << "All Pairs Shortest Distance Matrix:\n";
for (int i = 0; i < V; ++i) {
for (int j = 0; j < V; ++j) {
if (dist[i][j] == INF)
cout << "INF ";
else
cout << dist[i][j] << " ";
}
cout << endl;
}
}
int main() {
int V;
cout << "Enter the number of vertices: ";
cin >> V;
vector<vector<int>> graph(V, vector<int>(V));
cout << "Enter the adjacency matrix (use 99999 for INF):\n";
for (int i = 0; i < V; ++i) {
for (int j = 0; j < V; ++j) {
cin >> graph[i][j];
}
}
floydWarshall(graph, V);
return 0;
}