#include "customerAccess.h"

extern std::vector<Product>myProduct;

namespace{
  enum Decision{
    Pause,
    Buy,
    Exit
  };
  Decision myState = Pause;
  char ans;
  double money = 0,price = 0,additional = 0;
  unsigned int selection = 0,qty,in_stock;
  bool exists,stockStat;
}

void buying(){
  exists = false;
  if(money == 0){
    std::cout << "Enter how much money you have: ";
    std::cin >> money;
    std::cin.ignore();
  }
  myProduct.clear();
  productReading();
  productUpdating(myProduct);
  DisplayProduct();
  std::cout << "\n\nYour Balance: " << money << std::endl;
  std::cout << "Enter the number of your choice: ";
  std::cin >> selection;
  std::cin.ignore();
  for(unsigned i = 0; i < myProduct.size(); i++){
    if(i == (selection -1)){
      price = myProduct[i].GetPrice();
      std::cout << "How many " << myProduct[i].GetName() << " will you buy? ";
      std::cin >> qty;
      std::cin.ignore();
      price *= qty;
      exists = true;
    }
    if(i == (selection -1)){
      in_stock = myProduct[i].GetStock();
      if(in_stock < qty){
        stockStat = false;
      }
      else {
        stockStat = true;
      }
    }
  }
  if(!exists){
    std::cout << "You have entered a wrong number!" << std::endl;
  }
  else if(!stockStat){
    std::cout << "There is not enough stock for that product!" <<std::endl;
  }
  else{
    if (money >= price){
      money -= price;
      in_stock -= qty;
      for(unsigned i = 0; i < myProduct.size();i++){
        if(i == (selection - 1)){
          myProduct[i].SetStock(in_stock);
        }
      }
      std::cout << "Your remaining balance: " << money << std::endl;
    }
    else{
      std::cout << "You have insufficient money!" << std::endl;
      std::cout << "How much will you add? ";
      std::cin >> additional;
      std::cin.ignore();
      money += additional;
      std::cout << "Your new balance is: " << money << std::endl;
    }
  }
}

void buyMenu(){
  buying();
  productUpdating(myProduct);
  while(true){
    switch(myState){
      case Pause:
        std::cout << "Do you want to buy?[y/n] ";
        std::cin >> ans;
        std::cin.ignore();
        if(ans == 'y'|| ans == 'Y'){
          myState = Buy;
        }
        else if (ans == 'n' || ans == 'N'){
          myState = Exit;
        }
        else {
          std::cout << "Unknown Input!" << std::endl;
          myState = Pause;
        }
        break;
      case Buy:
        buying();
        productUpdating(myProduct);
        myState = Pause;
        break;
      case Exit:
        myState = Pause;
        break;
    }
    if(myState == Exit){
      break;
    }
  }
}
