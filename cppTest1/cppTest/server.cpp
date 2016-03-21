#include <iostream>
#include "libAdd.h"
using namespace std;
int main()
{
	if (!libAddInitialize())
		return -1;
	//cout << "init finish" << endl;
	int a = 10, b = 20;
	int c;
	mwArray mwA(1, 1, mxINT32_CLASS);
	mwArray mwB(1, 1, mxINT32_CLASS);
	mwArray mwC(1, 1, mxINT32_CLASS);
	mwA.SetData(&a, 1);
	mwB.SetData(&b, 1);

	Add(1, mwC, mwA, mwB);
	c = mwC.Get(1, 1);
	cout << "a+b=" << c << endl;
	/*
	Sub(1, mwC, mwA, mwB);
	c = mwC.Get(1, 1);
	cout << "a-b=" << c << endl;
	*/

	//测试两个矩阵相加
	double da[2][2] = { 1, 2, 3, 4 }, db[2][2] = { 5, 6, 7, 8 };	
	mwArray mwDA(2, 2, mxDOUBLE_CLASS);
	mwArray mwDB(2, 2, mxDOUBLE_CLASS);
	mwArray mwDC(2, 2, mxDOUBLE_CLASS);
	mwDA.SetData(*da, 4);
	mwDB.SetData(*db, 4);
	Add(1, mwDC, mwDA, mwDB);
	cout << "da+db=" << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << mwDC.Get(2, i + 1, j + 1)<<" ";
		}
		cout << endl;
	}
	libAddTerminate();
}