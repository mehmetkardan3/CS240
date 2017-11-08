#include<iostream>
#include "ShoppingCart.cpp"
#include "CartItem.cpp"
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

string fileName();
//input: none
//output: returns the name of the file that user wants to open...

void textOrder(ShoppingCart& o,int& num);
//input: object refferance
//output: takes items from the txt file and create CartItem objects for them in ShoppingCart...

int menu();
//input: none
//output: returns the selection...

void itemRemove(ShoppingCart& o,int& num);
//input: object refferance
//output: ask user the location and remove the item at that loc...

void manuelAdd(ShoppingCart& o,int& num);
//input: object refferance
//output: ask user the name of the item,price of item and number of item and creates new object...

void itemCost(ShoppingCart& o,int num);
//input: object refferance
//output: ask user the location of the item and prints its cost...

void complete(ShoppingCart& o);
//input: object refferance
//output: prints the total cost and ends program...


int main(){
	int select;
	int numItem=0;
	ShoppingCart shop;
	textOrder(shop,numItem);
	shop.displayCart();
	
	select=menu();
	while(select!=4){
		if(select==1){
			itemRemove(shop,numItem);
		}
		else if(select==2){
			manuelAdd(shop,numItem);
		}
		else if(select==3){
			itemCost(shop,numItem);
		}
		select=menu();
	}
	complete(shop);
}

string fileName(){
	string selection;
	cout << "Enter the name of the file: ";
	cin >> selection;
	return selection;
}

int menu(){
	int selection;
	cout << "Please select:\n1.Remove\n2.Add Item\n3.Cost of Specific Order\n4.Complete the Purchase" << endl;
	cin >> selection;
	if(selection<=0||selection>4){
		menu();
	}
	else{
		return selection;
	}
}

void textOrder(ShoppingCart& o,int& num){
	fstream file(fileName().c_str());
	string lines;
	string name;
	double price;
	int quantity;
	
	
	if(!file.is_open()){
		cout << "File could not be opened!! Try again!!" << endl;
		textOrder(o,num);
	}
	else{
		while(getline(file,lines)){
			stringstream ss(lines);
			ss >> name >> price >> quantity;
			CartItem newObj(name,price,quantity);
			o.addItem(newObj);
			num++;
		}
	}
	
}

void itemRemove(ShoppingCart& o,int& num){
	int loc;
	cout << "Enter the location of the item to remove: ";
	cin >> loc;
	if(loc<=0||loc>num){
		cout << "That item does not exist!!";
	}
	else{
		o.removeItem(loc);
		num--;
	}
}

void manuelAdd(ShoppingCart& o,int& num){
	string name;
	double price;
	int quantity;
	cout << "Enter the name of the item: ";
	cin >> name;
	cout << "Price of the item: ";
	cin >> price;
	if(price<0){
		cout << "Price can not be negative!!";
		manuelAdd(o,num);
	}
	else{
		cout << "How many of this item: ";
		cin >> quantity;
		CartItem newObj(name,price,quantity);
		o.addItem(newObj);
		num++;
	}
}

void itemCost(ShoppingCart& o,int num){
	int loc;
	cout << "Enter the location of the item: ";
	cin >> loc;
	if(loc<=0||loc>num){
		cout << "That item does not exist!!";
	}
	else{
		cout << "Cost of this item is: " << o.getCost(loc) << "$" << endl;
	}
}

void complete(ShoppingCart& o){
	o.displayCart();
	cout << "Total cost is: " << o.getTotalCost() << "$" << endl;
}
