#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>


using namespace std;
void buy_product();
void sell_product();
void earn_money();
void try_to_steal();


enum ACTIONS
{
	BUY = 1,
	SELL = 2,
	EARN = 3,
	STEAL = 4
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

template <typename T>
void input(string text, T& destination)
{
	cout << text;
	cin>> destination;
}


void controller()
{
	int a{0};
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
			cout << "Incorrect action" << endl;
			break;
		}
	}
}


int main()
{
	cout << "Hello" << endl; 

	controller();
	return 0;
}
