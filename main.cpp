#include <iostream>
#include <stdio.h>
#include <string.h>

using std::cout;
using std::string;

class Person {
    public:
    int ID, age, ParentID; 
    std::string birth; 
    const char *job, *surname, *name;
    string joblog;
    
    Person(){}
    
    Person(int ID, const char *surname, const char *name, int age,
    std::string birth, int ParentID, const char *job, string joblog) {
        this->ID = ID;
        this->surname = surname;
        this->name = name;
        this->age = age;
        this->birth = birth;
        this->ParentID = ParentID;
        this->job = job;
        this->joblog = joblog;
    }
    
    void ChangeJob(const char *newjob) {
        FILE *personjob;
        const char *cstr = joblog.c_str();
        personjob = fopen(cstr, "a");
        fprintf(personjob, "%s job changed to %s job \n", job, newjob);
        fclose(personjob);
    }
    
    Person* Born(Person *newperson, const char *newname) {
    string joblog = (string)newname + ".txt";
    return new Person(5, newperson->surname, newname, 0, "12.04.2023", newperson->ID, "-", joblog);
    }
};

void CoutPerson(Person* newperson) {
    cout << newperson->ID << " | " <<
    newperson-> surname << " | "
    << newperson->name << " | " 
    << newperson->age << " | "
    << newperson->birth << " | "
    << newperson->ParentID << " | "
    << newperson->job << " | "
    << newperson->joblog << "\n";
}
int main() {
    Person* newperson = new Person(172, "Samojlov", "Kirill", 16, "19.07.2006", 0, "-", "Kirill.txt");
    Person* child = newperson->Born(newperson, "Ahot");
    newperson->ChangeJob("\"yarche!\"");
    CoutPerson(newperson);
    CoutPerson(child);
    child->ChangeJob("\"yarche!\"");
}