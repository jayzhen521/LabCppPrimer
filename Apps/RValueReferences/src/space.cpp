#include <iostream>

int main()
{
	int i = 42;
	int& r = i;
	//int&& rr = i;
	int&& rr = std::move(i);
	//int& r2 = i * 42;
	const int& r3 = i * 42;
	int&& r2 = i * 42;
	


}