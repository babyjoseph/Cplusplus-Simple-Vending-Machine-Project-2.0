#include "fillMe.h"
extern std::vector<Product>myProduct;
namespace{
  enum fillState{
    Pause,
    Yes,
    No,
  };
  fillState myMe = Pause;
  char ans;
  bool exist;
  unsigned int selected,qty,stock;
}

void fillProduct(){
  myProduct.clear();
  productReading();
  DisplayProduct();
  std::cout << "\n\nEnter the number of the Product to be filled: ";
  std::cin >> selected;
  std::cin.ignore();
  for(unsigned i = 0; i < myProduct.size();i++){
    if(i == (selected-1)){
      std::cout << "How many " << myProduct[i].GetName() << " will you fill-in? ";
      std::cin >> qty;
      std::cin.ignore();
      stock = myProduct[i].GetStock();
      qty += stock;
      myProduct[i].SetStock(qty);
      exist = true;
      break;
    }
  }
  if(!exist){
    std::cout << "Unknown Selection!" <<std::endl;
  }
}

void fillMenu(){
  fillProduct();
  productUpdating(myProduct);
  while(true){
    switch(myMe){
      case Pause:
        std::cout << "Fill a product again?[y/n] ";
        std::cin >> ans;
        std::cin.ignore();
        if(ans == 'y'){
          myMe = Yes;
        }
        else if (ans == 'n'){
          myMe = No;
        }
        else{
          std::cout << "Unknown Input!" << std::endl;
          myMe = Pause;
        }
        break;
      case Yes:
        system("clear");
        fillProduct();
        productUpdating(myProduct);
        myMe = Pause;
        break;
      case No:
        myMe = Pause;
        break;
    }
    if(myMe == No){
      break;
    }
  }
}
