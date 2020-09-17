#include <iostream>
#include <math.h>
#include <list>

using namespace std;

class Ask {
    public:

    void ask_temp(){
        cout << "Sisesta temperatuur: " << endl;
    }
};

class Compare {
    public:

    string get_assessment(int temp){
        if (temp > 25){
            return "hot!";
        }

        if (temp < 10){
            return "cold!";
        }else
        {
            return "warm!";
        }
        
    }
};

int main(){

    int temperature;
    Ask asker;
    Compare comparator;

    asker.ask_temp();
    cin >> temperature;

    cout << comparator.get_assessment(temperature);

}