#include <iostream>
#include <string>
#include "addProduct.h"
#include "adminAccess.h"
#include "customerAccess.h"
namespace {
  enum MenuState{
    MainMenu,
    Admin,
    Customer,
    Exit
  };
  MenuState myMain = MainMenu;
  std::string userInput;
}

int main(){
  while(true){
    system("clear");
    switch(myMain){
      case MainMenu:
        std::cout << "[admin]" << std::endl;
        std::cout << "[customer]" << std::endl;
        std::cout << "[exit]" << std::endl;
        std::cout << "Input: ";
        getline(std::cin, userInput);
        if(userInput == "admin"){
          myMain = Admin;
        }
        else if(userInput == "customer"){
          myMain = Customer;
        }
        else if (userInput == "exit"){
          myMain = Exit;
        }
        else {
          std::cout << "Invalid Input!" << std::endl;
          myMain = MainMenu;
        }
        break;
      case Admin:
        MenuAdmin();
        myMain = MainMenu;
        break;
      case Customer:
        buyMenu();
        myMain = MainMenu;
        break;
      case Exit:
        break;
    }
    if(myMain == Exit){
      break;
    }
  }


  return 0;
}
