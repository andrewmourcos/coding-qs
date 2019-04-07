#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <numeric>
#include <string>
#include <fstream>

using namespace std;

void checkSplit(int N, int &A, int &B){
	vector<int> ArrA;
	vector<int> ArrB;

	string digits = to_string(N);
	for (int i = 0; i < digits.length(); ++i)
	{
		// cout << ((int)digits[i] - 48) << endl;
		if(((int)digits[i] - 48) == 4){
			// cout << ((int)digits[i] - 48)*pow(10, (digits.length() - i-1)) << endl;
			ArrB.push_back(((int)digits[i] - 48)*pow(10, (digits.length() - i-1)));
		}
		else{
			ArrA.push_back(((int)digits[i] - 48)*pow(10, (digits.length() - i-1)));
		}
	}
	
	B = accumulate(ArrB.begin(), ArrB.end(), 0)/2;
	A = accumulate(ArrA.begin(), ArrA.end(), 0) + B;
}

int main(int argc, char const *argv[])
{
    // //-- check if the files were opened successfully 
    // if (!fin.is_open()) cout << "input.in was not open successfully" << endl;
    // if (!fout.is_open()) cout << "output.out was not open successfully" << endl;
    
    int number = 0, datasize=0;
    int i = 0;
    int A=0, B=0;
    cin >> datasize;
    for (int i = 0; i < datasize; ++i)
    {
    	cin >> number;
    	checkSplit(number, A,B);
    	cout << "Case #" << (i + 1) << ": " << A << " " << B << endl;
    }
	return 0;
}