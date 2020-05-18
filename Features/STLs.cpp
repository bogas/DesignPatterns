#include "../common_design.h"

[[unused]] void foo() {}

void print(vector<int> v) {
  for (auto &vv : v) {
    cout << vv << " ";
  }
  cout << endl;
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 1, 2, 4, 3, 77};
  cout << accumulate(begin(v), end(v), 0) << endl;
  print(v);

  transform(begin(v), end(v), begin(v), [](auto a) { return a + 4; });
  print(v);

  auto y = v;
  sort(rbegin(y), rend(y));
  auto last = unique(begin(y), end(y));
  print(y);
  y.erase(last, end(y));
  print(y);
  auto l = find(begin(v), end(v), 5);
  // auto r = remove(begin(v), end(v), 5);
  print(v);

  v.erase(l);
  print(v);

  foo();
  return 0;
}
