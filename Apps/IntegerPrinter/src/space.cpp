#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	int a = 22;
	int b = 233;
	std::stringstream ss;

	ss << setfill('0') << setw(3) << a;

	std::cout << ss.str() << std::endl;

	ss.clear();

	ss << setfill('0') << setw(3) << b;

	std::cout << ss.str() << std::endl;

	//std::cout << setfill('0') << setw(3) << a << std::endl;


}