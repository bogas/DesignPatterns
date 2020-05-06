
#include <string>
#include <ostream>
#include <iostream>
#include "set"
#include "vector"

using namespace std;

static set<string> availableTypes{"int", "string", "float", "unsigned"};

string operator*(const string &input, const int times) {
    string result;
    for (int i = 0; i < times; i++)
        result += input;
    return result;
}

string operator*(const int times, const string &input) {
    return input * times;
}

class CodeBuilder {
    string name;
    vector<pair<string, string>> fields;
    constexpr static unsigned indent = 2;
public:
    CodeBuilder(const string &class_name) : name(class_name) {
        // todo
    }

    CodeBuilder &add_field(const string &name, const string &type) {
        pair<string, string> newField;
        if (availableTypes.count(type))
            newField.first = type;
        else
            newField.first = "int";
        newField.second = name;
        fields.push_back(newField);
        return *this;
    }

    friend ostream &operator<<(ostream &os, const CodeBuilder &obj) {
        os << "class " + obj.name << endl << "{" << endl;
        for (const auto &field : obj.fields) {
            os << string{" "} * obj.indent << field.first << " " << field.second << ";" << endl;
        }
        os << "};" << endl;
        return os;
    }


};

int main() {
    CodeBuilder builder{"Person"};
    builder.add_field("age", "int").add_field("name", "string")
            .add_field("city", "string").add_field("male", "gender");
    cout << builder;
}