#include "savingTo.h"

void productSaving(std::vector<Product>temp){
  std::ofstream saveMe;
  saveMe.open("myProducts.txt",std::ios::app);
  if(saveMe.is_open()){
    for(unsigned i = 0; i < temp.size();i++){
      saveMe << temp[i].GetName() << std::endl;
      saveMe << temp[i].GetId() << std::endl;
      saveMe << temp[i].GetPrice() << std::endl;
      saveMe << temp[i].GetStock() << std::endl;
    }
  }
  else{
    std::cout << "Error Occured!" << std::endl;
  }
  saveMe.close();
}

void productUpdating(std::vector<Product>temp){
  std::ofstream updateMe;
  updateMe.open("myProducts.txt",std::ios::trunc);
  if(updateMe.is_open()){
    for(unsigned i = 0; i < temp.size(); i++){
      updateMe << temp[i].GetName() << std::endl;
      updateMe << temp[i].GetId() << std::endl;
      updateMe << temp[i].GetPrice() << std::endl;
      updateMe << temp[i].GetStock() << std::endl;
    }
  }
  else{
    std::cout << "Error Occured!" << std::endl;
  }
  updateMe.close();
}
