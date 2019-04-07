#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

void pangram(int dimension, string lydia){
	map<int,char> code;
	code[0]='A';
	map[0]='B';
	map[7]='C';
	map[0]='D';
	map[0]='E';
	map[0]='F';
	map[0]='G';
	map[0]='H';
	map[0]='I';
	map[31]='J';
	map[0]='K';
	map[0]='L';
	map[0]='M';
	map[0]='N';
	map[0]='O';
	map[0]='P';
	map[61]='Q';
	map[0]='R';
	map[0]='S';
	map[0]='T';
	map[1]='U';
	map[0]='V';
	map[0]='W';
	map[0]='X';
	map[0]='Y';
	map[0]='Z';
	
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

