#include "../common_design.h"

void process(string &s) { cout << s + " As lvalue" << endl; }
void process(string &&s) { cout << s + " as Rvalue " << endl; }
void process(int &s) { cout << to_string(s) + " As lvalue" << endl; }
void process(int &&s) { cout << to_string(s) + " as Rvalue " << endl; }

template <typename T> void pass(T &&arg) {
  //   cout << "Forwarding: ";
  //   process(forward<T>(arg));
  //   cout << "Moving: ";
  //   process(move(arg));
  cout << "Simple passing: ";
  process(arg);
}

int main() {
  std::string a{"LVALUE"};
  // pass(a);
  pass(string{"a"});
  //   int a = 10;
  pass(move(3));
}

// void overloaded(int const &arg) { std::cout << "by lvalue\n"; }
// void overloaded(int &&arg) { std::cout << "by rvalue\n"; }

// template <typename t>
// /* "t &&" with "t" being template param is special, and  adjusts "t" to be
//    (for example) "int &" or non-ref "int" so std::forward knows what to do.
//    */
// void forwarding(t &&arg) {
//   std::cout << "via std::forward: ";
//   overloaded(std::forward<t>(arg));
//   std::cout << "via std::move: ";
//   overloaded(std::move(arg)); // conceptually this would invalidate arg
//   std::cout << "by simple passing: ";
//   overloaded(arg);
// }

// int main() {
//   std::cout << "initial caller passes rvalue:\n";
//   forwarding(5);
//   std::cout << "initial caller passes lvalue:\n";
//   int x = 5;
//   forwarding(x);
// }