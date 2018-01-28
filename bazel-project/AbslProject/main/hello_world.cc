#include <iostream>
#include <string>
#include <vector>
#include "absl/strings/str_join.h"
#include "lib/hello-time.h"

int main() {
  std::vector<std::string> v = {"foo", "bar", "baz"};
  std::string s = absl::StrJoin(v, "-");

  std::cout << "Join string: " << s << "\n";

  return 0;
}
