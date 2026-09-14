#include <vector>
#include "iostream"

using namespace std;

// int main() {
//
//     string a="hello";
//
//     string b="world";
//     string c;
//     string x;
//     cout << a+b <<endl;
//     cout << a.length() << endl;
//     cout << 456;
//     x=a.substr(2,2);
//     cout << x << endl;
//     return 0;
// }
// struct student {
//     string name;
//     int age;
// };
//
// void func (int &num) {
//     num+=5;
// }
//
// int main() {
//     struct student stu[10];
//     stu[0].name = "John";
//     stu[0].age = 10;
//
//     cout << stu[0].name << endl;
//
//     func(stu[0].age);
//     cout << stu[0].age << endl;
//
//     int *a = &stu[0].age;
//     cout << &stu[0].age << endl;
//     cout << *a << endl;
//     return 0;
// }

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2(5,-1);
    cout << v[2] <<endl;
    cout << v2.size() <<endl;

    int arr[]={10,20,30};
    vector<int> v3(arr,arr+3);
    for (int i=0;i<v3.size();i++) {
        cout << v3[i] <<endl;
    }

    v2.push_back(10);
    for (int i=0;i<v2.size();i++) {
        cout << v2[i] <<endl;
    }
    v2.resize(v2.size()-2);
    for (int i=0;i<v2.size();i++) {
        cout << v2[i] <<endl;
    }
    v2.resize(v2.size()+2);
    for (int i=0;i<v2.size();i++) {
        cout << v2[i] <<endl;
    }
    cout << v2[7] << endl;
    cout << v2.front() << endl;

    v.swap(v2);
    for (auto p=v2.begin();p!=v2.end();p++) {
        cout << *p << " ";
    }
    printf("\n");

    vector<string> vc={"fdf","fd","dfd"};
    vc.push_back("aaa");
    for (string x:vc) {
        cout << x <<' ';
    }
    return 0;
}