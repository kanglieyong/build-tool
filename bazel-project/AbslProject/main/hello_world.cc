#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "absl/strings/str_join.h"
#include "lib/hello-time.h"

// topk
std::vector<size_t> topk(const std::vector<double> &values, size_t k)
{
  size_t n = values.size();
  auto seq = [](size_t n)->std::vector<size_t> {
    std::vector<size_t> v(n); for(size_t i=0; i<n; ++i) v[i]=i; return v;
  };
  auto comp = [&values](size_t i, size_t j) { return values[i] > values[j]; };

  std::vector<size_t> labels = seq(n);
  auto first = labels.begin(), last = labels.begin()+k, end = labels.end();

  std::make_heap(first, last+1, comp);
  std::pop_heap(first, last+1, comp);
  for (auto it = last+1; it !=end; ++it) {
    if (values[*it] <= values[*first]) continue;
    *last = *it; std::pop_heap(first, last+1, comp);
  }
  std::sort_heap(first, last, comp);

  return std::vector<size_t>{first, last};
}


int main() {
  std::vector<std::string> v = {"foo", "bar", "baz"};
  std::string s = absl::StrJoin(v, "-");

  std::cout << "Join string: " << s << "\n";

  // topk
  const size_t n = 100000, k=10;
  std::default_random_engine eng(::time_t(NULL));
  std::uniform_real_distribution<double> rng(0, 1.0);
  std::vector<double> values(n);
  for (auto &x : values) x = rng(eng);

  std::vector<size_t> idx = topk(values, k);
  for (auto k : idx) { std::cout << values[k] << ","; }  std::cout << std::endl;

  std::sort(values.begin(), values.end(), [](double x, double y) { return x>y; });

  for (size_t i=0; i<k; ++i) { std::cout << values[i] << ",";}  std::cout << std::endl;
  

  return 0;
}
