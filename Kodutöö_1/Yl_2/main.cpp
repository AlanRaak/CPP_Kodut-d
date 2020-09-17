#include <iostream>
#include <math.h>
#include <list>

using namespace std;

class ClassAsker {
    public:

    void ask_pay() {
      cout << "Sisesta palga suurus: " << endl;
    }

    void ask_to_continue() {
        cout << "Soovid veel lisada? (y / n): " << endl;
    }

};

class ClassPrinter {
    public:

    void print_list(list<int> pays){
        for (auto const& i : pays) {
        cout << " ";
        if (i > 1000){
            cout << i;
        }else{
            cout << i * 1.05;
        }
        }
    }
};

int main(){

    ClassAsker asker;
    ClassPrinter printer;
    string checker = "y";
    list<int> palgad;
    int palk;

    while (checker == "y"){

        asker.ask_pay();
        cin >> palk;

        palgad.push_back(palk);

        asker.ask_to_continue();
        cin >> checker;
    }

    cout << "Uued palgad:";
    printer.print_list(palgad);

    return 0;
}