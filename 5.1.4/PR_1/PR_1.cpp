
#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder
{
private:
	string name; // создание локальных переменных {
	double price;
	int itemNumber; // }
public:
	void set_name(string name); 
	void set_price(double price);
	void set_itemNumber(int itemNumb); 
	string get_name(); // Методы доступа {
	double get_price();
	int get_itemsNumber();
	double get_total_price();
	void print(); // }
	ShopItemOrder(string name, double price, int itemNumber)
	{
		this->name = name;
		this->set_price(price);
		this->set_itemNumber(itemNumber);
	}
};
void ShopItemOrder::set_name(string name) // Присвоение имени
{
	this->name = name;
}
void ShopItemOrder::set_price(double price) // Присвоение цены
{
	if (price > 0)
		this->price = price;
	else
		this->price = 1;
}
void ShopItemOrder::set_itemNumber(int itemNumb) // Присвоение количества товара
{
	if (itemNumb >= 1)
		this->itemNumber = itemNumb;
	else
		this->itemNumber = 1;
}
string ShopItemOrder::get_name() // Вывод имени
{
	return this->name;
}
double ShopItemOrder::get_price() // Вывод цены
{
	return this->price;
}
int ShopItemOrder::get_itemsNumber() // Вывод количества товара
{
	return this->itemNumber;
}
double ShopItemOrder::get_total_price() // Вывод суммы чека (Цена товара * Количество товара)
{
	double totalPrice = 0;
	totalPrice = this->price * this->itemNumber;
	return totalPrice;
}
void ShopItemOrder::print() // Печать полной информации чека (Товар, цена, количество)
{
	cout << "Item name: " << this->name << "\nItem price: " << this->price << "\nNumber of items: " << this->itemNumber << "\n";
}
int main()
{
	ShopItemOrder order("potato", 1.2, 22); 
	cout << order.get_name() << endl;
	cout << order.get_price() << endl;
	cout << order.get_itemsNumber() << endl;
	cout << order.get_total_price() << endl;
	order.print();

	return 0;
}

