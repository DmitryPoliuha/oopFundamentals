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

	friend ostream& operator<< (ostream& stream, Date& date);
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

ostream& operator<< (ostream& stream, Date& date) {
	//шапка
	stream << (char)218;
	for (int i = 0; i < 10; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(10) << "Date" << (char)179 << endl;

	//середина
	stream << (char)195;
	for (int i = 0; i < 10; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill('0') << setw(2) << date.getDay() << (char)47 << setw(2) << date.getMonth() << (char)47 << setw(4) << date.getYear() << setfill(' ') << (char)179 << endl;

	//низ
	stream << (char)192;
	for (int i = 0; i < 10; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
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

	friend ostream& operator<< (ostream& stream, Bus& bus);
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

ostream& operator<< (ostream& stream, Bus& bus) {
	//шапка
	stream << (char)218;
	for (int i = 0; i < 28; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(14) << "Model" << (char)179 << setw(6) << "Seats" << (char)179 << setw(16) << "Consumption" << (char)179 << endl;

	//середина
	stream << (char)195;
	for (int i = 0; i < 28; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setw(14) << bus.getModel() << (char)179 << setw(6) << bus.getSeats() << (char)179 << setw(16) << bus.getConsumption() << setfill(' ') << (char)179 << endl;

	//низ
	stream << (char)192;
	for (int i = 0; i < 28; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
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

	friend ostream& operator<< (ostream& stream, Person& person);
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

ostream& operator<< (ostream& stream, Person& person) {
	//top header
	stream << (char)218;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(10) << "Birth" << (char)179 << setw(14) << "Name" << (char)179 << setw(14) << "Surname" << (char)179 << endl;

	//middle
	stream << (char)195;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill('0') << setw(2) << person.getDay() << (char)47 << setw(2) << person.getMonth() << (char)47 << setw(4) << person.getYear() << setfill(' ') << (char)179;
	stream << setw(14) << person.getName() << (char)179 << setw(14) << person.getSurname() << (char)179 << endl;

	//bottom
	stream << (char)192;
	for (int i = 0; i < 38; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
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

	friend ostream& operator<< (ostream& stream, Category& category);
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

ostream& operator<< (ostream& stream, Category& category) {
	//шапка
	stream << (char)218;
	for (int i = 0; i < 13; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(4) << "Rank" << (char)179 << setw(8) << "Salary" << (char)179 << endl;

	//середина
	stream << (char)195;
	for (int i = 0; i < 13; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setw(4) << category.getRank() << (char)179 << setw(8) << category.getSalary() << (char)179 << endl;

	//низ
	stream << (char)192;
	for (int i = 0; i < 13; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
}


/////////
class Driver : public Person, public Category {
public:
	Driver(); //Constructor by Default
	Driver(int, int, int, char*, char*, int, float); //Initializing Constructor
	Driver(const Driver &Driver); //Copying Constructor
	~Driver() {}; //Destructor

	friend ostream& operator<< (ostream& stream, Driver& driver);
};

Driver::Driver() : Person(), Category() {
}

Driver::Driver(int pday, int pmonth, int pyear, char* tpname, char* tpsurname, int rrank, float ssalary) : Person(pday, pmonth, pyear, tpname, tpsurname),
Category(rrank, ssalary) {
}

Driver::Driver(const Driver &Driver) : Person(Driver), Category(Driver) {
}

ostream& operator<< (ostream& stream, Driver& driver) {
	//top header
	stream << (char)218;
	for (int i = 0; i < 54; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(10) << "Birth" << (char)179 << setw(14) << "Name" << (char)179 << setw(14) << "Surname" << (char)179 << setw(4) << "Rank" << (char)179 << setw(8) << "Salary" << (char)179 << endl;

	//middle
	stream << (char)195;
	for (int i = 0; i < 54; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill('0') << setw(2) << driver.getDay() << (char)47 << setw(2) << driver.getMonth() << (char)47 << setw(4) << driver.getYear() << setfill(' ') << (char)179;
	stream << setw(14) << driver.getName() << (char)179 << setw(14) << driver.getSurname() << (char)179 << setw(4) << driver.getRank() << (char)179 << setw(8) << driver.getSalary() << (char)179 << endl;

	//bottom
	stream << (char)192;
	for (int i = 0; i < 54; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
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
	float getSize();
	void setDestination(char*);
	void setSize(float);

	friend ostream& operator<< (ostream& stream, Application& application);
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

float Application::getSize()
{
	return size;
}

void Application::setDestination(char* dst)
{
	this->destination = dst;
}

void Application::setSize(float lng)
{
	this->size = lng;
}

ostream& operator<< (ostream& stream, Application& application) {
	//top header
	stream << (char)218;
	for (int i = 0; i < 32; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(10) << "Birth" << (char)179 << setw(14) << "Destination" << (char)179 << setw(8) << "Size" << (char)179 << endl;

	//middle
	stream << (char)195;
	for (int i = 0; i < 32; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill('0') << setw(2) << application.getDay() << (char)47 << setw(2) << application.getMonth() << (char)47 << setw(4) << application.getYear() << setfill(' ') << (char)179;
	stream << setw(14) << application.getDestination() << (char)179 << setw(8) << application.getSize() << (char)179 << endl;

	//bottom
	stream << (char)192;
	for (int i = 0; i < 32; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
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

	friend ostream& operator<< (ostream& stream, Trip& trip);
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

ostream& operator<< (ostream& stream, Trip& trip) {
	//top header
	stream << (char)218;
	for (int i = 0; i < 139; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(10) << "Date A" << (char)179 << setw(14) << "Destination" << (char)179 << setw(8) << "Size" << (char)179;
	stream << setw(10) << "Birth" << (char)179 << setw(14) << "Name" << (char)179 << setw(14) << "Surname" << (char)179 << setw(4) << "Rank" << (char)179 << setw(8) << "Salary" << (char)179;
	stream << setw(14) << "Model" << (char)179 << setw(6) << "Seats" << (char)179 << setw(16) << "Consumption" << (char)179;
	stream << setw(10) << "Date" << (char)179 << endl;


	//middle
	stream << (char)195;
	for (int i = 0; i < 139; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill('0') << setw(2) << trip.Application::getDay() << (char)47 << setw(2) << trip.Application::getMonth() << (char)47 << setw(4) << trip.Application::getYear() << setfill(' ') << (char)179;
	stream << setw(14) << trip.getDestination() << (char)179 << setw(8) << trip.getSize() << (char)179;
	stream << setfill('0') << setw(2) << trip.Driver::getDay() << (char)47 << setw(2) << trip.Driver::getMonth() << (char)47 << setw(4) << trip.Driver::getYear() << setfill(' ') << (char)179;
	stream << setw(14) << trip.getName() << (char)179 << setw(14) << trip.getSurname() << (char)179 << setw(4) << trip.getRank() << (char)179 << setw(8) << trip.getSalary() << (char)179;
	stream << setw(14) << trip.getModel() << (char)179 << setw(6) << trip.getSeats() << (char)179 << setw(16) << trip.getConsumption() << setfill(' ') << (char)179;
	stream << setfill('0') << setw(2) << trip.Date::getDay() << (char)47 << setw(2) << trip.Date::getMonth() << (char)47 << setw(4) << trip.Date::getYear() << setfill(' ') << (char)179 << endl;


	//bottom
	stream << (char)192;
	for (int i = 0; i < 139; i++)
		stream << (char)196;
	stream << (char)217 << endl;

	return stream;
}


/////////
class List : public Trip {
private:
	Trip* tripList;
	int size;
public:
	List();
	List(Trip);
	List(const List &list);

	Trip* getList();
	void setList(Trip*);
	void addTrip(Trip);
	void addTrip(Trip, int);
	void removeTripAt(int);
	int getListLength();

	void operator +=(Trip);
	Trip operator[](int);

	void printBinary(std::string);
	void readBinary(std::string);

	friend ostream& operator<< (ostream& stream, List& list);
};

List::List() {
	this->size = 0;
}

List::List(Trip trip) : Trip(trip) { }

List::List(const List &tdList) : Trip(tdList) {
	this->size = tdList.size;
}

Trip* List::getList() {
	return tripList;
}

void List::setList(Trip* td) {
	this->tripList = td;
}

void List::addTrip(Trip td_lst) {
	addTrip(td_lst, size);
}

void List::addTrip(Trip a, int ind) {
	if (ind < 0 || ind > size) ind = size;

	Trip* tmp = new Trip[++size];

	for (int i = 0; i < ind; i++)
		tmp[i] = tripList[i];

	tmp[ind] = a;

	for (int i = ind + 1; i < size; i++)
		tmp[i] = tripList[i - 1];

	//delete[] csList;
	tripList = tmp;
}

void List::removeTripAt(int ind) {
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

int List::getListLength() {
	return size;
}

void List::operator+=(Trip a) {
	addTrip(a);
}

Trip List::operator[](int index) {
	if (index < 0 || index > size || index >= 100) throw;

	return tripList[index];
}
/*
void ArchiveItem::printBinary(std::string path) {
ofstream fout(path);
fout.open(path + std::string("file_bin.bin"), ios::trunc | ios::binary);
if (!fout)
throw ("Unable to write to a binary file.\n");

for (int i = 0; i < getListLength(); i++) {

char buff[20];

int pday = tdList[i].Person::getDay();
_itoa(pday, buff, 10);
fout.write(buff, sizeof(pday));

int pmonth = tdList[i].Person::getMonth();
_itoa(pmonth, buff, 10);
fout.write(buff, sizeof(pmonth));

int pyear = tdList[i].Person::getYear();
_itoa(pyear, buff, 10);
fout.write(buff, sizeof(pyear));

fout.write(tdList[i].Person::getName(), sizeof(char[20]));
fout.write(tdList[i].Person::getSurname(), sizeof(char[20]));

int fday = tdList[i].File::getDay();
_itoa(fday, buff, 10);
fout.write(buff, sizeof(fday));

int fmonth = tdList[i].File::getMonth();
_itoa(fmonth, buff, 10);
fout.write(buff, sizeof(fmonth));

int fyear = tdList[i].File::getYear();
_itoa(fyear, buff, 10);
fout.write(buff, sizeof(fyear));

fout.write(tdList[i].File::getFileName(), sizeof(char[20]));
fout.write(tdList[i].File::getType(), sizeof(char[20]));

double size = tdList[i].File::getSize();
_itoa(size, buff, 10);
fout.write(buff, sizeof(size));

fout.write(tdList[i].TextDoc::getLocation(), sizeof(char[20]));
fout.write(tdList[i].TextDoc::getKeyWords(), sizeof(char[20]));

int day = tdList[i].Date::getDay();
_itoa(day, buff, 10);
fout.write(buff, sizeof(day));

int month = tdList[i].Date::getMonth();
_itoa(month, buff, 10);
fout.write(buff, sizeof(month));

int year = tdList[i].Date::getYear();
_itoa(year, buff, 10);
fout.write(buff, sizeof(year));
}

std::cout << "Successful binary writing." << std::endl;
fout.close();
}

void ArchiveItem::readBinary(std::string path) {
std::ifstream fin(path + std::string("file_bin.bin"), std::ios_base::binary);
if (!fin)
throw("Unable to read from a binary file.\n");

int startpos = fin.tellg();
fin.seekg(0, std::ios::beg);

int count = 1;

char buff[20];

fin.read(buff, sizeof(char[20]));

while (!fin.eof()) {

fin.read(buff, sizeof(int));
int pday = atoi(buff);

fin.read(buff, sizeof(int));
int pmonth = atoi(buff);

fin.read(buff, sizeof(int));
int pyear = atoi(buff);

fin.read(buff, sizeof(char[20]));
char *name = new char[strlen(buff) + 1];
strcpy(name, buff);

fin.read(buff, sizeof(char[20]));
char *surname = new char[strlen(buff) + 1];
strcpy(surname, buff);

fin.read(buff, sizeof(int));
int fday = atoi(buff);

fin.read(buff, sizeof(int));
int fmonth = atoi(buff);

fin.read(buff, sizeof(int));
int fyear = atoi(buff);

fin.read(buff, sizeof(char[20]));
char *fileName = new char[strlen(buff) + 1];
strcpy(fileName, buff);

fin.read(buff, sizeof(char[20]));
char *type = new char[strlen(buff) + 1];
strcpy(type, buff);

fin.read(buff, sizeof(double));
double size = atof(buff);

fin.read(buff, sizeof(char[20]));
char *location = new char[strlen(buff) + 1];
strcpy(location, buff);

fin.read(buff, sizeof(char[20]));
char *keyWords = new char[strlen(buff) + 1];
strcpy(keyWords, buff);

fin.read(buff, sizeof(int));
int day = atoi(buff);

fin.read(buff, sizeof(int));
int month = atoi(buff);

fin.read(buff, sizeof(int));
int year = atoi(buff);

TextDoc temp(fday, fmonth, fyear, fileName, type, size, pday, pmonth, pyear, name, surname, location, keyWords);

addTextDoc(temp);
count++;
}

fin.close();
}
*/

ostream& operator<< (ostream& stream, List& list) {
	if (list.size != 0) {
		//шапка
		stream << (char)218;
		for (int i = 0; i < 139; i++)
			stream << (char)196;
		stream << (char)191 << endl;

		stream << (char)179 << setw(10) << "Date A" << (char)179 << setw(14) << "Destination" << (char)179 << setw(8) << "Size" << (char)179;
		stream << setw(10) << "Birth" << (char)179 << setw(14) << "Name" << (char)179 << setw(14) << "Surname" << (char)179 << setw(4) << "Rank" << (char)179 << setw(8) << "Salary" << (char)179;
		stream << setw(14) << "Model" << (char)179 << setw(6) << "Seats" << (char)179 << setw(16) << "Consumption" << (char)179;
		stream << setw(10) << "Date" << (char)179 << endl;

		//middle
		stream << (char)195;
		for (int i = 0; i < 139; i++)
			stream << (char)196;
		stream << (char)180 << endl;

		for (int i = 0; i < list.size; i++) {
			stream << (char)179 << setfill('0') << setw(2) << list[i].Application::getDay() << (char)47 << setw(2) << list[i].Application::getMonth() << (char)47 << setw(4) << list[i].Application::getYear() << setfill(' ') << (char)179;
			stream << setw(14) << list[i].getDestination() << (char)179 << setw(8) << list[i].getSize() << (char)179;
			stream << setfill('0') << setw(2) << list[i].Driver::getDay() << (char)47 << setw(2) << list[i].Driver::getMonth() << (char)47 << setw(4) << list[i].Driver::getYear() << setfill(' ') << (char)179;
			stream << setw(14) << list[i].getName() << (char)179 << setw(14) << list[i].getSurname() << (char)179 << setw(4) << list[i].getRank() << (char)179 << setw(8) << list[i].getSalary() << (char)179;
			stream << setw(14) << list[i].getModel() << (char)179 << setw(6) << list[i].getSeats() << (char)179 << setw(16) << list[i].getConsumption() << setfill(' ') << (char)179;
			stream << setfill('0') << setw(2) << list[i].Date::getDay() << (char)47 << setw(2) << list[i].Date::getMonth() << (char)47 << setw(4) << list[i].Date::getYear() << setfill(' ') << (char)179 << endl;
		}

		//низ
		stream << (char)192;
		for (int i = 0; i < 139; i++)
			stream << (char)196;
		stream << (char)217 << endl;

		return stream;
	}
	else stream << "No CircleSquares" << endl;

	return stream;
}


int main()
{

	List list;
	Trip tr1(14, 3, 2011, "Lviv", 564.3,
		26, 6, 1987, "John", "Stone", 1, 4207.34,
		"Mercedes", 18, 11.1,
		18, 3, 2011,
		72.2);

	Trip tr2(14, 3, 2011, "qwerty", 664.3,
		26, 6, 1987, "Son", "Rock", 1, 7607.34,
		"Mercedes", 18, 22.2,
		18, 3, 2011,
		72.2);

	Trip tr3(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnson", "Bag", 1, 1307.34,
		"Mercedes", 18, 33.3,
		18, 3, 2011,
		72.2);

	Trip tr4(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnsonn", "Bag", 1, 1307.34,
		"Mercedes", 18, 44.4,
		18, 3, 2011,
		72.2);

	Trip tr5;

	list.addTrip(tr1);
	list.addTrip(tr2);
	list.addTrip(tr3);
	list.addTrip(tr4);

	cout << list;

	cout << endl << "End of program" << endl;
	system("pause>>void");
}