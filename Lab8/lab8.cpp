#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <string>

#include <vector> //std::vector
#include <typeinfo>
#include <algorithm> //std::sort
#include <iterator>
#include <array>
#include <functional>

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

	virtual int getDDay() {
		return day;
	}

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

	virtual char* getMModel() {
		return model;
	}

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

	virtual char* getNName() {
		return name;
	}

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
	for (int i = 0; i < 40; i++)
		stream << (char)196;
	stream << (char)191 << endl;

	stream << (char)179 << setw(10) << "Birth" << (char)179 << setw(14) << "Name" << (char)179 << setw(14) << "Surname" << (char)179 << endl;

	//middle
	stream << (char)195;
	for (int i = 0; i < 40; i++)
		stream << (char)196;
	stream << (char)180 << endl;

	stream << (char)179 << setfill('0') << setw(2) << person.getDay() << (char)47 << setw(2) << person.getMonth() << (char)47 << setw(4) << person.getYear() << setfill(' ') << (char)179;
	stream << setw(14) << person.getName() << (char)179 << setw(14) << person.getSurname() << (char)179 << endl;

	//bottom
	stream << (char)192;
	for (int i = 0; i < 40; i++)
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

	virtual int getRRank() {
		return rank;
	}

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

	virtual int getDDriver() {
		return day;
	}

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

	virtual int getSSize() {
		return size;
	}

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

	virtual float getTConsumption() {
		return totalConsumption;
	}

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

	virtual int getListSize() {
		return size;
	}

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

void List::printBinary(std::string path) {
	ofstream fout(path);
	fout.open(path + std::string("file_bin.bin"), ios::trunc | ios::binary);
	if (!fout)
		throw ("Nemozhlivo zapisati\n");

	for (int i = 0; i < getListLength(); i++) {

		char buff[20];

		fout.write(tripList[i].Application::getDestination(), sizeof(char[20]));

		int aday = tripList[i].Application::Date::getDay();
		_itoa(aday, buff, 10);
		fout.write(buff, sizeof(aday));

		int amonth = tripList[i].Application::Date::getMonth();
		_itoa(amonth, buff, 10);
		fout.write(buff, sizeof(amonth));

		int ayear = tripList[i].Application::Date::getYear();
		_itoa(ayear, buff, 10);
		fout.write(buff, sizeof(ayear));

		float asize = tripList[i].Application::getSize();
		_itoa(asize, buff, 10);
		fout.write(buff, sizeof(asize));

		int dday = tripList[i].Driver::Date::getDay();
		_itoa(dday, buff, 10);
		fout.write(buff, sizeof(dday));

		int dmonth = tripList[i].Driver::Date::getMonth();
		_itoa(dmonth, buff, 10);
		fout.write(buff, sizeof(dmonth));

		int dyear = tripList[i].Driver::Date::getYear();
		_itoa(dyear, buff, 10);
		fout.write(buff, sizeof(dyear));

		fout.write(tripList[i].Driver::getName(), sizeof(char[20]));
		fout.write(tripList[i].Driver::getSurname(), sizeof(char[20]));

		int drank = tripList[i].Driver::getRank();
		_itoa(drank, buff, 10);
		fout.write(buff, sizeof(drank));

		float dsalary = tripList[i].Driver::getSalary();
		_itoa(dsalary, buff, 10);
		fout.write(buff, sizeof(dsalary));

		fout.write(tripList[i].Bus::getModel(), sizeof(char[20]));

		int bseats = tripList[i].Bus::getSeats();
		_itoa(bseats, buff, 10);
		fout.write(buff, sizeof(bseats));

		float bconsumption = tripList[i].Bus::getConsumption();
		_itoa(bconsumption, buff, 10);
		fout.write(buff, sizeof(bconsumption));

		int day = tripList[i].Trip::Date::getDay();
		_itoa(day, buff, 10);
		fout.write(buff, sizeof(day));

		int month = tripList[i].Trip::Date::getMonth();
		_itoa(month, buff, 10);
		fout.write(buff, sizeof(month));

		int year = tripList[i].Trip::Date::getYear();
		_itoa(year, buff, 10);
		fout.write(buff, sizeof(year));

		float totalConsumption = tripList[i].getTotalConsumption();
		_itoa(totalConsumption, buff, 10);
		fout.write(buff, sizeof(totalConsumption));
	}

	std::cout << "Uspishno" << std::endl;
	fout.close();
}

