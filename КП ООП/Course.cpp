#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "Classes.h"
#include "Func.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu();
	return 0;
}


void menu() {
	int choose = 1;
	while (1) {
		cout << "\t|----------------------|\n";
		cout << "\t|        ����          |\n";
		cout << "\t|----------------------|\n";
		cout << "\t|1. ��������           |\n";
		cout << "\t|2. ��������           |\n";
		cout << "\t|3. ������             |\n";
		cout << "\t|4. �����              |\n";
		cout << "\t|----------------------|\n";
		cout << "\n";
		cin >> choose;
		switch (choose) {
		case(1): system("cls");  menuDrivers(choose); break;
		case(2): system("cls");  carmenu(choose); break;
		case(3): system("cls");  ordermenu(choose);  break;
		case(4): exit(0);
		default: cout << "�� ����� ������������ ��������. �������� ����� ����.";
		}
	}
}

void menuDrivers(int choose) {
	bool repeat = true;
	while (repeat) {
		cout << "\t_________________________\n";
		cout << "\t|        ��������       |\n";
		cout << "\t|-----------------------|\n";
		cout << "\t|1. ������ ���������    |\n";
		cout << "\t|2. �������� ������     |\n";
		cout << "\t|3. ��������            |\n";
		cout << "\t|4. �������             |\n";
		cout << "\t|5. �����               |\n";
		cout << "\t-------------------------\n";
		cin >> choose;
		system("cls");
		switch (choose) {
		case (1): {
			alldriver();
			system("pause"); system("cls");
			break;
		}
		case(2): {
			changedriver(choose);
			system("pause"); system("cls");
			break;
		}
		case(3): {
			adddriver();
			system("pause"); system("cls");
			break;
		}
		case(4): {
			delDriver();
			system("pause"); system("cls");
			break;
		}
		case(5): {
			repeat = false;
			system("cls"); break;
		}
		default: {
			cout << "�� ����� ������������ ��������. �������� ����� ����" << endl;
			system("pause"); system("cls");
		}
		}
	}
	menu();
}

void carmenu(int choose) {
	bool repeat = true;
	while (repeat) {
		cout << "\t_________________________\n";
		cout << "\t|        ��������       |\n";
		cout << "\t|-----------------------|\n";
		cout << "\t|1. ������              |\n";
		cout << "\t|2. �������� ������     |\n";
		cout << "\t|3. ��������            |\n";
		cout << "\t|4. �������             |\n";
		cout << "\t|5. �����               |\n";
		cout << "\t-------------------------\n";
		cin >> choose;
		system("cls");
		switch (choose) {
		case(1):
		{
			allCars();
			system("pause"); system("cls");
			break;
		}
		case(2):
		{
			changecar(choose);
			system("pause"); system("cls");
			break;
		}
		case(3): {
			addCar();
			system("pause"); system("cls");
			break;
		}
		case(4): {
			delCar();
			system("pause"); system("cls");
			break;
		}
		case(5): {
			repeat = false;
			system("cls");
			break;
		}
		default: {
			cout << "������� ������������ ��������. �������� ����� ����." << endl;
		}
		}
	}
	menu();
}

void ordermenu(int choose) {
	bool repeat = true;
	while (repeat) {
		cout << "\t_________________________\n";
		cout << "\t|         ������        |\n";
		cout << "\t|-----------------------|\n";
		cout << "\t|1. ������              |\n";
		cout << "\t|2. �������� ������     |\n";
		cout << "\t|3. ��������            |\n";
		cout << "\t|4. �������             |\n";
		cout << "\t|5. �����               |\n";
		cout << "\t-------------------------\n";
		cin >> choose;
		system("cls");
		switch (choose) {
		case(1):
		{
			allOrders();
			system("pause"); system("cls");
			break;
		}
		case(2):
		{
			changeOrder(choose);
			system("pause"); system("cls");
			break;
		}
		case(3): {
			addOrder();
			system("pause"); system("cls");
			break;
		}
		case(4): {
			delOrder();
			system("pause"); system("cls");
			break;
		}
		case(5): {
			repeat = false;
			system("cls");
			break;
		}
		default: {
			cout << "������� ������������ ��������. �������� ����� ����." << endl;
		}
		}
	}
	menu();
}

void getData(vector<Driver>& driver) {
	ifstream read;
	read.open(Dfile);
	driver.clear();
	if (read.is_open()) {
		while (!read.eof()) {
			string username, stazh, number, car, phonenum;
			getline(read, username);
			if (!username.size()) break;
			getline(read, stazh);
			getline(read, number);
			getline(read, car);
			getline(read, phonenum);
			Driver us{ username,stazh,number,car,phonenum };
			driver.push_back(us);
		}
	}
	read.close();
}

