#include <iostream>
#include <sstream>
using namespace std;

//tạo class
class Student {
    //khai báo các thuộc tính ở private
    private:
        int age;
        int standard;
        string first_name;
        string last_name;

    //các phương thức ở public
    public:

        //set các thuộc tính
        void set_age(int age) {
            this->age = age;
        }

        void set_standard(int standard) {
            this->standard = standard;
        }

        void set_first_name(string first_name) {
            this->first_name = first_name;
        }

        void set_last_name(string last_name) {
            this->last_name = last_name;
        }

        //get các thuộc tính
        int get_age() {
            return age;
        }

        int get_standard() {
            return standard;
        }

        string get_first_name() {
            return first_name;
        }

        string get_last_name() {
            return last_name;
        }

        //phương thức ghép các chuỗi
        string to_string(){
            stringstream ss;
            ss << age <<","<<first_name<<","<<last_name<<","<<standard;
            return ss.str();
        }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
