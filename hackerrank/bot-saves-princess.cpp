#include <iostream>
#include <vector>
using namespace std;

/*
b---b
-----
--m--
-----
b---p

*/


void displayPathtoPrincess(int n, vector <string> grid){
    string x="";
    string y="";
    if(grid[0][0]=='p'){ // princess in top left
        x = "LEFT";
        y = "UP";
    }
    else if(grid[0][n-1]=='p'){ // princess in top right
        x = "RIGHT";
        y = "UP";
    }
    else if(grid[n-1][0]=='p'){ // princess in bottom left
        x = "LEFT";
        y = "DOWN";
    }
    else{ // princess in bottom right
        x = "RIGHT";
        y = "DOWN";
    }
    int num_iters = (int) n/2;
    for(int i=0; i < num_iters; i++){
        cout << x << endl << y << endl;
    } 
}

/*
   p----
   -----
   --m--
   -----
   -----
 */

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
