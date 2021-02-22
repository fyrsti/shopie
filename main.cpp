#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>


using namespace std;
class Product;
void show_product_list();
bool _validate_product_number(int pn);
int _get_product_number();
bool _check_account(int pcode);
string _process_transaction(int pcode);
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

int money{ 100 };
vector<Product*> productCatalog;


class Product
{
private:
	int price_;
	string name_;
public:
	Product(string name, int price) : price_(price), name_(name)
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

	void set_price(int value)
	{
		price_ = value;
	}
};


void buy_product()
{
	show_product_list();
	int choice = _get_product_number();
	if (_check_account(choice))
	{
		cout << "Well, you've bought a " << _process_transaction(choice);
		cout << ".\nNow, you account is " << money << "$\n";
	}
	else
	{
		cout << "You haven't enough money!" << endl;
	}
}


string _process_transaction(int pcode)
{
	string temp = productCatalog.at(pcode)->get_name();
	money -= productCatalog.at(pcode)->get_price();
	delete productCatalog.at(pcode);
	productCatalog.erase((productCatalog.begin() + pcode));
	return temp;
}


bool _check_account(int pcode)
{
	return (productCatalog.at(pcode)->get_price() <= money ? true : false);
}


int _get_product_number()
{
	int pnumber{0};
	while(!_validate_product_number(pnumber))
		input("Enter the product code: ", pnumber);	
	return pnumber - 1;
}

bool _validate_product_number(int pn)
{
	return (pn <= productCatalog.size() && pn >= 1 ? true : false);
}


void show_product_list()
{
	if (productCatalog.empty())
	{
		cout << "There aren't any products in our shop, but you can take sell some ones for us.\n";
		return;
	}
	for (int i = 0; i < productCatalog.size(); i++)
	{
		cout << i + 1 << ":\t" << productCatalog.at(i)->get_name() << "\t- " << productCatalog.at(i)->get_price() << "$\n";
	}
	cout << "\nYour account: " << money << "$\n";
}


void sell_product()
{
	cout << "Not implemented" << endl;
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
			buy_product();
			break;
		case SELL:
			sell_product();
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
