/* May 1st 2020
	Notes: 
		- there's still one bug to fix :/
		- Runtime can be improved with memoization
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size()==0)
            return 0;
        
        int lowestScore = 0;
        lowestScore = getLowestScore(dungeon, 0, lowestScore, 0, 0);
        return (lowestScore < 0)? 1-lowestScore : 1;
    }
    
    int getLowestScore(vector<vector<int>> &dungeon, int currScore, int &lowestScore, int x, int y){
        currScore += dungeon[y][x];
        lowestScore = min(currScore, lowestScore); 
        
        // Princess is found
        if ( (x==dungeon[0].size()-1) && (y==dungeon.size()-1) ){
            cout << lowestScore << endl;
            return lowestScore;
        }
        // Can't go right
        else if (x == dungeon[0].size()-1){
            getLowestScore(dungeon, currScore, lowestScore, x, y+1);   
        }
        // Can't go down
        else if (y == dungeon.size()-1){
            getLowestScore(dungeon, currScore, lowestScore, x+1, y);
        }
        else{
            lowestScore = max( getLowestScore(dungeon, currScore, lowestScore, x+1, y), getLowestScore(dungeon, currScore, lowestScore, x, y+1) );
        }

        return lowestScore;
    }
    
/*  First Recursion Attempt

    int getLowestScore(vector<vector<int>>& dungeon, int lowestScore, int currScore, int x, int y){
        currScore += dungeon[x][y];
        if (currScore < lowestScore)
            lowestScore = currScore;
        
        bool princessFound = (x==dungeon.size() && y==dungeon[0].size()) ? 1 : 0;
        if (princessFound)
            return lowestScore;
        
        int rightScore=100, leftScore=100;
        if (x != dungeon.size())
            getLowestScore(dungeon, lowestScore, currScore, x+1, y);
        if (y != dungeon[0].size())
            getLowestScore(dungeon, lowestScore, currScore, x, y+1);
        
        return lowestScore;
    }
*/

};
