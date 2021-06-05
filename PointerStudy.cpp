#include <iostream>

using namespace std;

int main()
{
	 int value = 100;
	 int* pvalue = &value;
	 int** ppvalue = &pvalue;

	 cout << "value : " << value << endl;
	 cout << "&value : " << &value << endl;
	 cout << "*pvalue : " << *pvalue << endl;

	 cout << "&pvalue : " << &pvalue << endl;
	 cout << "pvalue : " << pvalue << endl;
	 cout << "*ppvalue : " << *ppvalue << endl;

	 cout << "&ppvalue : " << &ppvalue << endl;
	 cout << "ppvalue : " << ppvalue << endl;
}
