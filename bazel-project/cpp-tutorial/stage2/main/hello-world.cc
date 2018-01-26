#include "hello-greet.h"
#include <iostream>
#include <string>
#include <ctime>

void print_localtime() {
  std::time_t result = std::time(nullptr);
  std::cout << std::asctime(std::localtime(&result));
}

int main(int argc, char *argv[])
{
  std::string who("Penglin");
  if (argc > 1) {
    who = argv[1];
  }
  std::cout << get_greet(who) << std::endl;
  print_localtime();

  std::cout << "Done!" << std::endl;

  return 0;
}
