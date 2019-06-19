#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
class Certificate {
private :
int cer ;
string dateCer;
public :
    Certificate (){

    do {
   cout << "Enter 1 if the book has a certificate and 2 if it doesnt : " ;
   cin >> cer;
   }

   while (!(cer == 1 || cer ==2));

    if (cer == 1){
           cout << "Enter the date of the certificate : " ;
           cin >> dateCer;
        }
    }
int getCer (){return cer;}
};
class Publisher{
string name;
string address;
string phone;
public:
    Publisher(){
        cout << "Enter the publisher's name: ";
        cin >> name;
        cout << "Enter the publisher's address: ";
        cin >> address;
        string str;
        do{
        cout << "Enter the publisher's phone: ";
        cin >> phone;
        stringstream ss;
        ss << phone;
        str = ss.str();
        }while(str.length() != 10);
    }
    string getName(){return name;}
    double calculatePrice(double p, int f){
        return p*f;
    }
};
class Book {
private :
    string title;
    string author;
    int edition ;
    string isbn ;
    string dateEd;
    string Numb;
    double price;
    Certificate * cc;
    Publisher *p;
public:
    Book(){
        int a;
        cout << "Enter the title of the book : ";
        cin >> title;
        cout << "Enter the author of the book : ";
        cin >> author;
        cout << "Enter the edition of the book : ";
        cin >> edition;
        cout << "Enter the ISBN number of the book : ";
        cin >> isbn;
        cout << "Enter the date of print of the book : ";
        cin >> Numb;
        cout << "Enter the date of edition of the book : ";
        cin >> dateEd;
        cout << "Enter the price of the book : ";
        cin >> price;
        cc = new Certificate;
            p = new Publisher;
    }
    ~Book(){delete[]cc; delete[]p;}
    string getTitle(){return title;}
    double getPrice(){return price;}
    Publisher getPubl(){return *p;}
};
ostream& operator<< (ostream &os, Book& b){
os << "The title of the book is : " << b.getTitle();
return os ;
}
int main (){
    ofstream ofile("file.txt");
    int a;
    cout << "Enter how many books would you like to insert: " ;
    cin >> a ;
    Book** b = new Book*[a];

    string* arrPubl = new string[a];
    for (int i =0; i <a ; i++){
    b[i] = new Book;
    arrPubl[i] = b[i]->getPubl().getName();
    ofile << *b[i] << endl;
    }
    int pick;
    cout << "Which publisher do you want to order from? Pick a number: " << endl;
    for(int i=0; i<a; i++){
        cout <<i+1 << ":" << arrPubl[i]<< endl;
    }
    cin >> pick ;
    int choice;
    int copies;
    double sum=0;
    double cur;
 for(int i=0; i<a; i++) {
cout << "Do you want to buy this book ? " << b[i]->getTitle()<<endl;
cout << "Enter 1 for yes or 2 for no ";
cin >> choice;
if(choice == 1){
    cout << "How many copies do you want? ";
    cin >> copies;
    cur = b[i]->getPrice();
    sum += b[i]->getPubl().calculatePrice(cur,copies);

}
}
cout << "The sum is : " << sum << endl;
ofile << "The sum is : " << sum << endl;
cout << *b[0]; //testing the overloading of <<
    delete[]b;
    delete[]arrPubl;

}
