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
        inline static int id = 4;

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

//int Professor::id = 1;

int main(){

    Person *per[3];
            // If val is 1 current object is of type Professor
    per[0] = new Professor;


    per[0]->getdata();

    per[0]->putdata(); // Print the required output for each object.

    for (;;);
    return 0;

}
