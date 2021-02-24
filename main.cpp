#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <chrono>


using namespace std;
class Product;

void show_information(bool hide = false);
bool _validate_number_in_range(int pn, int max);
void _preprocess_numbers(vector<int>& t, int& c, int& d);
int _get_answer();
void visualize_math_problems(int delta, int omega, vector<int> base);
int _get_product_number(vector<Product*> catlg);
bool _check_account(int pcode);
string _process_transaction(int pcode, vector<Product*>& from, vector<Product*>& to);
bool _antirepeat(vector<int> v, int target);
void buy_product();
void sell_product();
void earn_salary();
void try_to_steal();

template <typename T>
void input(string text, T& destination);


enum ACTIONS
{
	QUIT,
	BUY,
	SELL,
	EARN,
	STEAL
};

int money{ 0 };
vector<Product*> productCatalog;
vector<Product*> inventory;


class Product
{
private:
	const int price_;
	int current_price;
	string name_;
public:
	Product(string name, int price) : price_(price), name_(name), current_price(price)
	{}

	Product(string name) : Product(name, 0)
	{}

	string get_name()
	{
		return name_;
	}

	int get_price()
	{
		return price_;
	}

	int get_current_price()
	{
		return current_price;
	}

	bool compare_prices()
	{
		return (current_price == price_ ? true : false);
	}

	void set_price(int value)
	{
		current_price = value;
	}
};

// Разграничить перевод денег и перевод продуктов
string _process_transaction(int pcode, vector<Product*>& from, vector<Product*>& to)
{
	// Перемещает объект класса Product из одного вектора в другой
	to.push_back(from.at(pcode));
	int temp = to.back()->get_current_price();
	if (to.back()->compare_prices())
	{
		money -= temp;
		to.back()->set_price(temp - temp / 4);
	}
	else
	{
		money += temp;
		to.back()->set_price(to.back()->get_price());
	}
	from.erase((from.begin() + pcode));
	return to.back()->get_name();
}


bool _check_account(int pcode)
{
	return (productCatalog.at(pcode)->get_current_price() <= money ? true : false);
}


int _get_product_number(vector<Product*> catlg)
{
	int pnumber{-1};
	input("Enter the product code: ", pnumber);
	if (_validate_number_in_range(pnumber, catlg.size()))
		return pnumber - 1;
	else
		return -1;
}

bool _validate_number_in_range(int pn, int max)
{
	return (pn <= max && pn >= 1 ? true : false);
}


void show_information(bool hide)
{
	cout << "\n----- Shop Catalog -----" << endl;
	for (int i = 0; i < productCatalog.size(); i++)
	{
		cout << i + 1 << ":\t" << productCatalog.at(i)->get_name() << "\t- " << productCatalog.at(i)->get_current_price() << "$\n";
	}

	if (hide)
		return;

	cout << "\n----- Your Inventory -----" << endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << i + 1 << ":\t" << inventory.at(i)->get_name() << "\t- " << inventory.at(i)->get_current_price() << "$ for sell\n";
	}

	cout << "\nYour account: " << money << "$\n";
}


void buy_product()
{
	int choice = _get_product_number(productCatalog);
	if (choice == -1)
		return;
	if (_check_account(choice))
	{
		cout << "Well, you've bought a " << _process_transaction(choice, productCatalog, inventory);
		cout << ".\nNow, you account is " << money << "$\n";
	}
	else
		cout << "You haven't enough money!" << endl;
}


void sell_product()
{
	int choice = _get_product_number(inventory);
	if (choice == -1)
		return;
	cout << "Nice, you've just sold a " << _process_transaction(choice , inventory, productCatalog);
	cout << "\nNow, your acconut is " << money << "$\n";
}


bool solve_math_problem()
{
	vector<int> temp;
	int choice, delta, response{ 0 };
	_preprocess_numbers(temp, choice, delta);
	visualize_math_problems(delta, temp.at(choice) - delta, temp);
	return _get_answer() == choice + 1 ? true : false;
}


int _get_answer()
{
	int response{ 0 };
	while (true)
	{
		input("Choose the correct answer: ", response);
		if (_validate_number_in_range(response, 3))
			return response;
		else
			cout << "This is not a correct answer" << endl;
	}
}


