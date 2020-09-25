#include <iostream>

using namespace std;

int askDistance(){

    int distance;
    cout << "Sisesta vahemaa Maalt Kuule: " << endl;
    cin >> distance;

    return distance;

}

bool compareGuess(int& guess, int& correctDistance){

    float error = (float)(guess-correctDistance) / (float)correctDistance;

    if (guess == 0){
        cout << "Exiting simulation..." << endl;
        return true;
    }
    if (error < 0.03 && error > -0.03){
        cout << "Nealepea pihta!" << endl;
        return true;
    }else
    {
        if(error > 0){
            cout << "Vahemaa on väiksem!" << endl;
        }else
        {
            cout << "Vahemaa on suurem" << endl;
        }
        return false;
        
    }
    
}

int main(){

    int distance = 382500; // KM
    int guessedDistance;

    bool guessedRight = false;

    while (!guessedRight)
    {
        guessedDistance = askDistance();
        guessedRight = compareGuess(guessedDistance, distance);
    }
    
    

}