#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//tạo class Person làm lớp cha
class Person {
    public:
        string name;
        int age;

        //virtual function để lớp con override
        void getdata(){
            cin>>this->name>>this->age;
        }

        virtual void putdata(){
            cout<< this->name <<" "<<this->age<<endl;
        }
};

//tạo class Pro kế thừa class Per
class Professor : public Person{
    public:
        int publications, cur_id;
        //biến static để đếm số Professor
        static int id;

        Professor() {
            this->cur_id = id++; //gán số thứ tự cho Professor hiện tại
        }

        //override lại hàm trong Person
        void getdata(){
            cin >>this->name>>this->age>>this->publications;
        }

        void putdata() {
            cout << this->name << " "<< this->age <<" "<< this->publications <<" "<< this->cur_id << endl;
    }
};

//tạo class Student kế thừa class Per
class Student : public Person{
    public:
        int marks[6], cur_id, sum_mark=0;
        static int id;

        Student(){
            this->cur_id = id++;
        }

        void getdata(){
            cin >>this->name>>this->age;
            for (int i=0; i<6; i++) {
                cin>>marks[i];
                sum_mark += marks[i];
            }
        }

        void putdata() {
            cout << this->name << " "<< this->age << " "<<sum_mark << " "<< this->cur_id << endl;
    }
};

int Professor::id = 1;
int Student::id = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    for (;;);
    return 0;

}

