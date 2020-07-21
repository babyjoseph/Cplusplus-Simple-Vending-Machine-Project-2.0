#include "removeProduct.h"

extern std::vector<Product>myProduct;

void removeMe(){
  unsigned selection;
  bool exists = false;
  myProduct.clear();
  productReading();
  DisplayProduct();
  std::cout << "Enter the number of the Product you want to remove: ";
  std::cin >> selection;
  std::cin.ignore();
  for(int i = 0;i<myProduct.size();i++){
    if(i == (selection - 1)){
      myProduct.erase(myProduct.begin()+i);
      exists = true;
      break;
    }
  }
  if(!exists){
    std::cout << "Invalid selection" << std::endl;
  }
  productUpdating(myProduct);
}
namespace{
  enum Decision{
    Pause,
    Yes,
    No
  };
  Decision myState = Pause;
  char ans;
}


void removeMenu(){
  removeMe();
  while(true){
    switch(myState){
      case Pause:
        std::cout << "Remove a product?[y/n] ";
        std::cin >> ans;
        std::cin.ignore();
        if(ans == 'y'){
          myState = Yes;
        }
        else if(ans == 'n'){
          myState = No;
        }
        else{
          std::cout << "Unknown Input!" << std::endl;
          myState = Pause;
        }
        break;
      case Yes:
        system("clear");
        removeMe();
        myState = Pause;
        break;
      case No:
        myState = Pause;
        break;
    }
    if(myState == No){
      break;
    }
  }
}
