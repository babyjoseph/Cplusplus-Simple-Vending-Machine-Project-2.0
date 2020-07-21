#include "dataProduct.h"

std::string Product::GetName(){return _name;}
int Product::GetId() {return _id;}
double Product::GetPrice() {return _price;}
int Product::GetStock(){return _stock;}
void Product::SetName(std::string name){_name = name;}
void Product::SetId(int id){_id = id;}
void Product::SetPrice(double price){_price = price;}
void Product::SetStock(int stock){_stock = stock;}

extern std::vector<Product>myProduct;
void DisplayProduct(){
  unsigned index = 0;
  for(auto i = myProduct.begin(); i != myProduct.end(); i++){
    std::cout << "\n==================== Product " << index + 1 << " ====================\n";
    std::cout << "Product Name: " << (*i).GetName() << std::endl;
    std::cout << "Product Id: " << (*i).GetId() << std::endl;
    std::cout << "Product Price: " << (*i).GetPrice() << std::endl;
    std::cout << "Number of Stock/s: " << (*i).GetStock() << std::endl;
    index++;
  }
}
