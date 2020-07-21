#ifndef DATA_PRODUCT_H
#define DATA_PRODUCT_H

#include <string>
#include <iostream>
#include <vector>

class Product{
  std::string _name;
  double _price;
  int _id,_stock;
public:
  std::string GetName();
  int GetId();
  double GetPrice();
  int GetStock();
  void SetName(std::string name);
  void SetId(int id);
  void SetPrice(double price);
  void SetStock(int stock);
};

void DisplayProduct();

#endif
