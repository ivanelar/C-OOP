/*Създайте приложение - система за управление на хранителен блок (ученически стол). Системата има следната функционалност:
Възможност за формиране на специфични групи потребители и начисляване на различни отстъпки и надценки за отделните групи(20 точки).
Класовете (най-малко 3 класа при реализацията) трябва да капсулира всичките детайли.
Използват се private инстанции на променливите за съхраняване на различните детайли.
Трябва да има най-малко два конструктора, public getters/setters за private инстанции на променливите (30 точки).
Необходимо е да извършвате проверка на входните данни, където е необходимо (10 точки).
Да се предефинира операцията <<, която да се използва за извеждане на данните (10 точки).
Данните да се четат и съхраняват във файл (20 точки).
Класовете да се опишат с UML клас диаграма (10 точки).*/

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