void _preprocess_numbers(vector<int>& t, int& c, int& d)
{
	int iterations{ 0 };
	d = rand() % 20;
	while (true)
	{
		while (iterations < 3)
		{
			int temp = rand() % 30;
			if (_antirepeat(t, temp))
			{
				iterations++;
				t.push_back(temp);
			}
		}
		c = rand() % 3;
		if (d < t.at(c) - 5)
			break;
	}
}


bool _antirepeat(vector<int> v, int target)
{
	for (auto el : v)
	{
		if (el == target)
			return false;
	}
	return true;
}


void visualize_math_problems(int delta, int omega, vector<int> base)
{
	cout << "How much is " << delta << " + " << omega << endl;
	cout << "1: " << base.at(0) << endl;
	cout << "2: " << base.at(1) << endl;
	cout << "3: " << base.at(2) << endl;
}


string construct_word()
{
	string symbols{ "qwertyuiopasdfghjklzxcvbnm1234567890" };
	string result;
	int length = 7 + rand() % 5;
	for (int i = 0; i < length; i++)
	{
		result.push_back(symbols.at(rand() % symbols.size()));
	}
	return result;
}


void timer()
{}


int compare_words(string original, string user)
{
	int correct{ 0 };
	for (int i = 0; i < (original.size() >= user.size() ? user.size() : original.size()); i++)
		if (original[i] == user[i])
			correct++;
	return correct;
}


int repeat_word()
{
	string task = construct_word();
	string response;
	timer();
	input("Repeat that: " + task + "\n:", response);
	int correct = compare_words(task, response);
	cout << "Correct answers " << correct << '/' << task.size() << endl;
	if (correct > 0)
		return 100 * correct / task.size();
	else
		return 0;
}


void earn_salary()
{
	int salary{ 0 };
	if (solve_math_problem())
	{
		salary += 50;
		cout << "Right!" << endl;
	}
	else
		cout << "Incorrect!" << endl;
	salary += repeat_word();
	cout << "\nYour salary is " << salary << endl;
	money += salary;
}


void try_to_steal()
{
	cout << "Damn, you're going to do something mad, aren't you?" << endl;
	int max{ 0 };
	int choice = _get_product_number(productCatalog);
	if (choice == -1)
		return;
	
	// 1
	for (auto el : productCatalog)
	{
		if (el->get_current_price() > max)
			max = el->get_current_price();
	}

	// 2
	int chance = 100 - (productCatalog.at(choice)->get_current_price() / max * 100);
	if (chance < 10)
		chance = 10;
	else if (chance > 90)
		chance = 90;

	// 3
	bool result = rand() % 100 + 1 > chance ? false : true;

	// 4
	if (result)
	{
		_process_transaction(choice, productCatalog, inventory);
		cout << "Wow, we did it!" << endl;
	}
	else
	{
		cout << "COPS!" << endl;
	}
}


void _add_products()
{
	productCatalog.push_back(new Product("Tomato", 30));
	productCatalog.push_back(new Product("Apple", 20));
	productCatalog.push_back(new Product("Banana", 45));
	productCatalog.push_back(new Product("Nut", 15));
	productCatalog.push_back(new Product("Carrot", 25));
}


void _delete_products()
{
	for (auto product : productCatalog)
	{
		if (product != nullptr)
			delete product;
	}

	for (auto product : inventory)
	{
		if (product != nullptr)
			delete product;
	}
}


template <typename T>
void input(string text, T& destination)
{
	cout << text;
	cin>> destination;
}


void controller()
{
	int a{-1};
	while (true)
	{
		cout << "\n1 - Buy\n2 - Sell\n3 - Earn\n4 - Steal\n";
		input("Choose the action: ", a);
		switch (a)
		{
		case BUY:
			if (productCatalog.empty())
				cout << "There aren't any products in our shop, but you can sell some ones for us.\n";
			else
			{
				show_information();
				buy_product();	
			}
			break;
		case SELL:
			if (inventory.empty())
				cout << "There aren't any products in your inventory, but you can buy some.\n";
			else
			{
				show_information();
				sell_product();
			}
			break;
		case EARN:
			earn_salary();
			break;
		case STEAL:
			if (productCatalog.empty())
				cout << "There aren't any products in our shop to steal.\n";
			else
			{
				show_information(true);
				try_to_steal();
			}
			break;
		default:
			cout << "Don't waste my time! Get out!" << endl;
			return;
		}
	}
}


int main()
{
	srand(time(NULL));
	_add_products();
	controller();
	_delete_products();
	return 0;
}
