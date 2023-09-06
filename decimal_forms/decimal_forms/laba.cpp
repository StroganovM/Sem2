#include<iostream>
enum type_of_pres { normal, kid };
template<class T>
class IObject {
public:
	virtual ~IObject() = default;
	virtual void swap(T&) = 0;
	virtual T& assign(const T&) = 0;
	virtual T& copy()const = 0;
	virtual int cmp(const T&)const= 0;
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
	virtual void output(std::ostream& out) const= 0;
	virtual void input(std::istream& in) = 0;
	virtual void output() const= 0;
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
	date(const date& a): day(a.day), month(a.month), year(a.year){}
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
		out << day << "." <<month << "." << year;
	}
	void input(std::istream& in) {
		std::cout << "Input day: ";
		in >> day;
		std::cout << "Input month: ";
		in >> month;
		std::cout << "Input year: ";
		in >> year;
	}
	void output() const{
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
class FIO {
	std::string name, surname, lastname;
public:
	FIO(){
		name = "no name";
		surname = "no surname";
		lastname = "no lastname";
	}
	FIO(std::string _name, std::string _surname,
		std::string _lastname):name(_name), surname(_surname), lastname(_lastname){}
	FIO(const FIO& a):name(a.name), surname(a.surname),lastname(a.lastname) {}
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
class drug {
	int single_dosage;
	int intakes_per_day;
	std::string name_of_drug;
public:
	drug() {
		name_of_drug = "no name";
		single_dosage = 0;
		intakes_per_day = 0;
	}
	drug(std::string _name_of_drug, int _s_d, int _i_p_d) :name_of_drug(_name_of_drug), single_dosage(_s_d),
		intakes_per_day(_i_p_d) {}
	drug(const drug& a) :name_of_drug(a.name_of_drug), intakes_per_day(a.intakes_per_day),
		single_dosage(a.single_dosage) {}
	drug& operator =(drug& a) {
		if (this != &a) {
			drug tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(drug& a) {
		std::swap(this->name_of_drug, a.name_of_drug);
		std::swap(this->single_dosage, a.single_dosage);
		std::swap(this->intakes_per_day, a.intakes_per_day);
	}
	friend std::ostream& operator << (std::ostream& out, const drug& a);
	friend std::istream& operator>>(std::istream& in, drug& a);
	friend bool operator ==(const drug& a, const drug& b) {
		return (a.name_of_drug == b.name_of_drug) &&
			(a.single_dosage == b.single_dosage) && (a.intakes_per_day == b.intakes_per_day);
	}
};
std::ostream& operator << (std::ostream& out, const drug& a) {
	out << "name of drug: "<<a.name_of_drug << "\nsingle dosage: " << a.single_dosage
		<< "\nintakes per day: "<< a.intakes_per_day;
	return out;
}
std::istream& operator>>(std::istream& input, drug& a) {
	std::cout << "Input name of drug: ";
	input >> a.name_of_drug;
	std::cout << "Input single dosage: ";
	input >> a.single_dosage;
	std::cout << "Input intakes per day: ";
	input >> a.intakes_per_day;
	return input;
}
class doctor {
	FIO doc;//фио доктора
	std::string adress, name_of_hospital, phone_num;//адресс больницы, название, номер
public:
	doctor() {
		adress = "no adress";
		name_of_hospital = "no name of hospital";
		phone_num = "no phone number";
	}doctor(FIO _doc, std::string _adr, std::string _n_o_h, std::string _p_n): doc(_doc),
	name_of_hospital(_n_o_h),phone_num(_p_n)
	{}
	doctor(const doctor& a): doc(a.doc), name_of_hospital(a.name_of_hospital),
	adress(a.adress), phone_num(a.phone_num){}
	doctor& operator =(doctor& a) {
		if (this != &a) {
			doctor tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(doctor& a) {
		doc.swap(a.doc);
		std::swap(this->adress, a.adress);
		std::swap(this->phone_num, a.phone_num);
		std::swap(this->name_of_hospital, a.name_of_hospital);
	}
	friend std::ostream& operator << (std::ostream& out, const doctor& a);
	friend std::istream& operator>>(std::istream& in, doctor& a);
	friend bool operator ==(const doctor& a, const doctor& b) {
		return (a.name_of_hospital == b.name_of_hospital) && (a.doc == b.doc);
	}
	FIO get_FIO() {
		return doc;
	}
};
std::ostream& operator << (std::ostream& out, const doctor& a) {
	out << "FIO:\n" << a.doc << "\nname of hospital : " << a.name_of_hospital << "\nadress : " << a.adress<<"\nphone number : "<<a.phone_num;
	return out;
}
std::istream& operator>>(std::istream& input, doctor& a) {
	std::cout << "Input FIO doctor:\n";
	input >> a.doc;
	std::cout << "Input name of hospital: ";
	input >> a.name_of_hospital;
	std::cout << "Input adress: ";
	input >> a.adress;
	std::cout << "Input phone number: ";
	input >> a.phone_num;
	return input;
}
class recept {
private:
	float cost;//цена
	type_of_pres type;//тип рецепта
	date expir_date;//дата окончания
	date iss_date;//дата начала
	FIO patient;
	drug p_drug;
	doctor dr;
public:
	recept() {
		type = normal;
		cost = 0;
	}
	recept(float _cost, type_of_pres _type, date _ex_date, date _is_date, FIO _patient, drug _p_d, doctor _dr):
	cost(_cost), type(_type), expir_date(_ex_date), iss_date(_is_date), patient(_patient),p_drug(_p_d),dr(_dr)
	{}
	recept(const recept& a): cost(a.cost), type(a.type), expir_date(a.expir_date),iss_date(a.iss_date),
	patient(a.patient),p_drug(a.p_drug), dr(a.dr){}
	recept& operator =(const recept& a) {
		if (this != &a) {
			recept tmp(a);
			this->swap(tmp);
		}
		return *this;
	}
	void swap(recept& a) {
		dr.swap(a.dr);
		expir_date.swap(a.expir_date);
		iss_date.swap(a.iss_date);
		patient.swap(a.patient);
		p_drug.swap(a.p_drug);
		std::swap(this->cost, a.cost);
		std::swap(this->type, a.type);
	}
	friend bool operator ==( recept& a, recept& b) {
		return (a.dr == b.dr) && (a.p_drug == b.p_drug)&&(a.iss_date == b.iss_date)&&(a.expir_date == b.expir_date)&&
			(a.cost == b.cost)&&(a.type==b.type)&&(a.patient == b.patient);
	}
	friend std::istream& operator>>(std::istream& input, recept& a);
	friend std::ostream& operator<<(std::ostream& output, const recept& a);
	FIO get_doc_FIO() {
		return dr.get_FIO();
	}
};
std::istream& operator>>(std::istream& input, recept& a) {
	int choose = 0;
	std::cout << "Input cost: ";
	input >> a.cost;
	std::cout << "Input type of prescription(1-normal, 2-kid): ";
	std::cin >> choose;
	if (choose == 1) {
		a.type = normal;
	}
	else if (choose == 2) {
		a.type = kid;
	}
	std::cout << "Input issuance date\n";
	input >> a.iss_date;
	std::cout << "Input expiration date\n";
	input >> a.expir_date;
	std::cout << "Input FIO patient\n";
	input >> a.patient;
	std:: cout << "Input drug\n";
	input >> a.p_drug;
	std::cout << "Input doctor\n";
	input >> a.dr;
	system("cls");
	return input;
}
std::ostream& operator<<(std::ostream& output, const recept& a) {
	output << "cost of drug: "<<a.cost << "\n";
	if (a.type == normal) {
		output << "type: normal\n";
	}
	else if (a.type == kid) {
		output << "type: kid\n";
	}
	output<<"expiration date: " << a.expir_date << "\nissuance date : " << a.iss_date<<
		"\npatient: "<<a.patient<<"\ndrug:\n "<<a.p_drug<<"\ndoctor:\n"<<a.dr;
	return output;
}
class archive {
	int capacity;
	int size;
	recept* list;
public:
	archive() : size(0), capacity(5) {
		list = new recept[capacity];
	}
	archive(int _capacity) :
		size(0), capacity(_capacity)
	{
		list = new recept[capacity];
	}
	archive(const archive& a) :
		size(a.size), capacity(a.capacity), list(a.list)
	{}
	~archive() {
		delete[] list;
		list = nullptr;
	}
	void add(const recept& a) {
		if (size >= capacity) {
			int new_capacity = capacity * 2;
			recept* new_list = new recept[new_capacity];
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
	void search_recept(const FIO& a) {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (a == list[i].get_doc_FIO()) {
				counter++;
			}
		}
		int* doc_list = new int[counter];	
		int counter1 = 0;
		if (counter != 0) {
			for (int i = 0; i < size; i++) {
				if (a == list[i].get_doc_FIO()) {
					doc_list[counter1] = i;
					counter1++;
				}
			}
			for (int i = 0; i < counter1;i++) {
				std::cout <<"\n" << doc_list[i] + 1 << ") " << list[i];
			}
			
		}
		else {
			std::cout << "not found";
		}
	}
	void remove(int _count) {
		int index = _count - 1;
		if (index > size) {
			std::cout << "daleko";
		}
		else if (index < 0) {
			std::cout << "nedobral";
		}
		else {
			for (int i = index; i < size-1; i++) {
				list[i] = list[i+1];
			}
			size--;
		}
	}
	void display() {
		for (int i = 0; i < size;i++) {
			std::cout <<"\n" << i+1<<") " << list[i];
		}
	}
	int get_size() {
		return size;
	}
	void change(int _count) {
		int index = _count - 1;
		if (index < 1) {
			std::cout << "malo";
		}
		else if (index >= size) {
			std::cout << "mnogo";
		}
		else {
			std::cin >> list[index];
		}
	}
};
// изменить элемент по индексу 
int main() {
	int choose = 0;
	recept new_rec;
	archive baza;
	FIO doctor;
	int index = 0;
	while (true) {
		std::cout << "1. Add a new recept.\n2. Show the list.\n3. Find the recept\n4. Remove \n5. Change the recept\n6. Exit\nYour choise:";
		std::cin >> choose;
		switch (choose) {
		case 1:
			//новый рецепт
			std::cin >> new_rec;
			baza.add(new_rec);
			choose = 0;
			break;
		case 2:
			//показать лист
			baza.display();
			std::cout << "\n";
			system("pause");
			choose = 0;
			break;
		case 3:
			//найти рецепт
			std::cin >> doctor;
			baza.search_recept(doctor);
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
