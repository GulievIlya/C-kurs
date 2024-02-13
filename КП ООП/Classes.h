#pragma once
#include <string>
using namespace std;
class Car {
	string mark;
	string model;
	string num;
	string color;
	string year;
	string mileage;
	string hp;
	string consum;
public:
	Car();
	Car(string, string, string, string, string, string, string, string);
	string getmark();
	void setmark(string mark);
	void setmodel(string model);
	void setnum(string num);
	void setcolor(string color);
	void setyear(string year);
	void setmileage(string mileage);
	void sethp(string hp);
	void setconsum(string consum);
	string to_string();
	void outData();
};

class Driver
{
private:
	string userName;
	string stazh;
	string numnumber;
	string carnum;
	string telephoneNum;
public:
	Driver();
	Driver(string, string, string, string, string);
	string getUserName();
	string getCar();
	string to_string();
	void setUserName(string);
	void setstazh(string);
	void setnumnumber(string);
	void setcarnum(string);
	void setTelephoneNum(string);
	void outData();
};

class Orders : public Car, public Driver {
	string cFIO;
	string time;
	string from;
	string to;
	string driver;
	string price;
	string avto;
public:
	Orders();
	Orders(string, string, string, string, string, string, string);
	string to_string();
	void outData();
	void setcFIO(string);
	void settime(string);
	void setfrom(string);
	void setto(string);
	void setdriver(string);
	void setavto(string);
	void setprice(string);
};