string infoSet(vector<Driver>& driver, string userName, string infonew, int choose) {
	if (driver.empty()) getData(driver);
	for (int i = 0; i < driver.size(); i++) {
		Driver us = { driver[i] };
		string userString = us.to_string();
		if (userString.find(userName) != string::npos) {
			switch (choose) {
			case(1): us.setUserName(infonew);
				driver[i] = us; break;
			case(2): us.setstazh(infonew);
				driver[i] = us; break;
			case(3): us.setnumnumber(infonew);
				driver[i] = us; break;
			case(4): us.setcarnum(infonew);
				driver[i] = us; break;
			case(5): us.setTelephoneNum(infonew);
				driver[i] = us; break;
			}
			update(driver);
			return "������ �������� ��������";
		}
	}
	return "����� �������� �� ������";
}

void update(vector<Driver> drivers) {
	ofstream fin;
	fin.open(Dfile.c_str(), ios_base::in | ios_base::trunc);
	for (Driver driver : drivers) {
		fin << driver.to_string() << endl;
	}
	fin.close();
}

void addtofile(string username, string stazh, string number, string car, string phonenum) {
	if (driver.empty()) getData(driver);
	Driver* us = new Driver(username, stazh, number, car, phonenum);
	cout << "\n";
	driver.push_back(*us);
	update(driver);
}

string delfromfile(vector<Driver> driver, string userName) {
	if (car.empty()) getData(car);
	if (driver.empty()) getData(driver);
	for (int i = 0; i < driver.size(); i++) {
		Driver us = { driver[i] };
		string userString = us.to_string();
		if (userString.find(userName) != string::npos) {
			driver.erase(driver.begin() + i);
			vector<Driver>(driver).swap(driver);
			update(driver);
			return "�������� ������";
		}
	}
	return "�������� �� ������";
}

void getData(vector<Car>& car) {
	ifstream read;
	read.open(Cfile);
	car.clear();
	if (read.is_open()) {
		while (!read.eof()) {
			string mark, model, num, color, year, mileage, hp, consum;
			string str;
			getline(read, mark);
			if (read.eof()) break;
			if (!mark.size()) break;
			getline(read, model);
			getline(read, num);
			getline(read, color);
			getline(read, year);
			getline(read, mileage);
			getline(read, hp);
			getline(read, consum);
			Car* bk = new Car{ mark, model, num, color, year, mileage, hp, consum };
			car.push_back(*bk);
		}
	}
	read.close();
}

string infoSet(vector<Car>& car, string mark, string infonew, int choose) {
	if (car.empty()) getData(car);
	for (int i = 0; i < car.size(); i++) {
		Car bk = { car[i] };
		string carString = bk.to_string();
		if (carString.find(mark) != string::npos) {
			switch (choose) {
			case (1): bk.setmark(infonew);
				car[i] = bk;
				break;
			case (2): bk.setmodel(infonew);
				car[i] = bk;
				break;
			case (3): bk.setnum(infonew);
				car[i] = bk;
				break;
			case (4): bk.setcolor(infonew);
				car[i] = bk;
				break;
			case (5): bk.setyear(infonew);
				car[i] = bk;
				break;
			case (6): bk.setmileage(infonew);
				car[i] = bk;
				break;
			case (7): bk.sethp(infonew);
				car[i] = bk;
				break;
			case (8): bk.setconsum(infonew);
				car[i] = bk;
				break;
			}
			update(car);
			return "�������������� ���� ��������";
		}
	}
	return "����� ���������� �� ������";
}

void update(vector<Car> car) {
	ofstream fin;
	fin.open(Cfile.c_str(), ios_base::in | ios_base::trunc);
	for (Car car : car) {
		fin << car.to_string() << endl;
	}
	fin.close();
}

void addtofile(string mark, string model, string num, string color, string year, string mileage, string hp, string consum) {
	if (car.empty()) getData(car);
	Car* bk = new Car{ mark, model, num, color, year, mileage, hp, consum };
	car.push_back(*bk);
	update(car);
}

string delfromfile(vector<Car> car, string mark) {
	if (car.empty()) getData(car);
	for (int i = 0; i < car.size(); i++) {
		Car bk = car[i];
		string carString = bk.to_string();
		if (carString.find(mark) != string::npos) {
			car.erase(car.begin() + i);
			vector<Car>(car).swap(car);
			update(car);
			return "���� ������";
		}
	}
	return "���������� �� ������";
}

void getData(vector<Orders>& orders) {
	ifstream read;
	read.open(Ofile);
	orders.clear();
	if (read.is_open()) {
		while (!read.eof()) {
			string cFIO, time, from, to, driver, price, avto;
			getline(read, cFIO);
			if (read.eof()) break;
			if (!cFIO.size()) break;
			getline(read, time);
			getline(read, from);
			getline(read, to);
			getline(read, driver);
			getline(read, price);
			getline(read, avto);
			Orders* bk = new Orders{ cFIO, time, from, to, driver, price, avto };
			orders.push_back(*bk);
		}
	}
	read.close();
}

