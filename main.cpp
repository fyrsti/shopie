#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>


using namespace std;
class Product;
void buy_product();
void sell_product();
void earn_money();
void try_to_steal();


enum ACTIONS
{
	QUIT,
	BUY,
	SELL,
	EARN,
	STEAL
};


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
	cout << "Not implemented" << endl;
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
	cout << "1 - Buy\n2 - Sell\n3 - Earn\n4 - Steal\n";
	while (true)
	{
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
	cout << "Hello" << endl; 
	_add_products();
	controller();
	_delete_products();
	return 0;
}
