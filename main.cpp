#include <iostream>
#include <vector>

class Animal {
public:
    Animal(){
        std::cout << "In the Animal constructor" << std::endl;
    }
    virtual std::string speak(){
        return "I am an animal";
    }

    virtual ~Animal() {
        std::cout << "in the Animal destructor" << std::endl;
    }

protected:
    int age {-1};
};

class Cat : public Animal {
public:
    Cat(){
        std::cout << "in the default Cat constructor" << std::endl;
    }

    explicit Cat(int age) { // how could I do this with an initializer list?
        Animal::age = age;
        std::cout << "in the parameterized constructor" << std::endl;
        
    }

    std::string speak()  {
        return "I am a cat!";
    }

    virtual ~Cat() {
        std::cout << "In the Cat destructor" << std::endl;
    }
};

class HouseCat : public Cat {
public:
    HouseCat() {
        std::cout << "In the HouseCat constructor" << std::endl;
    }
    std::string speak(){
        return "I am a housecat";
    }
    virtual ~HouseCat() {
        std::cout << "In the HouseCat destructor" << std::endl;
    }
};

void printCat(Cat cat);

int add(int a, int b){
    return a + b;
}

std::string add(std::string a, std::string b){
    return a + b;
}


int main() {
    Animal* animal = new Cat;
   
    std::cout << animal->speak() << std::endl;
    delete animal;
   
    std::vector<Animal*> animals;
    animals.push_back(new Cat);
    for(auto a: animals){
        std::cout << a->speak() << std::endl;
    }

   // std::vector<std::shared_ptr<Animal>> animals2;
   // std::cout << "Adding the housecat" << std::endl;
   // animals2.push_back(std::shared_ptr<Cat>(new HouseCat) );

   // std::cout << "Adding the cat" << std::endl;
   // animals2.push_back(std::shared_ptr<Cat>(new Cat) );

   // for(auto catPtr : animals2){
   //     std::cout << catPtr->speak() << std::endl;
   // }

    std::cout << add(10,10) << std::endl;
    std::cout << add("John","John") << std::endl;

}




void printCat(Cat cat){
    cat.speak();
}
