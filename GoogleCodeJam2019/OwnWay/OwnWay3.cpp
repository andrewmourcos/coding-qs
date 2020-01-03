#include <iostream>
#include <cstdlib>
#include <queue>
#include <set>

using namespace std;
void createLink(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    // adj[v].push_back(u); 
} 

int unvisited(int num, vector<int>& path) 
{ 
	for (int i = 0; i < path.size(); i++) { 
		if (path[i] == num)  
			return 0; 
	} 
	return 1; 
} 

string translate(vector<int> path){
	string directions = "";
	for (int i = 0; i < path.size()-1; ++i)
	{
		if (path[i+1]-path[i] == 1)
			directions.append("E");
		else
			directions.append("S");
	}
	return directions;
}
  
// utility function for finding paths in graph 
// from source to destination 
void findpaths(vector<int> adj[], int V) 
{ 
    // queue for paths
    queue<vector<int> > q; 
    vector<int> newpath(path);
    // current path
    vector<int> path;
    path.push_back(0); 
    q.push(path); 
    while (!q.empty()) { 
        path = q.front(); 
        q.pop(); 
        int prev = path[path.size() - 1]; 
        // if reached desired location print path
        if (prev == V-1){
        	cout << translate(path) << endl;
            return;
        }
        
        // traverse everything
        for (int i = 0; i < adj[prev].size(); i++) { 
            if (unvisited(adj[prev][i], path)) { 
                newpath = path; 
                newpath.push_back(adj[prev][i]); 
                q.push(newpath); 
            } 
        } 
    } 
} 

void traverseMaze(int dimension, string lydia){
	vector<int> lydiaPath(2*dimension);
	// lydiaPath.resize(2*dimension-1);
	int prevLydia=0;

	// vector<vector<int> > adj(dimension*dimension, vector<int>(dimension*dimension, 1));
	vector<int> adj[dimension*dimension];
	for (int i = 0; i < dimension*dimension; ++i)
	{
		if((i+1)%dimension == 0){
			createLink(adj, i, i+dimension);
		}
		// check if too far down
		else if(i >= dimension*(dimension-1)){
			createLink(adj, i, i+1); // east
		}
		else{
			createLink(adj, i, i+1); // east
			createLink(adj, i, i+dimension); // south
		}
	}

	for (int i = 1; i < lydia.size(); ++i){
		if (lydia[i-1] == 'E'){
			adj[prevLydia][prevLydia+1] = 0;
			prevLydia = prevLydia+1;
		}
		else{
			// lydiaPath[i] = prevLydia+dimension;
			adj[prevLydia][prevLydia+dimension] = 0;
			prevLydia = prevLydia+dimension;	
		}
	}
	// cout << adj[6][7] << endl;
	findpaths(adj, dimension*dimension);
}

int main()
{
	traverseMaze(5, "EESSSESE");
	return 0;
}



