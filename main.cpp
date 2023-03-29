#include <iostream>
#include <stdio.h>

class Person {
    public:
    
    int ID, age, ParentID; 
    std::string birth, job, joblog, surname, name;
    
    Person(int ID, std::string surname, std::string name, int age,
    std::string birth, int ParentID, std::string job, std::string joblog) {
        this -> ID = ID;
        this -> surname = surname;
        this -> name = name;
        this -> age = age;
        this -> birth = birth;
        this -> ParentID = ParentID;
        this -> job = job;
        this -> joblog = joblog;
    }
    void GiveBorn(std::string newname) {
        std::string newjoblog = (surname[0] + newname[0] + name[0] + ".txt");
        /*test*/ std::cout << "test:" << newjoblog << "\n"; /*test*/
        //FILE PersonJobLog = fopen(newjoblog, "w");
        //Person* newperson = new Person(ID+1, surname, newname, 0, "29.03.2023", ID, "-", newjoblog);
    };
};
int main() {
    Person* newperson = new Person(172, "Samojlov", "Kirill", 16, "19.07.2006", 0, "-", "SKD.txt");
    newperson -> GiveBorn("Ahot");
}
