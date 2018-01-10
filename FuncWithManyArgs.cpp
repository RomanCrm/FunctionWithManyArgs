//	2. Написать программу, которая реализует функцию с неограниченным количеством 	параметров, организовывающую форматированный вывод на экран.
//	Иначе говоря, от Вас требуется попробовать создать свою версию функции printf.

#include<iostream>
#include<stdarg.h>

using namespace std;

//long screen(int k, ...)
//{
//	int* pk = &k;
//	long tmp=0;
//
//	for (;k;k--)
//	{
//		tmp = *pk;
//		cout << tmp << " ";
//	}
//	cout << endl;
//
//	return tmp;
//}
//long screen2(int k, ...)
//{
//	int* pk = &k;
//	long tmp = 0;
//
//	while (*pk)
//	{
//		tmp = *pk;
//		*pk++;
//		cout << tmp << " ";
//	}
//
//	return tmp;
//}
//char symbol(char k, ...)
//{
//	char tmp;
//	int* pk = &k;
//
//	while (*pk)
//	{
//		tmp = *pk++;
//		if(tmp == '0')
//		{
//			return;
//		}
//	}
//
//	return tmp;
//}

void AnyType(int count, int typeof, ...)
{
	int sumi = 0;
	double sumd = 0;
	float sumf = 0;
	char *sumc = 0;

	va_list arg_ptr;

	__crt_va_start(arg_ptr, count);
	__crt_va_start(arg_ptr, typeof);

	cout << "1 - int\n2 - double\n3 - float\n4-char\nPlease enter type (from 1 to 4): " << endl;
	cin >> typeof;

	if (typeof == 1)
	{
		sumi += __crt_va_arg(arg_ptr, int);
	}
	if (typeof == 2)
	{
		sumd += __crt_va_arg(arg_ptr, double);
	}
	if (typeof == 3)
	{
		sumf += __crt_va_arg(arg_ptr, float);
	}
	if (typeof == 4)
	{
		sumc += __crt_va_arg(arg_ptr, char);
	}

	__crt_va_end(arg_ptr);

	if (typeof == 1)
	{
		cout << "int --> " << sumi;
	}
	if (typeof == 2)
	{
		cout << "double --> " << sumd;
	}
	if (typeof == 3)
	{
		cout << "float --> " << sumf;
	}
	if (typeof == 4)
	{
		cout << "char --> " << sumc;
	}

}

void main()
{
	setlocale(LC_ALL, "rus");

	AnyType(3, 1, 1, 2, 3);
	AnyType(3, 2, 4, 5, 6);
	AnyType(3, 3, 7.1, 8.2, 9.3);
	AnyType(3, 4, 'r', 'o', 'm');

	system("pause");
}