#ifndef ADMIN_ACCESS_H
#define ADMIN_ACCESS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "addProduct.h"
#include "savingTo.h"
#include "removeProduct.h"
#include "dataProduct.h"
#include "sortingProduct.h"
#include "readTo.h"
#include "fillMe.h"

class UserData{
  std::string _name,_pass;
public:
  std::string GetName();
  std::string GetPass();
  void SetName(std::string name);
  void SetPass(std::string pass);
};

void MenuAdmin();

#endif
