#include "addProduct.h"

namespace{
  std::string name;
  double price;
  int id,stock;
  enum DecisionState{
    Pause,
    Yes,
    No
  };
  DecisionState myDecision = Pause;
  char ans;
  bool grant1 = true,grant2 = false;
}
std::vector<Product>myProduct;

Product addToProduct(){
  Product temp;
  productReading();
  std::cout << "\n=============== Product ===============" << std::endl;
  std::cout << "Enter Product Name: ";
  getline(std::cin, name);
  temp.SetName(name);
  std::cout << "Enter Product ID: ";
  std::cin >> id;
  std::cin.ignore();
  temp.SetId(id);
  std::cout << "Enter Product Price: ";
  std::cin >> price;
  std::cin.ignore();
  temp.SetPrice(price);
  std::cout << "Enter the number of stocks available: ";
  std::cin >> stock;
  std::cin.ignore();
  temp.SetStock(stock);
  myProduct.clear();
  return temp;
}
bool checkProduct(Product product){
  for(unsigned i = 0; i < myProduct.size();i++){
    if(product.GetName().compare(myProduct[i].GetName())==0){
      grant1 = false;
      return false;
    }
    if(product.GetId() == myProduct[i].GetId()){
      grant1 = false;
      return false;
    }
  }
  if(grant1){
    return true;
  }
}
void Adding(){
  myProduct.clear();
  productReading();
  DisplayProduct();
  myProduct.clear();
  Product product = addToProduct();
  grant2 = checkProduct(product);
  if(grant2){
    myProduct.push_back(product);
  }
  else{
    std::cout << "Product already exist." << std::endl;
  }
}

void AddMenu(){
  Adding();
  productSaving(myProduct);
  while(true){
    switch(myDecision){
      case Pause:
        std::cout << "\nEnter another?[y/n] ";
        std::cin >> ans;
        std::cin.ignore();
        if(ans == 'y'|| ans == 'Y'){
          myDecision = Yes;
        }
        else if(ans == 'n' || ans == 'N'){
          myDecision = No;
        }
        else {
          std::cout << "\nUnknown Input!" << std::endl;
          myDecision = Pause;
        }
        break;
      case Yes:
        Adding();
        productSaving(myProduct);
        myDecision = Pause;
        break;
      case No:
        myDecision = Pause;
        break;
    }
    if(myDecision == No){
      break;
    }
  }
}
