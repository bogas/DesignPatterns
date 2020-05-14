#include "../common_design.h"
#include <future>

void five(promise<int> pr) {
    this_thread::sleep_for(5s);
    pr.set_value(5);
}

int main() {
    promise<int> pr;
    auto fut = pr.get_future();
    thread t1(five,move(pr));
    cout<<"Waiting for result "<<endl;
    auto result = fut.get();
    cout<<"Result: " << result <<endl;
    t1.join();


}
