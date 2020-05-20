#include <functional>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
using namespace std;

struct SingletonTester {
  template <typename T> bool is_singleton(function<T *()> factory) {
    return factory() == factory();
  }
  template <typename T> bool is_singleton(function<shared_ptr<T>()> factory) {
    return factory().get() == factory().get();
  }
};

struct DummySingletonFactory {
private:
  DummySingletonFactory() { cout << "\nInitiazlizing singleton\n"; };

public:
  DummySingletonFactory(const DummySingletonFactory &) = delete;
  DummySingletonFactory operator=(const DummySingletonFactory &) = delete;
  static shared_ptr<DummySingletonFactory> get() {
    static auto factory = shared_ptr<DummySingletonFactory>( // STATIC!!!
        new DummySingletonFactory());
    return factory;
  }
  void do_stuff() { cout << "\nDid stuff\n"; }
};

int main() {
  DummySingletonFactory::get()->do_stuff();
  DummySingletonFactory::get()->do_stuff();

  SingletonTester st;
  std::function<shared_ptr<DummySingletonFactory>()> b =
      &DummySingletonFactory::get;
  cout << "Is it? " << st.is_singleton(b) << endl;
}