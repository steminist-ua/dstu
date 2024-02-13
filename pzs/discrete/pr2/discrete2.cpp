// discrete2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, _TCHAR* argv[])
{
	vector<int> A;
	vector<int> B;
	for(int i = 1; i <= 5; i++){
		A.push_back(i);
	}
	for(int i = 3; i <= 7; i++){
		B.push_back(i);
	}
	cout << "A U B: ";
	vector<int> C = A;
	for(int i = 0; i < B.size(); i++){
		if(find(A.begin(), A.end(), B[i]) == A.end()){
			C.push_back(B[i]);
		}
	}
	for(int i = 0; i <C.size(); i++){
		cout << C[i] << " ";
	}
	cout<<endl;
	vector<int> D;
	for (int elementA :A)
	{
		for (int elementB :B)
		{
			if(elementA==elementB)
			{
				D.push_back(elementA);
				cout<<elementA<<endl;
			}

		}
	}
	vector<int> E;
	cout << "A \ B: ";
	for(int elA : A){
		bool isThere = 1;
		for(int elB : B){
			if(elA == elB){
				isThere = 0;
			}
		}
		if(isThere){
				E.push_back(elA);
				cout << elA << " ";
			}
	}
	cout << endl;
	vector <int> W;
	for(int elB : B){
		bool isThere = 1;
		for(int elA : A){
			if(elB == elA){
				isThere = 0;
			}
		}
		if(isThere){
				W.push_back(elB);
				cout << elB << " ";
			}
	}
	system("pause");
	return 0;
}

