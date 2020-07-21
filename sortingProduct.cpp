#include "sortingProduct.h"

extern std::vector<Product>myProduct;
namespace{
  Product temp;
  std::string temp_name;
  double temp_price;
  int temp_id;
  enum sortState{
    Pause,
    Price,
    Id,
    Name,
    Exit
  };
  sortState meState = Pause;
  std::string ans;
}
void sortingPrice(){
  for(unsigned i = 0; i < myProduct.size();i++){
    for(unsigned j = i +1; j < myProduct.size(); j++){
      if(myProduct[i].GetPrice() > myProduct[j].GetPrice()){
        double temp;
        temp = myProduct[j].GetPrice();
        myProduct[j].SetPrice(myProduct[i].GetPrice());
        myProduct[i].SetPrice(temp);

        std::string tempName;
        tempName = myProduct[j].GetName();
        myProduct[j].SetName(myProduct[i].GetName());
        myProduct[i].SetName(tempName);

        int tempId;
        tempId = myProduct[j].GetId();
        myProduct[j].SetId(myProduct[i].GetId());
        myProduct[i].SetId(tempId);
      }
    }
  }
}

void sortingId(){
  for(unsigned i = 0; i < myProduct.size();i++){
    for(unsigned j = i +1; j < myProduct.size(); j++){
      if(myProduct[i].GetId() > myProduct[j].GetId()){
        double temp;
        temp = myProduct[j].GetPrice();
        myProduct[j].SetPrice(myProduct[i].GetPrice());
        myProduct[i].SetPrice(temp);

        std::string tempName;
        tempName = myProduct[j].GetName();
        myProduct[j].SetName(myProduct[i].GetName());
        myProduct[i].SetName(tempName);

        int tempId;
        tempId = myProduct[j].GetId();
        myProduct[j].SetId(myProduct[i].GetId());
        myProduct[i].SetId(tempId);
      }
    }
  }
}

void sortingName(){
  for(unsigned i = 0; i < myProduct.size();i++){
    for(unsigned j = i + 1; j < myProduct.size();j++){
      if(myProduct[i].GetName().compare(myProduct[j].GetName())>0){
        double temp;
        temp = myProduct[j].GetPrice();
        myProduct[j].SetPrice(myProduct[i].GetPrice());
        myProduct[i].SetPrice(temp);

        std::string tempName;
        tempName = myProduct[j].GetName();
        myProduct[j].SetName(myProduct[i].GetName());
        myProduct[i].SetName(tempName);

        int tempId;
        tempId = myProduct[j].GetId();
        myProduct[j].SetId(myProduct[i].GetId());
        myProduct[i].SetId(tempId);
      }
    }
  }
}

void sortingMenu(){
  while(true){
    switch(meState){
      case Pause:
        std::cout << "Sort by [name]" << std::endl;
        std::cout << "Sort by [price]" << std::endl;
        std::cout << "Sort by [id]" << std::endl;
        std::cout << "[exit]" << std::endl;
        std::cout << "Input: ";
        getline(std::cin, ans);
        if(ans == "name"){
          meState = Name;
        }
        else if(ans == "price"){
          meState = Price;
        }
        else if(ans == "id"){
          meState = Id;
        }
        else if(ans == "exit"){
          meState = Exit;
        }
        else{
          std::cout << "Unknown Input!" << std::endl;
          meState = Pause;
        }
        break;
      case Name:
        system("clear");
        myProduct.clear();
        productReading();
        sortingName();
        DisplayProduct();
        productUpdating(myProduct);
        std::cin.get();
        meState = Pause;
        break;
      case Price:
        system("clear");
        myProduct.clear();
        productReading();
        sortingPrice();
        DisplayProduct();
        productUpdating(myProduct);
        std::cin.get();
        meState = Pause;
        break;
      case Id:
        system("clear");
        myProduct.clear();
        productReading();
        sortingId();
        DisplayProduct();
        productUpdating(myProduct);
        std::cin.get();
      case Exit:
        meState = Pause;
        break;
    }
    if(meState == Exit){
      break;
    }
  }
}
