#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

//Base Class
class Date {
protected:
	int	day;
	int month;
	int year;

public:
	Date(); //Constructor by Default
	Date(int, int, int); //Initializing Constructor
	Date(const Date &Date); //Copying Constructor
	~Date() {}; //Destructor
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int);
	void setMonth(int);
	void setDay(int);
};

Date::Date() {
	day = 22;
	month = 10;
	year = 2009;
}

Date::Date(int dday, int dmonth, int dyear) {
	this->day = dday;
	this->month = dmonth;
	this->year = dyear;
}

Date::Date(const Date &Date) {
	this->day = Date.day;
	this->month = Date.month;
	this->year = Date.year;
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

void Date::setYear(int yyyy)
{
	year = yyyy > 0 && yyyy < 2020 ? yyyy : 2000;
}

void Date::setMonth(int mm)
{
	month = mm > 0 && mm < 13 ? mm : 1;
}

void Date::setDay(int dd)
{
	day = dd > 0 && dd < 31 ? dd : 1;
}


//Base Class
class Bus {
protected:
	char* model;
	int seats;
	float consumption;

public:
	Bus(); //Constructor by Default
	Bus(char*, int, float); //Initializing Constructor
	Bus(const Bus &Bus); //Copying Constructor
	~Bus(); //Destructor

	char* getModel();
	int getSeats();
	float getConsumption();
	void setModel(char*);
	void setSeats(int);
	void setConsumption(float);
};

Bus::Bus() {
	model = new char[strlen("Icarus") + 1];
	strcpy(model, "Icarus");
	seats = 26;
	consumption = 20.9;
}

Bus::Bus(char* mmodel, int sseats, float cconsumption) {
	this->model = new char[strlen(mmodel) + 1];
	strcpy(model, mmodel);
	this->seats = sseats;
	this->consumption = cconsumption;
}

Bus::Bus(const Bus &Bus) {
	this->model = new char[strlen(Bus.model) + 1];
	strcpy(model, Bus.model);
	this->seats = Bus.seats;
	this->consumption = Bus.consumption;
}

Bus::~Bus()
{
	if (!model)
		delete[] model;
}

char* Bus::getModel()
{
	return model;
}

int Bus::getSeats()
{
	return seats;
}

float Bus::getConsumption()
{
	return consumption;
}

void Bus::setModel(char* mdl)
{
	this->model = mdl;
}

void Bus::setSeats(int sts)
{
	this->seats = sts;
}

void Bus::setConsumption(float cns)
{
	this->consumption = cns;
}


/////////
class Person : public Date { //virtual public date
protected:
	char* name;
	char* surname;
public:
	Person(); //Constructor by Default
	Person(int, int, int, char*, char*); //Initializing Constructor
	Person(const Person &person); //Copying Constructor
	~Person(); //Destructor

	char* getName();
	char* getSurname();
	void setName(char*);
	void setSurname(char*);
};

Person::Person() : Date(12, 7, 1988) {
	this->name = new char[strlen("Yann") + 1];
	this->name = strcpy(name, "Yann");
	this->surname = new char[strlen("Martel") + 1];
	this->surname = strcpy(surname, "Martel");
}

Person::Person(int pday, int pmonth, int pyear, char* tpname, char* tpsurname) : Date(pday, pmonth, pyear) {
	this->name = new char[strlen(tpname) + 1];
	this->name = strcpy(name, tpname);
	this->surname = new char[strlen(tpsurname) + 1];
	this->surname = strcpy(surname, tpsurname);
}

Person::Person(const Person &person) : Date(person) {
	this->name = new char[strlen(person.name) + 1];
	this->name = strcpy(name, person.name);
	this->surname = new char[strlen(person.surname) + 1];
	this->surname = strcpy(surname, person.surname);
}

Person::~Person() {
	if (!name)
		delete[] name;
	if (!surname)
		delete[] surname;
}

char* Person::getName()
{
	return name;
}

char* Person::getSurname()
{
	return surname;
}

void Person::setName(char* nm)
{
	this->name = nm;
}

void Person::setSurname(char* srn)
{
	this->surname = srn;
}



//Base Class
class Category {
protected:
	int rank;
	float salary;

public:
	Category(); //Constructor by Default
	Category(int, float); //Initializing Constructor
	Category(const Category &Category); //Copying Constructor
	~Category() {}; //Destructor

	int getRank();
	float getSalary();
	void setRank(int);
	void setSalary(float);
};

Category::Category() {
	rank = 2;
	salary = 2078.94;
}

Category::Category(int rrank, float ssalary) {
	this->rank = rrank;
	this->salary = ssalary;
}

Category::Category(const Category &Category) {
	this->rank = Category.rank;
	this->salary = Category.salary;
}

int Category::getRank()
{
	return rank;
}

float Category::getSalary()
{
	return salary;
}

void Category::setRank(int rnk)
{
	this->rank = rnk;
}

void Category::setSalary(float slr)
{
	this->salary = slr;
}


/////////
class Driver : public Person, public Category {
public:
	Driver(); //Constructor by Default
	Driver(int, int, int, char*, char*, int, float); //Initializing Constructor
	Driver(const Driver &Driver); //Copying Constructor
	~Driver() {}; //Destructor
};

Driver::Driver() : Person(), Category() {
}

Driver::Driver(int pday, int pmonth, int pyear, char* tpname, char* tpsurname, int rrank, float ssalary) : Person(pday, pmonth, pyear, tpname, tpsurname),
Category(rrank, ssalary) {
}

Driver::Driver(const Driver &Driver) : Person(Driver), Category(Driver) {
}



/////////
class Application : public Date {
protected:
	char* destination;
	float size;
public:
	Application(); //Constructor by Default
	Application(int, int, int, char*, float); //Initializing Constructor
	Application(const Application &Application); //Copying Constructor
	~Application(); //Destructor

	char* getDestination();
	float getsize();
	void setDestination(char*);
	void setsize(float);
};

Application::Application() : Date() {
	this->destination = new char[strlen("Kyiv") + 1];
	this->destination = strcpy(destination, "Kyiv");
	this->size = 456.8;
}

Application::Application(int pday, int pmonth, int pyear, char* ddestination, float lsize) : Date(pday, pmonth, pyear) {
	this->destination = new char[strlen(ddestination) + 1];
	this->destination = strcpy(destination, ddestination);
	this->size = lsize;
}

Application::Application(const Application &Application) : Date(Application) {
	this->destination = new char[strlen(Application.destination) + 1];
	this->destination = strcpy(destination, Application.destination);
	this->size = Application.size;
}

Application::~Application() {
	if (!destination)
		delete[] destination;
}

char* Application::getDestination()
{
	return destination;
}

float Application::getsize()
{
	return size;
}

void Application::setDestination(char* dst)
{
	this->destination = dst;
}

void Application::setsize(float lng)
{
	this->size = lng;
}



/////////
class Trip : public Application, public Driver, public Bus, public Date {
protected:
	float totalConsumption;
public:
	Trip(); //Constructor by Default
	Trip(int, int, int, char*, float,
		int, int, int, char*, char*, int, float,
		char*, int, float,
		int, int, int,
		float); //Initializing Constructor
	Trip(const Trip &Trip); //Copying Constructor
	~Trip() {}; //Destructor

	float getTotalConsumption();
	void setTotalConsumption(float);

	friend ostream& operator<< (ostream& stream, Trip& d)
	{
		stream << d.getTotalConsumption() << "l/100km";

		return stream;
	}
};

Trip::Trip() : Application(), Driver(), Bus(), Date() {
	this->totalConsumption = 45.9;
}

Trip::Trip(int pday, int pmonth, int pyear, char* ddestination, float lsize,
	int dday, int dmonth, int dyear, char* tpname, char* tpsurname, int rrank, float ssalary,
	char* mmodel, int sseats, float cconsumption,
	int ddday, int ddmonth, int ddyear,
	float ttotalConsumption) :
	Application(pday, pmonth, pyear, ddestination, lsize),
	Driver(dday, dmonth, dyear, tpname, tpsurname, rrank, ssalary),
	Bus(mmodel, sseats, cconsumption),
	Date(ddday, ddmonth, ddyear) {
	this->totalConsumption = ttotalConsumption;
}

Trip::Trip(const Trip &Trip) : Application(Trip), Driver(Trip), Bus(Trip), Date(Trip) {
	this->totalConsumption = Trip.totalConsumption;
}

float Trip::getTotalConsumption()
{
	return totalConsumption;
}

void Trip::setTotalConsumption(float ttl)
{
	this->totalConsumption = ttl;
}


/////////
class List : public Trip {
private:
	Trip* tripList;
	int size;
public:
	List() {
		size = 0;
	}; //Constructor by Default
	List(Trip arr); //Initializing Constructor
	List(const List &List); //Copying Constructor
	~List(); //Destructor

	Trip* getTripList();
	void setTripList(Trip*);
	void addTrip(Trip);
	void addTrip(Trip, int);
	void displayTripList();
	void removeTripAt(int);
	int getTripListsize();
	bool operator >(List s);
	bool operator <(List s);
	bool operator ==(List s);
	void operator +=(Trip e);
	Trip operator[](int index);
	operator int();
	/*
	friend ostream& operator<< (ostream& stream, List& o)
	{
	stream << "Waiter: " << o.Driver::getName() << " " << o.Waiter::getSurname() << endl << "gender[1-male, 2-female]: " << o.Waiter::getGender() << endl;
	stream << "Born: " << o.Waiter::Person::Date::getDay() << "/" << o.Waiter::Person::Date::getMonth() << "/" << o.Waiter::Person::Date::getYear() << endl;
	stream << "Category: [1-young, 2-average, 3-senior, 4-metr] " << o.getCategory() << endl;
	stream << "Working since: " << o.Waiter::Date::getDay() << "/" << o.Waiter::Date::getMonth() << "/" << o.Waiter::Date::getYear() << endl << endl;

	if (o.size != 0) {
	for (int i = 0; i < o.size; i++) {
	stream << "Trip " << i + 1 << endl;
	stream << o.Trips[i] << endl;
	}
	}
	else stream << "No Trips" << endl;

	return stream;
	}
	*/
};

List::List(Trip tr) : Trip(tr) {
	this->size = 0;
}

List::List(const List & List) : Trip(List) {
	size = List.size;
}

List::~List() {
	//delete[] tripList;
}

Trip* List::getTripList()
{
	return tripList;
}

void List::setTripList(Trip* d)
{
	this->tripList = d;
}

void List::addTrip(Trip d)
{
	addTrip(d, size);
}

void List::displayTripList()
{
	for (int i = 0; i < getTripListsize(); i++)
	{
		cout << "Trip " << i + 1 << endl;
		cout << tripList[i] << endl;
	}
}

void List::addTrip(Trip d, int ind)
{
	if (ind < 0 || ind > size) ind = size;

	Trip* tmp = new Trip[++size];

	for (int i = 0; i < ind; i++)
		tmp[i] = tripList[i];

	tmp[ind] = d;

	for (int i = ind + 1; i < size; i++)
		tmp[i] = tripList[i - 1];

	//delete[] tripList;
	tripList = tmp;
}

void List::removeTripAt(int ind)
{
	if (ind < 0 || ind >= size) return;

	Trip* tmp = new Trip[size - 1];

	for (int i = 0; i < ind; i++)
		tmp[i] = tripList[i];

	for (int i = ind + 1; i < size; i++)
		tmp[i - 1] = tripList[i];

	size--;
	delete[] tripList;
	tripList = tmp;
}

int List::getTripListsize()
{
	return size;
}

bool List::operator>(List o)
{
	return size > o.size;
}

bool List::operator<(List o)
{
	return size < o.size;
}

bool List::operator==(List o)
{
	return size == o.size;
}

void List::operator+=(Trip d)
{
	addTrip(d);
}

Trip List::operator[](int index)
{
	if (index < 0 || index > size || index >= 100) throw;

	return tripList[index];
}

List::operator int()
{
	return size;
}



//----- Stat
template <typename T>
T meanSquare(T* arr, int count)
{
	T sum = 0;

	for (int i = 0; i < count; i++) {
		sum += pow(arr[i], 2);
	}

	return sqrt(sum);
}

//----- Sorting
Trip* Sort1(Trip* obj, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			std::string s1 = obj[i].getSurname();
			std::string s2 = obj[j].getSurname();
			if (s1.compare(s2) > 0)
			{
				char* temp = obj[i].getSurname();
				obj[i].setSurname(obj[j].getSurname());
				obj[j].setSurname(temp);
			}
		}
	}
	return obj;
}

