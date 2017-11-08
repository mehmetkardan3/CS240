#ifndef CART_ITEM_
#define CART_ITEM_
#include <iostream>
#include <string>
using namespace std;

class CartItem{
	private:
		string itemName;
		double price;
		int quantity;
	
	public:
		
		CartItem();
		CartItem(string itname,double itprice,int itquantity);
		
		string getName();
		double getPrice();
		int getQuantity();
		double getTotal();
		
		friend std::ostream& operator<< (std::ostream & out, const CartItem & f);
};
#endif
