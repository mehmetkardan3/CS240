#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart(){
	total=0;
	itemUsed=0;
}

void ShoppingCart::addItem(CartItem it){
	cart.append(it);
	itemUsed++;
}

void ShoppingCart::displayCart(){
	int i;
	for(i=1;i<=itemUsed;i++){
		cout << i << ". " << cart.retrieve(i) << endl;
	}
}

void ShoppingCart::removeItem(int pos){
	cart.remove(pos);
	itemUsed--;
}
double ShoppingCart::getCost(int pos){
	return cart.retrieve(pos).getTotal();
}
double ShoppingCart::getTotalCost(){
	int i;
	for(i=1;i<=itemUsed;i++){
		total+=cart.retrieve(i).getTotal();
	}
	return total;
}
