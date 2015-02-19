#include <iostream>
#include <chrono>
#include "indexOfAsm.h"
#include "indexOfC.h"

//-----------------------------------------------------------------------------

using namespace std;

//-----------------------------------------------------------------------------

int main()
{
	const unsigned array_size = 100000;
	const unsigned loop_size = 100000;

	// Fill an array with pseudorandom integers
	long arrayInt[array_size];
	for (unsigned i = 0; i != array_size; ++i)
		arrayInt[i] = rand();

	long search_val;
	cout<<"Enter an integer value to find: ";
	cin>>search_val;
	cout<<"Please wait...\n";

	// Test the Assembly language function
	auto start = chrono::steady_clock::now();
	int count = 0;

	for (unsigned n = 0; n != loop_size; ++n)
		count = IndexOf(search_val,arrayInt,array_size);

	bool found = (count != -1);
	auto stop = chrono::steady_clock::now();

	cout<<"Elpased ASM time: "<<chrono::duration_cast<chrono::milliseconds>(stop-start).count()<<"ms.\n"
		<<"Found = "<<found<<endl;

	// Test the C++ language function
	cout<<"\nPlease wait...\n";

	start = chrono::steady_clock::now();
	count = 0;

	for (unsigned n = 0; n != loop_size; ++n)
		count = IndexOfC(search_val,arrayInt,array_size);

	found = (count != -1);
	stop = chrono::steady_clock::now();

	cout<<"Elpased C++ time: "<<chrono::duration_cast<chrono::milliseconds>(stop-start).count()<<"ms.\n"
		<<"Found = "<<found<<endl;

	return 0;
}
