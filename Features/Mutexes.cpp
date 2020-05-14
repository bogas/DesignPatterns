#include "../common_design.h"
#include <future>

struct Asset {
    void update(string s) { cout << "Used by: " << s << endl; }
};

static Asset asset;
mutex assetMutex;
condition_variable cv;
bool condition = false;

void assetProcessor1() {
    auto name = "Processor1";
    std::srand(std::time(nullptr));
    auto counter = 3;
    while (counter--) {
        auto pause = std::rand() % 500;
        unique_lock<mutex> guard(assetMutex);
        cout << name <<endl;
        cv.wait(guard/*,[](){return condition;}*/);
        std::this_thread::sleep_for(chrono::milliseconds (pause));
        cv.notify_one();
    }

}

void assetProcessor2() {
    auto name = "Processor2";
    std::srand(std::time(nullptr));
    auto counter = 3;
    while (counter--) {
        auto pause = std::rand() % 500;
        {
            lock_guard<mutex> guard(assetMutex);
            std::this_thread::sleep_for(chrono::milliseconds (pause));
            cout << name << endl;
        }

        cv.notify_one();
        unique_lock<mutex> guard(assetMutex);
        if(counter)
        cv.wait(guard);
        else
            cv.notify_one();
    }
    throw exception("P2 error");
}

int main() {
    std::thread t1(assetProcessor1);
    auto fut = std::async(std::launch::async,assetProcessor2);
    try{fut.get();}
    catch(std::exception& e)
    {
        cout<<"Async erro caught"<<endl;
    }
    //fut.wait();
    cout<<"Async finished"<<endl;
    cv.notify_all();
    try{fut.get();}
    catch(std::exception& e)
    {
        cout<<"Async erro caught"<<endl;
    }

    t1.join();
    cout<<"T1 finished"<<endl;
    return 0;
}