void List::readBinary(std::string path) {
	std::ifstream fin(path + std::string("file_bin.bin"), std::ios_base::binary);
	if (!fin)
		throw("Unable to read from a binary file.\n");

	int startpos = fin.tellg();
	fin.seekg(0, std::ios::beg);

	int count = 1;

	char buff[20];

	//fin.read(buff, sizeof(char[20]));

	while (!fin.eof()) {
		fin.read(buff, sizeof(char[20]));
		char *destination = new char[strlen(buff) + 1];
		strcpy(destination, buff);

		fin.read(buff, sizeof(int));
		int aday = atoi(buff);
		fin.read(buff, sizeof(int));
		int amonth = atoi(buff);
		fin.read(buff, sizeof(int));
		int ayear = atoi(buff);

		fin.read(buff, sizeof(float));
		float size = atof(buff);

		fin.read(buff, sizeof(int));
		int dday = atoi(buff);
		fin.read(buff, sizeof(int));
		int dmonth = atoi(buff);
		fin.read(buff, sizeof(int));
		int dyear = atoi(buff);

		fin.read(buff, sizeof(char[20]));
		char *name = new char[strlen(buff) + 1];
		strcpy(name, buff);

		fin.read(buff, sizeof(char[20]));
		char *surname = new char[strlen(buff) + 1];
		strcpy(surname, buff);

		fin.read(buff, sizeof(int));
		int rank = atoi(buff);

		fin.read(buff, sizeof(float));
		float salary = atof(buff);

		fin.read(buff, sizeof(char[20]));
		char *model = new char[strlen(buff) + 1];
		strcpy(model, buff);

		fin.read(buff, sizeof(int));
		int seats = atoi(buff);

		fin.read(buff, sizeof(float));
		float consumption = atof(buff);

		fin.read(buff, sizeof(int));
		int day = atoi(buff);
		fin.read(buff, sizeof(int));
		int month = atoi(buff);
		fin.read(buff, sizeof(int));
		int year = atoi(buff);

		fin.read(buff, sizeof(float));
		float totalConsumption = atof(buff);

		Trip temp(aday, amonth, ayear, destination, size, dday, dmonth, dyear, name, surname, rank, salary, model, seats, consumption, day, month, year, totalConsumption);

		addTrip(temp);
		count++;
	}

	fin.close();
}


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
	else stream << "No Trips" << endl;

	return stream;
}

template <class T>
class ListTemptale
{
	int _listLength;
	T* _arr;

public:
	ListTemptale();
	void Add(T*);
	void Add(T*, int);
	void RemoveAt(int);
	void DisplayAll();
	int GetLength();
	T operator [](int);
};

template<class T>
ListTemptale<T>::ListTemptale() {
	_listLength = 0;
	_arr = nullptr;
}

template<class T>
void ListTemptale<T>::Add(T* obj)
{
	Add(obj, _listLength);
}

template<class T>
int ListTemptale<T>::GetLength()
{
	return _listLength;
}

template<class T>
void ListTemptale<T>::Add(T* obj, int ind)
{
	if (ind < 0 || ind > _listLength) ind = _listLength;

	T* tmp = new T[++_listLength];

	for (int i = 0; i < ind; i++)
		tmp[i] = _arr[i];

	tmp[ind] = *obj;

	for (int i = ind + 1; i < _listLength; i++)
		tmp[i] = _arr[i - 1];

	delete[] _arr;
	_arr = tmp;
}

template<class T>
void ListTemptale<T>::RemoveAt(int ind)
{
	if (ind < 0 || ind >= _listLength) return;

	T* tmp = new T[_listLength - 1];

	for (int i = 0; i < ind; i++)
		tmp[i] = _arr[i];

	for (int i = ind + 1; i < _listLength; i++)
		tmp[i - 1] = _arr[i];

	_listLength--;
	delete[] _arr;
	_arr = tmp;
}


