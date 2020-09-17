#include <iostream>
#include <math.h>

using namespace std;

class ClassSquare {        
  public:
    int side;

    ClassSquare(int x = 0){
        side = x;
    }

    int get_area() {
      return side*side;
    }

    int get_circumference(){
        return side*4;
    }

};

class ClassCircle {        
  public:
    int circleRadius;

    ClassCircle(int x = 0){
        circleRadius = x;
    }

    float get_area() {
      return M_PI*circleRadius*circleRadius;
    }

    float get_circumference(){
        return 2*circleRadius*M_PI;
    }

};

int main(){

    ClassSquare square;
    ClassCircle circle;

    int radius;

    cout << "Sisesta ringi raadius!" << endl;

    cin >> radius;

    square.side = radius*2;
    circle.circleRadius = radius;

    cout << "Ruudu pindala on: " << square.get_area() << endl;
    cout << "Ruudu ümbermõõt on: " << square.get_circumference() << endl;
    cout << "Ringi pindala on: " << circle.get_area() << endl;
    cout << "Ringi ümbermõõt on: " << circle.get_circumference() << endl;
    
}