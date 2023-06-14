#include <iostream>
#include <string>
using namespace std;

// Pet is the base class
class Pet{
public:
    // Constructors, Destructors
    Pet(): weight(1), food("Pet Chow") {}
    ~Pet() {}

    // Accessors and mutators
    void setWeight(int w){
        weight = w;
    }
    
    int getWeight() const{
        return weight;
    }

    void setfood(string f){
        food = f;
    }
    
    string getFood() const{
        return food;
    }

    // General methods
    void eat();
    void speak();

protected:
    int weight;
    string food;

};

void Pet::eat(){
    cout << "Eating " << food << endl;
}

void Pet::speak(){
    cout << "Growl" << endl;
}

class Rat: public Pet{
public:
	Rat() {}
    ~Rat() {}

    // Other methods
    void sicken(){
        cout << "Speading Plague" << endl;
    }

};

class Cat: public Pet{
public:
    Cat() : numberToes(5) {}
    ~Cat() {}

    // Other methods
    void setNumberToes(int toes){
        numberToes = toes;
    }
    
    int getNumberToes(){
        return numberToes;
    }

private:
    int numberToes;
};


int main(){
    Rat charles;
    Cat fluffy;

    charles.setWeight(25);
    cout << "Charles weighs " << charles.getWeight() << " kilos " << endl;
    charles.speak();
    charles.eat();
    charles.sicken();

    fluffy.speak();
    fluffy.eat();
    cout << "Fluffy has " << fluffy.getNumberToes() << " toes " << endl;

    return 0;
}
