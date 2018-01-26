#include <iostream>

template<long long f>
class Factorial
{
public:
  static const long long val = (f*Factorial<f-1>::val);
};

template <>
class Factorial<1>
{
public:
  static const long long val = 1;
};

int main()
{
  std::cout << "Factorial<6>::val=" << Factorial<6>::val << std::endl;

  return 0;
}
