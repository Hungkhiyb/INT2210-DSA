#include <iostream>
#include <map>

using namespace std;

struct Student {
    string ID;
    string name;
    string _class;

    Student(string ID, string name, string _class) {
        this->ID = ID;
        this->name = name;
        this->_class = _class;
    }

    void printInfor() {
        cout << name << ',' << _class << endl;
    }
};

class StudentList {
    map<string, Student*> list;

public:
    ~StudentList() {
        for(auto x: list) {
            delete x.second;
        }
        list.clear();
    }

    void Insert(string ID, string name, string _class) {
        Student* tmp = new Student(ID, name, _class);
        list.insert({ID, tmp});
    }

    void Delete(string ID) {
        delete list[ID];
        list.erase(ID);
    }

    void Infor(string ID) {
        if(list.find(ID) != list.end())
            list[ID]->printInfor();
        else {
            cout << "NA,NA" << endl;
        }
    }

    void Operation() {
        string op;
        getline(cin, op, '(');
        if(op == "Insert") {
            string ID;
            getline(cin, ID, ',');
            string name;
            getline(cin, name, ',');
            string _class;
            getline(cin, _class, ')');
            Insert(ID, name, _class);
            string tmp;
            getline(cin, tmp);
        }
        if(op == "Delete") {
            string ID;
            getline(cin, ID, ')');
            Delete(ID);
            string tmp;
            getline(cin, tmp);
        }
        if(op == "Infor") {
            string ID;
            getline(cin, ID, ')');
            Infor(ID);
            string tmp;
            getline(cin, tmp);
        }
    }
};

int main()
{
    StudentList* list = new StudentList();
    while(cin) {
        list->Operation();
    }
    delete list;
    return 0;
}
