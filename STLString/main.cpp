#include <iostream>
#include "myString.h"

using namespace std;
using namespace myString;

void main()
{
	cout << "hello" <<endl;

	Ms ms1;
	ms1.~Ms();

	Ms ms2("abc", 2);
	cout << ms2.get_str() << endl;
	//cout << ms2;

	return ;
}