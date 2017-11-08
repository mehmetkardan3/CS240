#ifndef SHOPPIN_CART_
#define SHOPPING_CART_
#include "LinkedList.cpp"
#include "CartItem.h"
class ShoppingCart{
	private:
		LinkedList<CartItem> cart;
		double total;
		int itemUsed;
	
	public:
		ShoppingCart();
		void addItem(CartItem it);
		void displayCart();
		void removeItem(int pos);
		double getCost(int pos);
		double getTotalCost();
		
		
};

#endif
