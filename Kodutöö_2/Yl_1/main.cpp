#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

int guessed_no;
int random_number;
int money_spent = 0;

bool initialQuestion(){
    cout << "Want to win a million dollars?\nIf so, guess the winning number (a number between 0 and 100000)." << endl;
};

bool keepPlayingQuestion(){
    string ans;
    cout << "Insert $1.00 and enter your number or 'q' to quit:" << endl;

    cin >> ans;
    if (ans == "q"){
        return false;
    }
    if (stoi(ans) >= 0 && stoi(ans) <= 1000000 ){
        guessed_no = stoi(ans);
        money_spent++;
        return true;
    }else{
        return false;
    }
}

bool offerHint(){
    string ans;
    cout << "Sorry, good guess, but not quite right. Do you want me to give you a hint (y|n)?" << endl;
    cin >> ans;

    if (ans == "y"){
        cout << "Insert $2.00 for the hint!" << endl;
        money_spent = money_spent + 2;
        return true;
    }else{
        return false;
    }
}

void compareAndGiveHint(){
    if (guessed_no > random_number){
        cout << "Your number is too high!" << endl;
    }else{
        cout << "Your number is too low!" << endl;
    }
    
}

void gameLost(){
    cout << "You lost $" << money_spent << ". Thanks for playing. Come again!" << endl;
}

void gameWon(){
    cout << "YOU WIN!" << endl;
}

int main()
{   
    random_number = 0 + (rand() % static_cast<int>(1000000 - 0 + 1));
    //cout << random_number << endl;

    initialQuestion();

    while (keepPlayingQuestion() == true){
        if (guessed_no == random_number){
            gameWon();
            return 0;
        }else{
            if (offerHint() == true){
                compareAndGiveHint();
            }
        }
    }
    gameLost();
}