void addtofile(string cFIO, string time, string to, string from, string driver, string price, string avto) {
	if (orders.empty()) getData(orders);
	Orders* bk = new Orders{ cFIO, time, to, from, driver, price, avto };
	orders.push_back(*bk);
	update(orders);
}

void update(vector<Orders> orders) {
	ofstream fin;
	fin.open(Ofile.c_str(), ios_base::in | ios_base::trunc);
	for (Orders orders : orders) {
		fin << orders.to_string() << endl;
	}
	fin.close();
}

string delfromfile(vector<Orders> orders, string time) {
	if (orders.empty()) getData(orders);;
	for (int i = 0; i < orders.size(); i++) {
		Orders us = { orders[i] };
		string userString = us.to_string();
		if (userString.find(time) != string::npos) {
			orders.erase(orders.begin() + i);
			vector<Orders>(orders).swap(orders);
			update(orders);
			return "����� ������";
		}
	}
	return "����� �� ������";
}

string infoSet(vector<Orders>& order, string time, string infonew, int choose) {
	if (orders.empty()) getData(orders);
	for (int i = 0; i < orders.size(); i++) {
		Orders bk = { orders[i] };
		string orderString = bk.to_string();
		if (orderString.find(time) != string::npos) {
			switch (choose) {
			case (1): bk.setcFIO(infonew);
				orders[i] = bk;
				break;
			case (2): bk.settime(infonew);
				orders[i] = bk;
				break;
			case (3): bk.setfrom(infonew);
				orders[i] = bk;
				break;
			case (4): bk.setto(infonew);
				orders[i] = bk;
				break;
			case (5): bk.setdriver(infonew);
				orders[i] = bk;
				break;
			case (6): bk.setprice(infonew);
				orders[i] = bk;
				break;
			case (7): bk.sethp(infonew);
				orders[i] = bk;
				break;
			}
			update(car);
			return "������ ������ ��������";
		}
	}
	return "����� �� ������";
}

void alldriver() {
	getData(driver);
	if (!driver.empty()) {
		for (unsigned i = 0; i < driver.size(); i++) {
			Driver us{ driver[i] };
			us.outData();
			cout << endl;
		}
	}
	else cout << "������ ��������� ����";
	cout << endl;
}

int changedriver(int choose) {
	string userName, infonew;
	while (true) {
		cout << "\t\t��� �� ������ ��������?" << endl;
		cout << "\t\t|1. ���               |\n";
		cout << "\t\t|2. ����              |\n";
		cout << "\t\t|3. �����             |\n";
		cout << "\t\t|4. ������ ��������   |\n";
		cout << "\t\t|5. ����� ��������    |\n";
		cout << "\t\t|0. �����             |\n ";
		cin >> choose;
		if (0 <= choose <= 5) break;
	}
	if (choose == 0) return 0;
	cin.ignore(2, '\n');
	cout << "������� ��� �������� ��� ���������: "; getline(cin, userName);
	cout << "������� ����� ������ "; getline(cin, infonew);
	cout << endl << infoSet(driver, userName, infonew, choose) << endl;
	return 0;
}

void adddriver() {
	cin.ignore(2, '\n');
	string username, stazh, number, car, phonenum;
	cout << "������� ��� ��������: "; getline(cin, username);
	cout << "������� ���� �������� "; getline(cin, stazh);
	cout << "������� ����� ������ ��������: "; getline(cin, number);
	cout << "������� ������ ��������: "; getline(cin, car);
	cout << "������� ���������� ����� ��������: "; getline(cin, phonenum);
	addtofile(username, stazh, number, car, phonenum);
}

void delDriver() {
	string userName;
	cin.ignore(2, '\n');
	cout << "������� ��� ��������, ����� ������� ��� �� ���� - "; getline(cin, userName);
	cout << delfromfile(driver, userName) << endl;
}

void allCars() {
	getData(car);
	if (!car.empty()) {
		for (unsigned i = 0; i < car.size(); i++) {
			Car bk{ car[i] };
			bk.outData();
			cout << endl;
		}
	}
	else {
		cout << "������ ����������� �����������" << endl;
	}
	cout << endl;
}

