#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//khai báo kiểu dữ liệu struct
struct Student{

    string first_name;
    int standard;
    int age;
    string last_name;

};

int main() {
    //khai báo biến cho kiểu dữ liệu
    Student st;

    //cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    //cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard<<" "
    cout<<sizeof(st);

    return 0;
}
