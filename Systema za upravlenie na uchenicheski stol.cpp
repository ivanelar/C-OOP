/*�������� ���������� - ������� �� ���������� �� ���������� ���� (���������� ����). ��������� ��� �������� ��������������:
���������� �� ��������� �� ���������� ����� ����������� � ����������� �� �������� �������� � �������� �� ��������� �����(20 �����).
��������� (���-����� 3 ����� ��� ������������) ������ �� ��������� �������� �������.
��������� �� private ��������� �� ������������ �� ����������� �� ���������� �������.
������ �� ��� ���-����� ��� ������������, public getters/setters �� private ��������� �� ������������ (30 �����).
���������� � �� ���������� �������� �� �������� �����, ������ � ���������� (10 �����).
�� �� ����������� ���������� <<, ����� �� �� �������� �� ��������� �� ������� (10 �����).
������� �� �� ����� � ���������� ��� ���� (20 �����).
��������� �� �� ������ � UML ���� �������� (10 �����).*/

#include <iostream>
using namespace std;
#include <fstream>


class Client {
private:
    string name;
    int age;
    double price;
    public:
    Client(){
    cout << "Enter the client's name : " ;
    cin >> name;
    cout << "Enter the client's age: " ;
    cin >> age;
    price = 3.6;
    }
    double getPrice(){return price;}
    int getAge(){return age;}
    void setAge(int a){age = a ;}
    void setPrice(double a){price=a;}
    string getName(){return name;}
    virtual void calculate_price (){}
    friend ostream& operator<< (ostream &os, Client& cl);
};
class Student : public Client {
public:
Student(){

    if(getAge()>28){
            cout << "The students older than 28 years will not be given a discount"  << endl;
    }
/*while (getAge()>28){
int b;
    cout << "Enter the client's age: " ;
    cin >> b;
    setAge(b);
}*/
}
void calculate_price() {
if(getAge()<=28){
cout << "The student "<< getName() << " has a discount of 50% and the total ammount he pays is : \t "  << getPrice()/2 << endl;
setPrice(getPrice()/2);
}else{
cout << "The student "<< getName() << " has no discount of 50% and the total ammount he pays is : \t "  << getPrice() << endl;
}}

};
class Teacher : public Client {
public:
Teacher (){
}
void calculate_price() {
cout << "The teacher "<< getName() << " has a standart price of : \t "  << getPrice()<< endl;
}
};
class Other : public Client {
public:
    Other (){}
void calculate_price() {
cout << "Only students and teachers have a discount! Others - "<< getName() << " pay :  \t "  << getPrice()*2 << endl;
setPrice(getPrice()*2);
}

} ;


ostream& operator<< (ostream &os, Client& cl){
os << "The age of " << cl.getName()<<  " is " <<cl.getAge();
return os ;
}
int main (){
ofstream ofile("tryThis.txt");
Client f ;
cout<<f<<endl;
Client** c = new Client*[3];

c[0] = new Student;
c[1] = new Teacher;
c[2] = new Other;

for(int i =0 ; i <3; i++) {
       c[i]->calculate_price();
       ofile << *c[i] << " and the price he/she pays is: " << c[i]->getPrice() << endl;
}

}