template<class T>
T ListTemptale<T>::operator[](int index)
{
	if (index < 0 || index >= _listLength) throw;

	return _arr[index];
}

template<class T>
void ListTemptale<T>::DisplayAll()
{
	for (int i = 0; i < _listLength; i++)
	{
		cout << _arr[i];
	}
}



template <class Type>
class Objects {
private:
public:
	void save_bin(Type obj, int n) {
		ofstream output_file;
		output_file.open("D:/Study/OOP/binaryfile.bin", ios::binary);
		for (int i = 0; i < n; i++)
			output_file.write((char*)&obj[i], sizeof(obj[i]));
		output_file.close();
	}
	void save_text(Type& obj, std::string path, int n) {
		ofstream output_file;
		output_file.open(path);
		for (int i = 0; i < n; i++) {
			output_file << "Type is: " << (typeid(obj[i]).name()) << endl << endl;
			output_file << obj[i] << endl << endl;
		}
		output_file.close();
	}
	void save_text_single(Type& obj, std::string path) {
		ofstream output_file;
		output_file.open(path, ios::app);
		output_file << "The type of this oblect is: " << (typeid(obj).name()) << endl << endl;
		output_file << obj << endl << endl;
		output_file.close();
	}
};


int getTypeSizeFromId(const std::type_info& p) {

	if (p == typeid(Date)) {
		return sizeof(Date);
	}
	if (p == typeid(Person)) {
		return sizeof(Person);
	}
	if (p == typeid(Driver)) {
		return sizeof(Driver);
	}
	if (p == typeid(Trip)) {
		return sizeof(Trip);
	}
	if (p == typeid(List)) {
		return sizeof(List);
	}
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

bool numSort(Trip& a, Trip& b) {
	return a.getTotalConsumption() > b.getTotalConsumption();
}

bool charSort(Trip& a, Trip& b) {
	if (strcmp(a.getModel(), b.getModel()) > 0)
		return (1);
	else
		return (0);
}

//created sorting function for nums
//(char* was created earlier in the program)
Trip* Sort3(Trip* obj, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (obj[i].getConsumption() > obj[j].getConsumption())
			{
				double temp = obj[i].getConsumption();
				obj[i].setConsumption(obj[j].getConsumption());
				obj[j].setConsumption(temp);
			}
		}
	}
	return obj;
}


