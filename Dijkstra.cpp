#include<iostream>
#include<vector>

using namespace std;

const int MAXNODES=10;
const int INF = 9999;

void fnDijkstra(int [][MAXNODES], int [],int [],int [],int,int,int);

int main(){
	int n, cost[MAXNODES][MAXNODES], dist[MAXNODES], visited[MAXNODES],path[MAXNODES];
	int i,j,source,dest;
	
	cout << "\nEnter the number of nodes:";
	cin >> n;
	
	cout << "Enter the Cost Matrix(Use " << INF << " for no direct edge):\n";
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cin >> cost[i][j];
			if(i != j && cost[i][j] ==0){
				cost[i][j] = INF; 
			}
		}
	}
	
	cout << "Enter the Source vertex: ";
	cin >> source;
	
	cout << "\nShortest paths from Source vertex " << source << ":\n";
	for(dest = 0; dest < n; dest++){
		fnDijkstra(cost,dist,path,visited,source,dest,n);
		if(dist[dest] == INF){
			cout << "Vertex " << dest << " is not reachable.\n";
		}else{
			vector<int> route;
			for(i = dest;i != source;i = path[i]){
				route.push_back(i);
			}
			route.push_back(source);
			
			cout << "Distance to " << dest << "="<<dist[dest] << "\nPath: ";
			for(i = route.size()-1 ;i > 0; i--){
				cout<<route[i] <<"->";
			}
			cout << route[0] <<endl;
		}
	}
	return 0;
}

void fnDijkstra(int c[MAXNODES][MAXNODES],int d[MAXNODES],int p[MAXNODES],int s[MAXNODES],int so,int de, int n){
	int i,j,a,b,min;
	
	for(i = 0 ;i < n ; i++){
		s[i] = 0;
		d[i] = c[so][i];
		p[i] = (c[so][i] ==INF) ? -1 : so;
	}
	
	s[so] = 1;
	
	for(i = 1;i < n; i++){
		min = INF;
		a = -1;
		
		for(j = 0;j < n; j++){
			if(!s[j] && d[j] < min){
				min = d[j];
				a = j;
			}
		}
		
		if(a == -1) return;
		s[a] = 1;
		if(a == de) return ;
		for(b = 0; b < n; b++){
			if(!s[b] && d[a] + c[a][b] < d[b]){
				d[b] = d[a] +c[a][b];
				p[b] = a;
			}
		}
	}
}
