#include "../common_design.h"

struct Item {
    string name;
    static int counter;
    int localCounter;

    Item() {
        counter++;
        localCounter = counter;
        cout << "\nEmpty constructor on " << localCounter << "\n";
    }

    Item(string name) : name(name) {
        counter++;
        localCounter = counter;
        cout << "\nString constructor on " << localCounter << "\n";
    }

    Item(const Item &item) : name(item.name) {
        counter++;
        localCounter = counter;
        cout << "\nCopy constructor on " << localCounter << "\n";
    }

    Item operator=(const Item &item) {
        cout << "\nAssignment operator on " << localCounter << "\n";
        return Item{item};
    }

    Item(const Item &&item) : name(item.name) {
        counter++;
        localCounter = counter;
        cout << "\nMove constructor on " << localCounter << "\n";
    }

    ~Item() { cout << "\nDestroying  " << localCounter << "\n"; }
};

int Item::counter = 0;

struct PointerConsumer {
    std::vector<unique_ptr<Item>> uniques;
    std::vector<shared_ptr<Item>> shareds;
    std::vector<weak_ptr<Item>> weaks;

    void consume(unique_ptr<Item> &p) { uniques.push_back(move(p)); }

    void consume(shared_ptr<Item> p) { shareds.push_back(p); }

    void consume(weak_ptr<Item> p) { weaks.push_back(p); }

    //~PointerConsumer() { for (auto s : shareds) { delete (s.get()); }}

};

void observe(const shared_ptr<Item> p)
{
    cout << "\nUsers of b: " << p.use_count() << endl;
}

int main() {
    weak_ptr<Item> weak;
    {
        PointerConsumer ps;
        auto a = make_unique<Item>("a");
        auto b = make_shared<Item>("b");
        auto c = make_shared<Item>(*b);
        auto d = make_shared<Item>(move(*b));
        observe(b);
        auto e = b;
        observe(b);
        weak = d;
        observe(b);


        if(auto lock = weak.lock())
        {
            cout<<"Locked" <<endl;
        }

        ps.consume(a);
        ps.consume(b);
        observe(b);
    }
    if(auto lock = weak.lock())
    {
        cout<<"Locked" <<endl;
    }
    else {
        cout << "Not locked"<<endl;
    }
    return 0;
}

