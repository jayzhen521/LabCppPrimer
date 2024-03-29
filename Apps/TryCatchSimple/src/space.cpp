//#include <iostream>
//#include <exception>
//
//
//int main()
//{
//    float b = 0;
//    try {
//        int a = 2;
//        
//        int c = a / b;
//
//    }
//    catch (std::exception& e)
//    {
//        std::cerr << e.what() << std::endl;
//    }
//
//    
//}


#include <iostream>
using namespace std;

// Defining function Division
float Division(float num, float den)
{
    if (den == 0) {
        throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    }


    // return the result of division
    return (num / den);

} // end Division

int main()
{
    // storing 12.5 in numerator
    // and 0 in denominator
    float numerator = 12.5;
    float denominator = 0;
    float result;

    try {
        // calls Division function
        result = Division(numerator, denominator);

        // display the value stored in result
        cout << "The quotient of 12.5/0 is "
            << result << endl;
    }
    catch (std::runtime_error& e)
    {
        cout << "Exception occurred" << endl
            << e.what();
    }

    

} // end main