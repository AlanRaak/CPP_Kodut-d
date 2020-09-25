#include <iostream>

using namespace std;

int main(){

    int paaris = 0;
    int paarituid = 0;

    int input_num;
    for(int i = 1; i < 6; i++){
        cout << "Sisesta arv " << i << ": " << endl;
        cin >> input_num;
        if (input_num % 2 == 0){
            paaris++;
        }else
        {
            paarituid++;
        }
        
    }

    cout << "Paarisarve on: " << paaris << endl << "Paarituid on: " << paarituid << endl;

}

