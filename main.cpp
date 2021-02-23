#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>


using namespace std;
class Product;
void show_information();

bool _validate_product_number(int pn, vector<Product*> catlg);
int _get_product_number(vector<Product*> catlg);
bool _check_account(int pcode);
string _process_transaction(int pcode, vector<Product*>& from, vector<Product*>& to);
void buy_product();
void sell_product();
void earn_money();
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

int money{ 1000 };
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

// Переделать механизм использования брать продукт from и передавать в to
string _process_transaction(int pcode, vector<Product*>& from, vector<Product*>& to)
{
	// Перемещает объект класса Product из одного вектора в другой
	to.push_back(from.at(pcode));
	int temp = to.back()->get_current_price();
	if (to.back()->compare_prices())
	{
		money -= temp;
		to.back()->set_price(temp - temp / 10);
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
	if (_validate_product_number(pnumber, catlg))
		return pnumber - 1;
	else
		return -1;
}

bool _validate_product_number(int pn, vector<Product*> catlg)
{
	return (pn <= catlg.size() && pn >= 1 ? true : false);
}


void show_information()
{
	cout << "\n----- Shop Catalog -----" << endl;
	for (int i = 0; i < productCatalog.size(); i++)
	{
		cout << i + 1 << ":\t" << productCatalog.at(i)->get_name() << "\t- " << productCatalog.at(i)->get_current_price() << "$\n";
	}

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


void earn_money()
{
	cout << "Not implemented" << endl;
}


void try_to_steal()
{
	cout << "Not implemented" << endl;
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
			earn_money();
			break;
		case STEAL:
			try_to_steal();
			break;
		default:
			cout << "Don't waste my time! Get out!" << endl;
			return;
		}
	}
}


int main()
{ 
	_add_products();
	controller();
	_delete_products();
	return 0;
}
