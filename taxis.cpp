/*Създайте приложение, което да поддържа информация за маршрутни таксита.
Данните за колите са марка, модел, години, колко местна е, с каква товароподемност и колко разход на гориво иска.
Тези коли покриват някакви маршрути в града.
 За маршрута трябва да се знае възловите му точки  и колко километра е дълъг и колко пъти на ден се обикаля.

Приложението да има възможност за въвеждане на произволен брой различни маршрутни таксита и маршути(10 точки).

Да има възможност за избор на маршрутни таксита на което да се задава маршут и да извежда информация колко гориво да се зареди за извършване
нa дневната обиколка (10 точки).

Класовете (най-малко 3 класа при реализацията) трябва да капсулира всичките детайли. Използват се private инстанции на променливите
за съхраняване на различните детайли.
 Трябва да има най-малко два конструктора, public getters/setters за private инстанции на променливите (30 точки).

Необходимо е да извършвате проверка на входните данни, където е необходимо (10 точки).

Да се предефинира операцията <<, която да се използва за извеждане на данните (10 точки). Данните да се четат и съхраняват във файл (20 точки).

Класовете да се опишат с UML клас диаграма (10 точки).
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class KeyDestination{
private:
    string name;
public:
    KeyDestination(){
    cout<< "Enter your destination ";
    //getline (cin,name);
    //cin.clear();
    cin>>name;
    }
    string getName(){return name;}

};


 class Route{
     private:
KeyDestination* startRoute;
KeyDestination* endRoute;
double length;
int toursADay;
     public:
Route(){
startRoute = new KeyDestination;
endRoute = new KeyDestination;
cout<< "How long is the route(km)?";
cin>>length;
cout<<"How many times a day the route is toured?";
cin>>toursADay;
}
~Route(){delete startRoute;delete endRoute;}
string getStartRoute(){return startRoute->getName();}
string getEndRoute(){return endRoute->getName();}
double getLength(){return length;}
int getToursADay(){return toursADay;}

};

 class Taxi {
private:
    string brand;
    string model;
    int age;
    int seats;
    double loadCapacity;
    double fuelSpent; // liter per km (primerno 7/100 ti e 0,07 za 1 km )
    Route *r;
    double fuel;
public:
    Taxi(){
        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter model: ";
        cin >> model;
        age = 5;
        seats = 8;
        loadCapacity = 10;
        fuelSpent = 0.07;
        r = new Route();
    }
    ~Taxi(){delete r;}
    string getBrand(){return brand;}
    string getModel(){return model;}
    int getAge() {return age;}
    int getSeats(){return seats;}
    double getLoadCapacity(){return loadCapacity;}
    double getFuelSpent(){return fuelSpent;}
    void calculateFuel(){
double wholeRouteCost=0;
wholeRouteCost=(r->getLength() * getFuelSpent() )* (r->getToursADay());
cout<<"Fuel liters for route " << r->getStartRoute() << " - " << r->getEndRoute() << " are: " << wholeRouteCost << endl;
fuel = wholeRouteCost;
    }
    Route getRoute(){return *r;}
    double getFuel(){return fuel;}
    friend ostream& operator<<(ostream& os, Taxi& obj);
};


ostream& operator<<(ostream& os, Taxi& obj)
{
    os << "The route for taxi with brand: " << obj.getBrand() << " and model: " << obj.getModel() << " is " << obj.getRoute().getStartRoute() << " - " << obj.getRoute().getEndRoute() << endl;
    return os;
}
int main(){
    ofstream ofile("tryThis.txt");
    int i;
    cout << "How many taxis do you have: ";
    cin >> i;
    vector<Taxi*> arr;
    for(int j = 0; j < i; j++){
        arr.push_back(new Taxi());
    }

      for(int j = 0; j < i; j++){
        arr[j]->calculateFuel();
        ofile << "Fuel liters for route " << arr[j]->getRoute().getStartRoute() << " - " << arr[j]->getRoute().getEndRoute() << " are: " << arr[j]->getFuel() << endl;
}
    Taxi testOS = Taxi();
    cout << testOS;
    arr.clear();
}
