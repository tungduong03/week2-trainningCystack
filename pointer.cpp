#include <stdio.h>
#include <math.h>

//tham số là giá trị của địa chỉ
void update(int *a,int *b) {
    //ở đây *a là giá trị của địa chỉ pa truyền vào, tương tự với *b
    *a = *a + *b;
    *b = abs(*a - *b - *b);
}

int main() {
    int a, b;

    //khai báo con trỏ pa chứa địa chỉ biến a
    //khai báo con trỏ pb chứa địa chỉ biến b
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);

    //truyền địa chỉ biến a và b
    update(pa, pb);

    printf("%d\n%d", a, b);

    return 0;
}