int changecar(int choose) {
	string mark;
	while (true) {
		cout << "\t\t ����� �������� ��������?" << endl;
		cout << "\t\t|1. ����� ����          |" << endl;
		cout << "\t\t|2. ������ ����         |" << endl;
		cout << "\t\t|3. ����� ����          |" << endl;
		cout << "\t\t|4. ���� ����           |" << endl;
		cout << "\t\t|5. ��� ����            |" << endl;
		cout << "\t\t|6. ������ ����         |" << endl;
		cout << "\t\t|7. �� ����             |" << endl;
		cout << "\t\t|8. ������ ����         |" << endl;
		cout << "\t\t|0. �����               |" << endl;
		cin >> choose;
		if (0 <= choose <= 8) break;
	}
	if (choose == 0) return 0;
	cin.ignore(2, '\n');
	cout << "������� ����� ����" << endl;
	getline(cin, mark);
	if (choose != 0) {
		string infonew;
		cout << "������� ������, ������� ���������� �������� - ";
		cin >> infonew;
		cout << endl << infoSet(car, mark, infonew, choose) << endl;
	}
	return 0;
}

void addCar() {
	cin.ignore(2, '\n');
	string mark, model, num, color, year, mileage, hp, consum;
	cout << "������� ����� ����: "; getline(cin, mark);
	cout << "������� ������ ����: "; getline(cin, model);
	cout << "������� ����� ����: "; getline(cin, num);
	cout << "������� ���� ����: "; getline(cin, color);
	cout << "������� ��� ����: "; getline(cin, year);
	cout << "������� ������ ����: "; getline(cin, mileage);
	cout << "������� �� ����: "; getline(cin, hp);
	cout << "������� ������ ����: "; getline(cin, consum);
	addtofile(mark, model, num, color, year, mileage, hp, consum);
}

void delCar() {
	cin.ignore(2, '\n');
	string mark;
	cout << "������� ����� ����: "; getline(cin, mark);
	cout << delfromfile(car, mark) << endl;
}

void allOrders() {
	getData(orders);
	if (!orders.empty()) {
		for (unsigned i = 0; i < orders.size(); i++) {
			Orders bk{ orders[i] };
			bk.outData();
			cout << endl;
		}
	}
	else {
		cout << "������ ������� ����" << endl;
	}
	cout << endl;
}

int addOrder() {
	cin.ignore(2, '\n');
	string cFIO, time, to, from, drivern, price, avto;
	cout << "������� ��� �������: "; getline(cin, cFIO);
	cout << "������� ����� ������ (�� � ��): "; getline(cin, time);
	cout << "������� ����� ��������: "; getline(cin, to);
	cout << "������� ����� ����������: "; getline(cin, from);
	cout << "������� ��� ��������" << endl;
	cout << "������ ��������� �����: " << endl;

	getData(driver);
	cout << "*____________" << endl;
	if (!driver.empty()) {
		for (unsigned i = 0; i < driver.size(); i++) {
			Driver us{ driver[i] };
			cout << "| " << us.getUserName() << endl;
		}
	}
	cout << "*------------" << endl;
	getline(cin, drivern);
	int check = 0;
	for (unsigned i = 0; i < driver.size(); i++) {
		Driver us{ driver[i] };
		if (drivern == us.getUserName()) check = 1;
	}
	if (check == 0) {
		cout << "�� ����� ��� �������� ����������. ����� �������� �������� ��������������� ������� ���� |��������|" << endl;
		return 0;
	}
	cout << "������� ���� ������: "; getline(cin, price);
	for (unsigned i = 0; i < driver.size(); i++) {
		Driver us{ driver[i] };
		if (us.getUserName() == drivern) {
			avto = us.getCar();
			break;
		}
	}
	addtofile(cFIO, time, to, from, drivern, price, avto);
	return 0;
}

void delOrder() {
	cin.ignore(2, '\n');
	string time;
	cout << "������� ����� ������: "; getline(cin, time);
	cout << delfromfile(orders, time) << endl;
}

int changeOrder(int choose) {
	string time;
	while (true) {
		cout << "\t\t ����� �������� ��������?" << endl;
		cout << "\t\t|1. ��� �������         |" << endl;
		cout << "\t\t|2. ����� ������        |" << endl;
		cout << "\t\t|3. ����� ��������      |" << endl;
		cout << "\t\t|4. ����� ����������    |" << endl;
		cout << "\t\t|5. ��������            |" << endl;
		cout << "\t\t|6. ����                |" << endl;
		cout << "\t\t|7. ����������          |" << endl;
		cout << "\t\t|0. �����               |" << endl;
		cin >> choose;
		if (0 <= choose <= 7) break;
	}
	if (choose == 0) return 0;
	cin.ignore(2, '\n');
	cout << "������� ����� ������" << endl;
	getline(cin, time);
	if (choose != 0) {
		string infonew;
		cout << "������� ������, ������� ���������� �������� - ";
		cin >> infonew;
		cout << endl << infoSet(orders, time, infonew, choose) << endl;
	}
	return 0;
}