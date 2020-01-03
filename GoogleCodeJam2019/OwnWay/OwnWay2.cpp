#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <numeric>
#include <string>
#include <fstream>

using namespace std;

void traverseMaze(int N, string lydia){
	string result = "";
	vector<int> lydiaPos;
	int myPos = 0, myLastPos=0;

	for (int i = 0; i < (2*N-2); ++i)
	{
		if (lydiaPos == myPos)
		{
			if (lydia[i] == 'E')
				// go S
			else 
				// go E
		}
		else{
			if (lydia[i] == 'E')
			{
				/* code */
			}
			else{

			}
		}
	}
}

int main(int argc, char const *argv[])
{
	traverseMaze(5, "ESESESSE");
	return 0;
}

