// discrete.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool ifSimple(int number) {
	if (number < 2) return 0;
	for (int i = 2; i*i < number; i++) if (number%i == 0) return 0;
	return 1;

}

int _tmain(int argc, _TCHAR* argv[])
{
	
	for (int i = 1; i < 10; i++) {
		if(i%3 == 0) std::cout << "x: " << i << std::endl;
	}
	for (int x =-5; x<=5; x++){
		if(x%2==0) std::cout << x << std::endl;
	}
	cout<<endl;
	
	for (int i = -3; i <= 3; i++) {
		cout<<i*i<<endl;
	}
	std::cout << "-----------" << std::endl;
	for (int i = 10; i < 30; i++) {
		if (ifSimple(i)) {
			std::cout << "D: " << i << std::endl;
		}
	}

	for (int i = 1; i < 100; i++) {
		for (int j = 1; j < 100; j++)
			if (ifSimple(i*i + j*j) && (i != j)) 
			{
				std::cout << i << " " << j << std::endl;
			}
	}
		




	system ("pause");
	return 0;
}

