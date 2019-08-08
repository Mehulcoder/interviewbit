#include <iostream>   // std::cout
#include <string>     // std::string, std::stod
using namespace std; 
int main()
{
    string a="1.3141        2.3145";
    string::size_type sz;
    double b=stod(a, &sz);
    cout<<b<<endl;
    std::cout<<sz<<std::endl;
    double c=stod(a.substr(sz));
    cout << c << '\n';

    /* code */
    return 0;
}