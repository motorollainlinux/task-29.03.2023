#include <iostream>
#include <stdio.h>
#include <cstring>

using std::cout;

class Person {
    public:
    int ID, age, ParentID; 
    std::string birth; 
    const char *joblog, *job, *surname, *name;
    Person(int ID, const char *surname, const char *name, int age,
    std::string birth, int ParentID, const char *job, const char *joblog) {
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
        cout << "ChangeJob...\n";
        FILE *personjob;
        personjob = fopen(joblog, "a");
        fprintf(personjob, "%s job changed to %s job \n", job, newjob);
        fclose(personjob);
    }
Person* Born(Person *newperson, const char *newname) {
    Person *child = new Person(ParentID+1, newperson->surname, newname, 0, "05.04.2023", newperson->ID, "-", strcat((char*)newname, ".txt"));
    return child;
};
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
    Person* newperson = new Person(172, "Samojlov", "Kirill", 16, "19.07.2006", 0, "-", "SKD.txt");
    Person* child = newperson->Born(newperson, "Ahot");
    newperson->ChangeJob("\"yarche!\"");
    CoutPerson(newperson);
    CoutPerson(child);
}