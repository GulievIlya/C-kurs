#include <iostream>
#include "Classes.h"
using namespace std;

Driver::Driver() {}
Driver::Driver(string userName, string stazh, string numnumber, string carnum, string telephoneNum) {
	this->userName = userName;
	this->stazh = stazh;
	this->numnumber = numnumber;
	this->carnum = carnum;
	this->telephoneNum = telephoneNum;
}
string Driver::to_string() {
	return userName + "\n" + stazh + "\n" + numnumber + "\n" + carnum + "\n" + telephoneNum;
}
string Driver::getUserName() {
	return userName;
}
void Driver::setUserName(string userName) {
	this->userName = userName;
}
void Driver::setstazh(string stazh) {
	this->stazh = stazh;
}
void Driver::setnumnumber(string numnumber) {
	this->numnumber = numnumber;
}
void Driver::setcarnum(string carnum) {
	this->carnum = carnum;
}
void Driver::setTelephoneNum(string telephoneNum) {
	this->telephoneNum = telephoneNum;
}
void Driver::outData() {
	cout << "*____________" << endl;
	cout << "|ФИО водителя: " << userName << endl;
	cout << "|Стаж водителя: " << stazh << endl;
	cout << "|Номер машины водителя: " << numnumber << endl;
	cout << "|Автомобиль " << carnum << endl;
	cout << "|Телефон: " << telephoneNum << endl;
	cout << "*------------" << endl;
}
string Driver::getCar() {
	return carnum;
}


Car::Car() { }
Car::Car(string mark, string model, string num, string color, string year, string mileage, string hp, string consum) {
	this->mark = mark;
	this->model = model;
	this->num = num;
	this->color = color;
	this->year = year;
	this->mileage = mileage;
	this->hp = hp;
	this->consum = consum;
}
string Car::to_string() {
	return mark + "\n" + model + "\n" + num + "\n" + color + "\n" + mileage + "\n" + year + "\n" + hp + "\n" + consum;
}
string Car::getmark() {
	return mark;
}
void Car::setmark(string mark) {
	this->mark = mark;
}
void Car::setmodel(string model) {
	this->model = model;
}
void Car::setnum(string num) {
	this->num = num;
}
void Car::setcolor(string color) {
	this->color = color;
}
void Car::setyear(string year) {
	this->year = year;
}
void Car::setmileage(string mileage) {
	this->mileage = mileage;
}
void Car::sethp(string hp) {
	this->hp = hp;
}
void Car::setconsum(string consum) {
	this->consum = consum;
}
void Car::outData() {
	cout << "*____________" << endl;
	cout << "|Марка авто: " << mark << endl;
	cout << "|Модель авто: " << model << endl;
	cout << "|Номер авто: " << num << endl;
	cout << "|Цвет авто: " << color << endl;
	cout << "|Год выпуска авто: " << year << endl;
	cout << "|Пробег авто: " << mileage << " км" << endl;
	cout << "|Мощность авто: " << hp << " лc" << endl;
	cout << "|Расход авто: " << consum << " л" << endl;
	cout << "*------------" << endl;
}


Orders::Orders() {}
Orders::Orders(string cFIO, string time, string from, string to, string driver, string price, string avto) {
	this->cFIO = cFIO;
	this->time = time;
	this->from = from;
	this->to = to;
	this->driver = driver;
	this->price = price;
	this->avto = avto;
}

void Orders::outData() {
	cout << "*____________" << endl;
	cout << "|ФИО клиента: " << cFIO << endl;
	cout << "|Время заказа: " << time << endl;
	cout << "|Пункт отправки: " << from << endl;
	cout << "|Пункт назначения " << to << endl;
	cout << "|Водитель: " << driver << endl;
	cout << "|Цена: " << price << endl;
	cout << "|Автомобиль: " << avto << endl;
	cout << "*------------" << endl;
}

string Orders::to_string() {
	return cFIO + "\n" + time + "\n" + from + "\n" + to + "\n" + driver + "\n" + price + "\n" + avto;
}

void Orders::setcFIO(string cFIO) {
	this->cFIO = cFIO;
}
void Orders::settime(string time) {
	this->time = time;
}
void Orders::setfrom(string from) {
	this->from = from;
}
void Orders::setto(string to) {
	this->to = to;
}
void Orders::setdriver(string driver) {
	this->driver = driver;
}
void Orders::setprice(string price) {
	this->price = price;
}
void Orders::setavto(string avto) {
	this->avto = avto;
}