Trip* Sort2(Trip* obj, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (strcmp(obj[i].getSurname(), obj[j].getSurname()) > 0)
			{
				char* temp = obj[i].getSurname();
				obj[i].setSurname(obj[j].getSurname());
				obj[j].setSurname(temp);
			}
		}
	}
	return obj;
}




int main()
{
	/*
	//initializing
	Trip t1(14, 3, 2011, "Lviv", 564.3,
	26, 6, 1987, "John", "Stone", 1, 4207.34,
	"Mercedes", 18, 16.4,
	18, 3, 2011,
	72.2);
	printf("\t\t<<INITIALIZED TRIP>>\n\n");
	//t1.Show();

	//default
	Trip t2;
	printf("\n\n\t\t");
	printf("<<TRIP BY DEFAULT>>\n\n");
	//t2.Show();

	//copying
	Trip t3(t1);
	printf("\n\n\t\t");
	printf("<<COPIED TRIP>>\n\n");
	//t3.Show();

	printf("\n\n\n\n\t\t");
	printf("<<LIST OF TRIPS>>\n\n");
	Trip arr[3] = { t1, t2, t3 };

	List main(arr, 3);
	//main.List::Show();
	*/






	//----- Creating an array of objects
	List list70;
	List* listptr = &list70;
	listptr->addTrip(Trip(14, 3, 2011, "Lviv", 564.3,
		26, 6, 1987, "John", "Stone", 1, 4207.34,
		"Mercedes", 18, 11.1,
		18, 3, 2011,
		72.2));
	listptr->addTrip(Trip(14, 3, 2011, "qwerty", 664.3,
		26, 6, 1987, "Son", "Rock", 1, 7607.34,
		"Mercedes", 18, 22.2,
		18, 3, 2011,
		72.2));
	listptr->addTrip(Trip(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnson", "Bag", 1, 1307.34,
		"Mercedes", 18, 33.3,
		18, 3, 2011,
		72.2));

	*listptr += Trip(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnsonn", "Bag", 1, 1307.34,
		"Mercedes", 18, 44.4,
		18, 3, 2011,
		72.2);

	//----- Making a copy
	List list_copy;
	for (int i = 0; i < list70.getTripListsize(); i++)
		list_copy.addTrip(list70[i]);

	cout << "Amount of dishes: " << list70.getTripListsize() << endl << endl;
	float a[4];
	for (int i = 0; i < 4; i++) a[i] = list70[i].getConsumption();
	cout << "Mean square of Consumption: " << meanSquare(a, 4) << endl; 
	cout << endl << endl;

	//----- File Output
	/*ofstream file;
	do
	{
	char ans;
	char *path = new char[30];
	path = "D:/KPI/default.txt";
	cout << "Would you like to enter a path to the file?" << endl;
	cin >> ans;
	if (!(ans == 'y' || ans == 'Y' || ans == '+'))
	cout << "Using default path -- D:/KPI/default.txt" << endl;
	else
	{
	cout << "Enter the path to the file (disk:/[folder/]name.extension)" << endl;
	cin >> path;
	}
	file.open(path);
	if (file) {
	file << list70;
	cout << "Objects have been written to the file\n" << endl;
	}
	else cout << "Please enter correct path\n" << endl;
	if (!path)
	delete[] path;
	} while (!file);*/


	////----- Output versions
	//cout << "List Output" << endl;
	//list70.displayTripList();
	//----- List
	//List<Order> newlist;
	//newlist.Add(&list70);
	//newlist.DisplayAll();
	//----- Linked List
	//linklist<Order> orders;
	//orders.additem(list70);
	//orders.display();


	//----- Sorting Comparison
	srand(time(NULL));
	Sort1(list70.getTripList(), list70.getTripListsize());
	double first = clock();
	cout << setprecision(10);
	cout << endl << first / 1000 << " is STD::STRING time in ms" << endl;

	srand(time(NULL));
	Sort2(list_copy.getTripList(), list_copy.getTripListsize());
	double second = clock();
	cout << endl << second / 1000 << " is CHAR* time in ms" << endl;

	cout << endl << endl << "Difference in timing" << endl;
	cout << fabs(first - second) / 1000 << " ms" << endl;

	//----- Reaching the end of program
	cout << endl << "End of program" << endl;
	system("pause>>void");
}