int askForMenu(void);

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
		18, 3, 2001,
		72.2);

	Trip tr4(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnsonn", "Bag", 1, 1307.34,
		"Mercedes", 18, 44.4,
		18, 3, 2015,
		72.2);

	Trip tr5;

	list.addTrip(tr1);
	list.addTrip(tr2);
	list.addTrip(tr3);
	list.addTrip(tr4);

	ListTemptale<List> listTrips;
	listTrips.Add(&list);
	//listTrips.DisplayAll();

	List listCopy;
	for (int i = 0; i < list.getListLength(); i++)
		listCopy.addTrip(list[i]);




















	// LAB 8

	cout << endl;

	//----- template object container
	Objects <List> o;
	o.save_text(list, "D:/Study/OOP/textfileorder.txt", list.getListLength());
	//read_bin(order66);

	////////////////////////////////////////////

	//array of pointers
	Date*	d1 = new Date(11, 4, 2001);
	Date*	d2 = new Date(22, 8, 2002);
	Person*	p1 = new Person(12, 11, 1977, "Qwerty", "Qwertiov");

	void *array[3];

	array[0] = d1;
	array[1] = d2;
	array[2] = p1;

	cout << typeid(*(Date*)(array[0])).name() << endl;
	cout << typeid(*(Date*)(array[1])).name() << endl;
	cout << typeid(*(Person*)(array[2])).name() << endl;

	/////
	cout << endl;
	/////

	void* p[2];
	p[0] = d1;
	p[1] = p1;
	cout << *((Date*)(p[0])) << endl;
	cout << *((Person*)(p[1])) << endl;

	/////
	cout << endl;
	/////

	//----- Bin file
	Date	date_test(3, 12, 1996);
	Person	person_test(1, 1, 1999, "Stolen", "Sunday");
	Driver	driver_test(1, 5, 2004, "John", "Son", 3, 3423.5);

	std::ofstream outfile;
	outfile.open("D:/Study/OOP/test.dat", std::ios::binary);
	if (outfile.is_open())
	{
		Date** arr = new Date*[3];
		arr[0] = &date_test;
		arr[1] = &person_test;
		arr[2] = &driver_test;
		int temp;
		for (int i = 0; i < 3; i++) {
			temp = getTypeSizeFromId(typeid(*(arr[i])));
			std::cout << temp << " " << typeid(*arr[i]).name() << std::endl;
			outfile.write(reinterpret_cast<const char*>(arr[i]), temp);
		}

		outfile.close();
	}
	std::ifstream infile;
	infile.open("D:/test.dat", std::ios::binary);
	cout << endl << "FROM FILE:" << endl;
	if (infile.is_open())
	{
		Date** arr = new Date*[3];
		arr[0] = new Date;
		arr[1] = new Person;
		arr[2] = new Driver;
		int temp;
		for (int i = 0; i < 3; i++) {
			temp = getTypeSizeFromId(typeid(*(arr[i])));
			infile.read(reinterpret_cast<char*>(arr[i]), temp);
			cout << *arr[i] << endl;
		}
		infile.close();
	}

	/////
	cout << endl;
	/////

	//----- Text file
	std::ofstream outfiletxt;
	outfiletxt.open("D:/test.txt");
	if (outfiletxt.is_open())
	{
		Date** arr = new Date*[3];
		arr[0] = &date_test;
		arr[1] = &person_test;
		arr[2] = &driver_test;
		int temp;
		for (int i = 0; i < 3; i++) {
			temp = getTypeSizeFromId(typeid(*(arr[i])));
			//std::cout << temp << " " << typeid(*arr[i]).name() << std::endl;
			//outfiletxt.write(reinterpret_cast<const char*>(arr[i]), temp);
			outfiletxt << *arr[i];
		}

		outfiletxt.close();
	}



	/*
	std::ifstream infiletxt;
	infiletxt.open("D:/test.txt");
	cout << endl << "FROM FILE:" << endl;
	if (infiletxt.is_open())
	{
	Date** arr = new Date*[3];
	arr[0] = new Date;
	arr[1] = new Person;
	arr[2] = new Waiter;
	int temp;
	for (int i = 0; i < 3; i++) {
	temp = getTypeSizeFromId(typeid(*(arr[i])));
	infiletxt.read(reinterpret_cast<char*>(arr[i]), temp);
	cout << *arr[i] << endl;
	}

	infiletxt.close();
	}*/



	////////////////////////////////////

	Trip *dishes = new Trip[8]();
	Objects <Trip> di;
	for (int i = 0; i < 8; i++)
		di.save_text_single(*dishes, "D:/Study/OOP/textfiletrips.txt");

	Date *dates = new Date[8]();
	Objects <Date> da;
	for (int i = 0; i < 8; i++)
		da.save_text_single(*dates, "D:/Study/OOP/textfiledates.txt");

	Driver *drivers = new Driver[8]();
	Objects <Driver> w;
	for (int i = 0; i < 8; i++)
		w.save_text_single(*drivers, "D:/Study/OOP/textfiledrivers.txt");

	////////////////////////////////////

	//----- containers for sorting (vector)
	vector <Trip> vect;
	vect.reserve(8);
	vect.push_back(Trip(14, 3, 2011, "Lviv", 564.3,
		26, 6, 1987, "John", "Stone", 1, 4207.34,
		"Mercedes", 18, 11.1,
		18, 3, 2011,
		72.2));
	vect.push_back(Trip(14, 3, 2011, "qwerty", 664.3,
		26, 6, 1987, "Son", "Rock", 1, 7607.34,
		"Mercedes", 18, 22.2,
		18, 3, 2011,
		72.2));
	vect.push_back(Trip(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnson", "Bag", 1, 1307.34,
		"Mercedes", 18, 33.3,
		18, 3, 2001,
		72.2));
	vect.push_back(Trip(14, 3, 2011, "Lviv", 564.3,
		26, 6, 1987, "John", "Stone", 1, 4207.34,
		"Mercedes", 18, 11.1,
		18, 3, 2011,
		72.2));
	vect.push_back(Trip(14, 3, 2011, "qwerty", 664.3,
		26, 6, 1987, "Son", "Rock", 1, 7607.34,
		"Mercedes", 18, 22.2,
		18, 3, 2011,
		72.2));
	vect.push_back(Trip(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnson", "Bag", 1, 1307.34,
		"Mercedes", 18, 33.3,
		18, 3, 2001,
		72.2));
	vect.push_back(Trip(14, 3, 2011, "Lviv", 564.3,
		26, 6, 1987, "John", "Stone", 1, 4207.34,
		"Mercedes", 18, 11.1,
		18, 3, 2011,
		72.2));
	vect.push_back(Trip(14, 3, 2011, "qwerty", 664.3,
		26, 6, 1987, "Son", "Rock", 1, 7607.34,
		"Mercedes", 18, 22.2,
		18, 3, 2011,
		72.2));

	vector <Trip> vect_copy;
	vect_copy.reserve(8);
	vect_copy.push_back(Trip(14, 3, 2011, "Lviv", 564.3,
		26, 6, 1987, "John", "Stone", 1, 4207.34,
		"Mercedes", 18, 11.1,
		18, 3, 2011,
		72.2));
	vect_copy.push_back(Trip(14, 3, 2011, "qwerty", 664.3,
		26, 6, 1987, "Son", "Rock", 1, 7607.34,
		"Mercedes", 18, 22.2,
		18, 3, 2011,
		72.2));
	vect_copy.push_back(Trip(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnson", "Bag", 1, 1307.34,
		"Mercedes", 18, 33.3,
		18, 3, 2001,
		72.2));
	vect_copy.push_back(Trip(14, 3, 2011, "Lviv", 564.3,
		26, 6, 1987, "John", "Stone", 1, 4207.34,
		"Mercedes", 18, 11.1,
		18, 3, 2011,
		72.2));
	vect_copy.push_back(Trip(14, 3, 2011, "qwerty", 664.3,
		26, 6, 1987, "Son", "Rock", 1, 7607.34,
		"Mercedes", 18, 22.2,
		18, 3, 2011,
		72.2));
	vect_copy.push_back(Trip(14, 3, 2011, "Kyiv", 364.3,
		26, 6, 1987, "Johnson", "Bag", 1, 1307.34,
		"Mercedes", 18, 33.3,
		18, 3, 2001,
		72.2));	vect_copy.push_back(Trip(14, 3, 2011, "Lviv", 564.3,
			26, 6, 1987, "John", "Stone", 1, 4207.34,
			"Mercedes", 18, 11.1,
			18, 3, 2011,
			72.2));
	vect_copy.push_back(Trip(14, 3, 2011, "qwerty", 664.3,
		26, 6, 1987, "Son", "Rock", 1, 7607.34,
		"Mercedes", 18, 22.2,
		18, 3, 2011,
		72.2));


	//----- Sorting Comparison
	std::cout << endl << endl << "My sorting:" << endl;
	cout << fixed << setprecision(4);
	srand(time(NULL));
	Sort3(list.getList(), list.getListLength());
	double time1 = clock();
	std::cout << "Num my sort time: " << time1 / 1000 << "ms" << endl;

	srand(time(NULL)); +
		Sort2(listCopy.getList(), listCopy.getListLength());
	double time2 = clock();
	std::cout << "Char* my sort time: " << time2 / 1000 << "ms" << endl;

	//sorting comparison with standard function

	std::cout << endl << "Standard sorting:" << endl;
	srand(time(NULL));
	std::sort(vect.begin(), vect.end(), numSort);
	double time3 = clock();
	std::cout << "Num standard sort time: " << time3 / 1000 << "ms" << endl;

	srand(time(NULL));
	std::sort(vect.begin(), vect.end(), charSort);
	double time4 = clock();
	std::cout << "Char* standard sort time: " << time4 / 1000 << "ms" << endl;

	//}
	//catch (ExceptionHierarchy obj) {
	//cout << obj.what() << endl;
	//}





















	int choice, correct = 0;
	do {
		choice = askForMenu();
		switch (choice)
		{
		case 1:
		{
			cout << list;
			break;
		}
		case 2:
		{
			std::string dir = "D:/Study/OOP/";
			ofstream file_text(dir);
			bool check = false;
			char answer;
			do {
				std::cout << std::endl << "Vvoditi direktoriyu? (y/n)";
				std::cin >> answer;
				if (answer == 'y' || answer == 'Y') {
					std::cout << "Vvedit direktoriyu(disk:/[folder/])" << std::endl;
					std::string newdir;
					std::cin >> newdir;
					dir = newdir;
					std::cout << "Direktoriya  " << dir << std::endl;
					check = true;
				}
				else if (answer == 'n' || answer == 'N') {
					std::cout << "Vikoristannia direktorii za zamovchuvaniam (D:/)" << std::endl;
					check = true;
				}
				else
					check == false;
			} while (!check);

			file_text.open(dir + std::string("file_text.txt"), ios::trunc);
			if (!file_text)
				throw ("Nemozhlivo vidkriti file\n");
			else {
				file_text << list;
				std::cout << "Uspishno" << std::endl;

				list.printBinary(dir);
			}
			file_text.close();
			break;
		}
		case 3:
		{
			char ans;
			char ans_path;
			std::string path = "D:/Study/OOP/";
			do
			{
				std::cout << std::endl << "Read from text or binary? [t/b]" << std::endl;
				std::cin >> ans;
			} while (!(ans == 't' || ans == 'T' || ans == 'b' || ans == 'B'));

			std::cout << std::endl << "Would you like to enter a path to the files? [y/n]";
			std::cin >> ans_path;
			if (ans_path == 'n' || ans_path == 'N')
				std::cout << "Using default path -- D:/" << std::endl;
			else if (ans_path == 'y' || ans_path == 'Y')
			{
				std::cout << "Enter the path to the file (disk:/[folder/])" << std::endl;
				std::string newpath;
				std::cin >> newpath;
				path = newpath;
				std::cout << "path = " << path;
			}

			if (ans == 't' || ans == 'T') {
				std::string line;
				ifstream itext(path + std::string("file_text.txt"));
				if (itext.is_open()) {
					std::cout << "Text opening successful" << std::endl;
					while (getline(itext, line))
						std::cout << line << std::endl;
					itext.close();
				}
				else
					std::cout << "Error opening a text file." << std::endl;
			}
			else if (ans == 'b' || ans == 'B') {
				list.readBinary(path);
			}
			break;
		}
		case 0:
			std::cout << std::endl << "Program exiting... [Press any key]" << std::endl;
			break;
		default:
			throw("Invalid menu option chosen\n");
		}
	} while (choice != 0);
	return (0);
}

int askForMenu(void)
{
	fflush(stdin);
	bool flag = true;
	int ans, incorrect;
	char *input = new char[10];
	do {
		incorrect = 0;
		std::cout << std::endl << "\tEnter your option:" << std::endl;
		std::cout << "1 -- Output data" << std::endl;
		std::cout << "2 -- Write data on disk in a file (text and binary)." << std::endl;
		std::cout << "3 -- Read data from file." << std::endl;
		std::cout << "0 -- Exit" << std::endl << std::endl;
		std::cin >> input;
		for (int i = 0; i < strlen(input); i++)
			if (!isdigit(input[i]))
				incorrect++;
		ans = atoi(input);
		if ((incorrect != 0) || (strlen(input) == 0))
			std::cout << "Error. Try again" << std::endl;
		else if ((ans == 0) || (ans == 1) || (ans == 2) || (ans == 3))
			flag = false;
		else
			std::cout << "Error. Try again" << std::endl;
	} while (flag);

	delete[] input;
	return ans;
}