#include <iostream>
template<class T>
class IObject {
public:
	virtual ~IObject() = default;
	virtual void swap(T&) = 0;
	virtual T& assign(const T&) = 0;
	virtual T& copy()const = 0;
	virtual int cmp(const T&)const = 0;
};
template<class T>
class TObject : public IObject<T> {
public:
	virtual ~TObject() = default;
	bool operator==(const T& other) { return this->cmp(other) == 0; }
	bool operator!=(const T& other) { return this->cmp(other) != 0; }
	bool operator>(const T& other) { return this->cmp(other) > 0; }
	bool operator<(const T& other) { return this->cmp(other) < 0; }
	bool operator>=(const T& other) { return this->cmp(other) >= 0; }
	bool operator<=(const T& other) { return this->cmp(other) <= 0; }
};
class TInOut {
public:
	virtual void output(std::ostream& out) const = 0;
	virtual void input(std::istream& in) = 0;
	virtual void output() const = 0;
	virtual void input() = 0;
};
class date : public TObject<date>, public TInOut {
public:
	date() {
		day = 0;
		month = 0;
		year = 0;
	}
	date(int _day, int _month, int _year)
		: day(_day), month(_month), year(_year)
	{}
	date(const date& a) : day(a.day), month(a.month), year(a.year) {}
	virtual ~date() = default;
	date& operator = (date& a) {
		if (this != &a) {
			date tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(date& other) {
		std::swap(day, other.day);
		std::swap(month, other.month);
		std::swap(year, other.year);
	}

	date& assign(const date& other) {
		day = other.day;
		month = other.month;
		year = other.year;
		return *this;
	}

	date& copy()const {
		date* tmp = nullptr;;
		tmp->assign(*this);
		return *tmp;
	}

	int cmp(const date& other)const {
		if (year != other.year) {
			return year - other.year;
		}
		if (month != other.month) {
			return month - other.month;
		}
		return day - other.day;
	}
	void output(std::ostream& out)const {
		out << "Date of deal\n" << day << "." << month << "." << year;
	}
	void input(std::istream& in) {
		std::cout << "Date of deal\n";
		std::cout << "Input day: ";
		in >> day;
		std::cout << "Input month: ";
		in >> month;
		std::cout << "Input year: ";
		in >> year;
	}
	void output() const {
		output(std::cout);
	}
	void input() {
		input(std::cin);
	}
	int get_day() const { return day; }
	int get_month() const { return month; }
	int get_year() const { return year; }
	friend std::ostream& operator<<(std::ostream& out, const date& date);
	friend std::istream& operator>>(std::istream& in, date& date);
private:
	int day;
	int month;
	int year;
};
std::ostream& operator<<(std::ostream& out, const date& date) {
	date.output(out);
	return out;
}
std::istream& operator>>(std::istream& in, date& a) {
	a.input(in);
	return in;
}
class VIN {
	std::string vin;
public:
	VIN() {
		vin = "no vin";
	}
	VIN(std::string _vin){}
	VIN(const VIN& a):vin(a.vin){}
	VIN& operator =(VIN& a) {
		if (this != &a) {
			VIN tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(VIN & a) {
		std::swap(this->vin, a.vin);
	}
	friend std::ostream& operator << (std::ostream& out, const VIN& a);
	friend std::istream& operator>>(std::istream& input, VIN& a);
	friend bool operator ==(const VIN& a, const VIN& b) {
		return (a.vin == b.vin);
	}
};
std::ostream& operator << (std::ostream& out, const VIN& a) {
	out << a.vin;
	return out;
}
std::istream& operator>>(std::istream& input, VIN& a) {
	std::cout << "Input VIN: ";
	input >> a.vin;
	return input;
}
class FIO {
	std::string name, surname, lastname;
public:
	FIO() {
		name = "no name";
		surname = "no surname";
		lastname = "no lastname";
	}
	FIO(std::string _name, std::string _surname,
		std::string _lastname) :name(_name), surname(_surname), lastname(_lastname) {}
	FIO(const FIO& a) :name(a.name), surname(a.surname), lastname(a.lastname) {}
	FIO& operator =(FIO& a) {
		if (this != &a) {
			FIO tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(FIO& a) {
		std::swap(this->name, a.name);
		std::swap(this->surname, a.surname);
		std::swap(this->lastname, a.lastname);
	}
	friend std::ostream& operator << (std::ostream& out, const FIO& a);
	friend std::istream& operator>>(std::istream& in, FIO& a);
	friend bool operator ==(const FIO& a, const FIO& b) {
		return (a.name == b.name) && (a.surname == b.surname) && (a.lastname == b.lastname);
	}
};
std::ostream& operator << (std::ostream& out, const FIO& a) {
	out << a.name << " " << a.surname << " " << a.lastname;
	return out;
}
std::istream& operator>>(std::istream& input, FIO& a) {
	std::cout << "Input name: ";
	input >> a.name;
	std::cout << "Input surname: ";
	input >> a.surname;
	std::cout << "Input lastname: ";
	input >> a.lastname;
	return input;
}

class Buyer {
	FIO buyer;
	std::string phone;
	std::string adress;

public:
	Buyer() {
		phone = "no phone";
		adress = "no adress";
	}Buyer(FIO _buyer, std::string _p_n, std::string _adress)
	{}
	Buyer(const Buyer&a): buyer(a.buyer), phone(a.phone), adress(a.adress)
	{}
	Buyer& operator =(Buyer& a) {
		if (this != &a) {
			Buyer tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(Buyer& a) {
		buyer.swap(a.buyer);
		std::swap(this->adress, a.adress);
		std::swap(this->phone, a.phone);
	}
	friend std::ostream& operator << (std::ostream& out, const Buyer& a);
	friend std::istream& operator>>(std::istream& in, Buyer& a);
	friend bool operator ==(const Buyer& a, const Buyer& b) {
		return   (a.buyer == b.buyer)&&(a.adress == b.adress)&&(a.phone==b.phone);
	}
	FIO get_FIO() {
		return buyer;
	}
};
std::ostream& operator << (std::ostream& out, const Buyer& a) {
	out << "\nFIO Buyer:\n" << a.buyer << "\nphone: " << a.phone << "\nadress: " << a.adress ;
	return out;
}
std::istream& operator>>(std::istream& input, Buyer& a) {
	std::cout << "Input FIO Buyer:\n";
	input >> a.buyer;
	std::cout << "Input phone: ";
	input >> a.phone;
	std::cout << "Input adresss: ";
	input >> a.adress;
	
	return input;
}
class Diller {
	FIO dil;
	std::string name_campony;
	std::string phone;
	std::string adress;
public:
	Diller() {
		name_campony = "no campony";
		phone="no phone";
		adress = "no adress";
		
	}Diller(FIO _dil, std::string _campony, std::string _p_n, std::string _adress): dil(_dil),name_campony(_campony), phone(_p_n), 
		adress(_adress)
	{}
	Diller(const Diller& a) : dil(a.dil), name_campony(a.name_campony), phone(a.phone), 
		adress(a.adress)
	{}
	Diller& operator =(Diller& a) {
		if (this != &a) {
			Diller tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(Diller& a) {
		dil.swap(a.dil);
		std::swap(this->adress, a.adress);
		std::swap(this->phone, a.phone);
		std::swap(this->name_campony, a.name_campony);
	}
	friend std::ostream& operator << (std::ostream& out, const Diller& a);
	friend std::istream& operator>>(std::istream& in, Diller& a);
	friend bool operator ==(const Diller& a, const Diller& b) {
		return (a.name_campony == b.name_campony) && (a.dil == b.dil);
	}
	FIO get_FIO() {
		return dil;
	}
};
std::ostream& operator << (std::ostream& out, const Diller& a) {
	out << "\nFIO Diller:\n" << a.dil << "\nname of campony : " << a.name_campony << "\nadress : " << a.adress  << "\nphone number : " << a.phone;
	return out;
}
std::istream& operator>>(std::istream& input, Diller& a) {
	std::cout << "Input FIO diller:\n";
	input >> a.dil;
	std::cout << "Input name of caampony: ";
	input >> a.name_campony;
	std::cout << "Input phone number: ";
	input >> a.phone;
	std::cout << "Input adress: ";
	input >> a.adress;
	return input;
}

enum Complectation {Comfort, Prestige, Luxe, GT_line, GT_line_plus };
enum Tupe_Car {Passenger, Off_Road, Bus, Truck };
class Car {
	Tupe_Car Tupe;
	std::string model; //Kia Cerato
	std::string color;
	VIN car_vin; //XXXXX00XXX0000000
	std::string engine_num;//G4NA
	Complectation commlectation;
	int year;
	float cost;
	Diller diller;
	Buyer buyer;
	date dkpdate;
public:
	Car() {
		Tupe = Passenger;
		model = "no model";
		color = "no color";
		engine_num = "no num";
		commlectation = Comfort;
		year = 0;
		float cost = 0.0;

	}Car(Tupe_Car _Tupe, std::string _model, std::string _color, VIN _VIN, std::string _engine_num, Complectation _complectation, int _year, float _cost, Diller _dil, Buyer _buy, date _dkpdate) :
		Tupe(_Tupe), model(_model), color(_color), car_vin(_VIN), engine_num(_engine_num), commlectation(_complectation), year(_year), cost(_cost), diller(_dil), buyer(_buy), dkpdate(_dkpdate)
	{}
	Car(const Car& a): Tupe(a.Tupe), model(a.model), color(a.color), car_vin(a.car_vin), engine_num(a.engine_num), commlectation(a.commlectation), year(a.year), 
		cost(a.cost), diller(a.diller), buyer(a.buyer),dkpdate(a.dkpdate) {}
	Car& operator = (const Car& a) {
		if (this != &a) {
			Car tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(Car& a) {
		std::swap(this->Tupe, a.Tupe);
		std::swap(this->model, a.model);
		std::swap(this->color, a.color);
		std::swap(this->engine_num, a.engine_num);
		std::swap(this->commlectation, a.commlectation);
		std::swap(this->year, a.year);
		std::swap(this->cost, a.cost);
		diller.swap(a.diller);
		buyer.swap(a.buyer);
		dkpdate.swap(a.dkpdate);
		car_vin.swap(a.car_vin);
	}
	
	
	friend std::ostream& operator << (std::ostream& out, const Car&a);
	friend std::istream& operator >>(std::istream& in, Car&a);
	friend bool operator ==(Car& a,  Car& b) {
		return (a.Tupe == b.Tupe) && (a.model == b.model)&& (a.color == b.color) && (a.car_vin == b.car_vin)&& (a.engine_num == b.engine_num) && (a.commlectation == b.commlectation)
			&& (a.year == b.year)&&(a.cost==b.cost) && (a.diller == b.diller) && (a.buyer == b.buyer) && (a.dkpdate == b.dkpdate);
	}
	VIN get_VIN() {
		return car_vin;
	}
};
std::ostream& operator << (std::ostream& output, const Car&a) {
	output << a.diller;
	output << a.buyer;
	output << a.dkpdate;
	if (a.Tupe == Passenger) {
		output << "\nType car - Passenger";
	}else if (a.Tupe == Off_Road) {
		output << "\nType car - Off Road";
	}
	else if (a.Tupe == Bus) {
		output << "\nType car - Bus";
	}
	else if (a.Tupe == Truck) {
		output << "\nType car - Truck";
	}
	output<<"\nModel:" << a.model << "\nColor: " << a.color << "\nVIN: " << a.car_vin << "\nEnginee number: " << a.engine_num;
	if (a.commlectation == Comfort) {
		output << "\nComplectaton - Comfort";
	}
	else if (a.Tupe == Prestige) {
		output << "\nComplectaton - Prestige";
	}
	else if (a.Tupe == Luxe) {
		output << "\nComplectaton - Luxe";
	}
	else if (a.Tupe == GT_line) {
		output << "\nComplectaton - GT Line";
	}
	else if (a.Tupe == GT_line_plus) {
		output << "\nComplectaton - GT Line +";
	}
	
	output<<"\nYear of realise: " << a.year << "\nCost: " << a.cost<<"\n";
	return output;
}
std::istream& operator>>(std::istream& input, Car& a) {
	int choose = 0;
	int choose1 = 0;
	input >> a.diller;
	input >> a.buyer;
	input >> a.dkpdate;
	std::cout << "Input type of car (1)Passenger, (2)Off_Road, (3)Bus, (4)Truck:\n";
	std::cin >> choose;
	if (choose == 1) {
		a.Tupe = Passenger;
	}
	else if (choose == 2) {
		a.Tupe = Off_Road;
	}
	else if (choose == 3) {
		a.Tupe = Bus;
	}
	else if (choose==4) {
		a.Tupe = Truck;
	}
	std::cout << "Input model of car: ";
	input >> a.model;
	std::cout << "Input color of car: ";
	input >> a.color;
	std::cout << "";
	input >> a.car_vin;
	std::cout << "Input engine num: ";
	input >> a.engine_num;
	std::cout << "Input complectation of car (1)Comfort, (2)Prestige, (3)Luxe, (4)GT_line, (5)GT_line_plus): ";
	std::cin >> choose1;
	if (choose1 == 1) {
		a.commlectation = Comfort;
	}
	else if (choose1 == 2) {
		a.commlectation = Prestige;
	}
	else if (choose1 == 3) {
		a.commlectation = Luxe;
	}
	else if (choose1 == 4) {
		a.commlectation = GT_line;
	}
	else if (choose1 == 5) {
		a.commlectation = GT_line_plus;
	}
	std::cout << "Input year of realise car: ";
	input >> a.year;
	std::cout << "Input cost of car: ";
	input >> a.cost;

	return input;
}
class archive {
	int capacity;
	int size;
	Car* list;
public:
	archive() : size(0), capacity(5) {
	list = new Car[capacity];
}
	  archive(int _capacity) :
		  size(0), capacity(_capacity)
	  {
		  list = new Car[capacity];
	  }
	  archive(const archive& a) :
		  size(a.size), capacity(a.capacity), list(a.list)
	  {}
	  ~archive() {
		  delete[] list;
		  list = nullptr;
	  }
	  void add(const Car& a) {
		  if (size >= capacity) {
			  int new_capacity = capacity * 2;
			  Car* new_list = new Car[new_capacity];
			  for (int i = 0; i < capacity; i++) {
				  new_list[i] = list[i];
			  }
			  delete[] list;
			  list = new_list;
			  capacity = new_capacity;
		  }
		  list[size] = a;
		  size++;
	  }
	  void search_dkp(const VIN  &a) {
		  int counter = 0;
		  for (int i = 0; i < size; i++) {
			  if (a == list[i].get_VIN()) {
				  counter++;
			  } 
		  }
		  int* dkp_list = new int[counter];
		  int counter1 = 0;
		  if (counter != 0) {
			  for (int i = 0; i < size; i++) {
				  if (a == list[i].get_VIN()) {
					  dkp_list[counter1] = i;
					  counter1++;
				  }
			  }
		  }
		  for (int i = 0; i < counter1; i++) {
			  std::cout << "\n" << dkp_list[i] + 1 << ") " << list[i];
		  }
	  }
	  void remove(int _count) {
		  int index = _count - 1;
		  if (index > size) {
			  std::cout << "err";
		  }
		  else if (index < 0) {
			  std::cout << "err";
		  }
		  else {
			  for (int i = index; i < size - 1; i++) {
				  list[i] = list[i + 1];
			  }
			  size--;
		  }
	  }
	  void display() {
		  for (int i = 0; i < size; i++) {
			  std::cout << "\n" << i + 1 << ") " << list[i];
		  }
	  }
	  int get_size() {
		  return size;
	  }
	  void change(int _count) {
		  int index = _count - 1;
		  if (index < 0) {
			  std::cout << "err";
		  }
		  else if (index >= size) {
			  std::cout << "err";
		  }
		  else {
			  std::cin >> list[index];
		  }
	  }
};

int main() {
	int choose = 0;
	Car new_car;
	archive baza;
	VIN vin;
	int index = 0;
	while (true) {
		std::cout << "1. Add a new dkp.\n2. Show the list.\n3. Find the dkp\n4. Remove \n5. Change the dkp\n6. Exit\nYour choise:";
		std::cin >> choose;
		switch (choose) {
		case 1:
			
			std::cin >> new_car;
			baza.add(new_car);
			choose = 0;
			break;
		case 2:
			baza.display();
			std::cout << "\n";
			system("pause");
			choose = 0;
			break;
		case 3:
			
			std::cin >> vin;
			baza.search_dkp(vin);
			choose = 0;
			system("pause");
			break;
		case 4:
			std::cout << "Input index: ";
			std::cin >> index;
			baza.remove(index);
			choose = 0;
			break;
		case 5:
			std::cout << "Input index: ";
			std::cin >> index;
			baza.change(index);
			choose = 0;
			break;
		case 6:
			return 0;
		}
		system("cls");
	}
	std::cout << "Bye-bye";
	return 0;
}
