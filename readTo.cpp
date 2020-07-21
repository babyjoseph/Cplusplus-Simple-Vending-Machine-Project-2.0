#include "readTo.h"

extern std::vector<Product>myProduct;
void productReading(){
  std::ifstream readMe;
  readMe.open("myProducts.txt");
  if(readMe.is_open()){
    while(readMe.peek()!=std::fstream::traits_type::eof()){
      Product myTemp;
      std::string name;
      double price;
      int id,stock;
      getline(readMe, name);
      myTemp.SetName(name);
      readMe >> id;
      readMe.ignore();
      myTemp.SetId(id);
      readMe >> price;
      readMe.ignore();
      myTemp.SetPrice(price);
      readMe >> stock;
      readMe.ignore();
      myTemp.SetStock(stock);
      myProduct.push_back(myTemp);
    }
  }
  else{
    std::cout << "Unable to open file!" << std::endl;
  }
  readMe.close();
}
