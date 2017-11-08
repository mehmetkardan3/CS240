#include "CartItem.h"
#include <iostream>
#include <string>
using namespace std;

CartItem::CartItem(){
	itemName="";
	price=0;
	quantity=0;
}

CartItem::CartItem(string itname,double itprice,int itquantity){
	itemName=itname;
	price=itprice;
	quantity=itquantity;
}

string CartItem::getName(){
	return itemName;
}

double CartItem::getPrice(){
	return price;
}

int CartItem::getQuantity(){
	return quantity;
}

double CartItem::getTotal(){
	return price*quantity;
}

std::ostream & operator<< (std::ostream & out, const CartItem & f) {
		out << f.itemName << ": " << f.price << "$ " << "<" << f.quantity << ">";
		return out;
	} 
