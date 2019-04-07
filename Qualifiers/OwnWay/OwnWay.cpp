#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

void createLink(vector<int> adj[], int u, int v);
  
int unvisited(int num, vector<int>& path) 
{ 
	for (int i = 0; i < path.size(); i++) { 
		if (path[i] == num)  
			return 0; 
	} 
	return 1; 
} 

void findpaths(vector<int> adj[], int V) 
{ 
    // queue for paths
    queue<vector<int> > q; 
    vector<int> path;
    path.push_back(0); 
    q.push(path);
    int prev;
    vector<int> newpath(path); 
    while (!q.empty()) { 
        path = q.front(); 
        q.pop(); 
        prev = path[path.size() - 1]; 
        
        // if reached desired location print path
        if (prev == V-1){
        	for (int i = 0; i < path.size()-1; ++i)
			{
				if (path[i+1]-path[i] == 1)
					cout<<"E";
				else
					cout << "S";
			}
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
    // cout << translate(path) << endl;
} 

void traverseMaze(int dimension, string lydia){
	int V = dimension*dimension;
	vector<int> adj[V];
	int LydiaPos = 0, LydiaMoves=0;

	// creating the map
	for (int i = 0; i < V-1; i++)
	{
			if (lydia[0] == 'E' && lydia[2*dimension-3] == 'S')
		{
			for (int i = 0; i < 2*dimension-2; ++i)
			{
				if(i < dimension-1){
					cout << 'S';
				}
				else{
					cout << 'E';
				}
			}
			return;
		}
		else if (lydia[0] == 'S' && lydia[2*dimension-2] == 'E')
		{
			for (int i = 0; i < 2*dimension-2; ++i)
			{
				if(i < dimension-1){
					cout << 'E';
				}
				else{
					cout << 'S';
				}
			}
			return;
		}
		if(LydiaPos == i && lydia[LydiaMoves] == 'E'){
			if (!(i >= dimension*(dimension-1)))
			{
				LydiaPos = i+1;
				LydiaMoves++;
				createLink(adj, i, i+dimension); // south
			}
			else{
				LydiaPos = i+1;
				LydiaMoves++;
			}
		}
		else if(LydiaPos == i && lydia[LydiaMoves] == 'S'){
			if ((i+1)%dimension != 0)
			{
				LydiaPos = i+dimension;
				LydiaMoves++;
				createLink(adj, i, i+1); // east
			}
			else{
				LydiaPos = i+dimension;
				LydiaMoves++;
			}
		}
		// check if too far right
		else if((i+1)%dimension == 0){
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
	findpaths(adj, V);
}

int main()
{
	int size=0, dimension=0;
	string pattern;
	cin >> size;
	for (int i = 0; i < size; ++i)
	 {
	 	cin >> dimension;
	 	cin >> pattern;
	 	cout << "Case #" << (i + 1) << ": ";
	 	traverseMaze(dimension, pattern);
	 	cout << endl;
	 } 
	return 0;
}

void createLink(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
} 
