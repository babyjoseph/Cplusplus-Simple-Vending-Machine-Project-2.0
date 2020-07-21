#include "adminAccess.h"


  std::string UserData::GetName(){return _name;}
  std::string UserData::GetPass(){return _pass;}
  void UserData::SetName(std::string name){_name = name;}
  void UserData::SetPass(std::string pass){_pass = pass;}

extern std::vector<Product>myProduct;

namespace{
  std::vector<UserData>myUser;
  std::string name, pass;
  enum AdminMenu{
    Pause,
    Login,
    SignUp,
    Exit
  };
  enum MenuAdmin{
    Stand,
    Add,
    Fill,
    Remove,
    Sort,
    CloseMe
  };
  MenuAdmin adminMe = Stand;
  AdminMenu myAdmin = Pause;
  std::string userInput;
  bool name_exists = false,pass_exists = false, granted = false;
  unsigned account = 0;
}

bool loginUser(){
  system("clear");
  myUser.clear();
  std::ifstream adminUser;
  adminUser.open("myuser.txt");
  if(adminUser.is_open()){
    while(adminUser.peek()!=std::fstream::traits_type::eof()){
      UserData temp;
      getline(adminUser, name);
      getline(adminUser, pass);
      temp.SetName(name);
      temp.SetPass(pass);
      myUser.push_back(temp);
    }
  }
  else{
    std::cout << "Error Occured!" << std::endl;
  }
  adminUser.close();
  std::string temp_name;
  std::cout << "Username: ";
  getline(std::cin, temp_name);
  for(unsigned int i = 0; i < myUser.size(); i++){
    if(temp_name == myUser[i].GetName()){
      name_exists = true;
      account = i;
      break;
    }
  }
  if(!name_exists){
    std::cout << "Unknown Username!" << std::endl;
    std::cin.get();
    return false;
  }
  else{
    std::string temp_pass;
    std::cout << "Password: ";
    getline(std::cin, temp_pass);
    if(temp_pass == myUser[account].GetPass()){
      pass_exists = true;
    }
    if(!pass_exists){
      name_exists = false;
      std::cout << "Wrong Password" << std:: endl;
      std::cin.get();
      return false;
    }
    else{
      return true;
    }
  }
}

void signUser(){
  myUser.clear();
  UserData temp;
  std::cout << "Enter Username: ";
  getline(std::cin, name);
  std::cout << "Enter Password: ";
  getline(std::cin, pass);
  temp.SetName(name);
  temp.SetPass(pass);
  myUser.push_back(temp);
  std::ofstream myAdmin;
  myAdmin.open("myuser.txt",std::ios::app);
  if(myAdmin.is_open()){
    for(unsigned int i = 0; i < myUser.size();i++){
      myAdmin << myUser[i].GetName() << std::endl;
      myAdmin << myUser[i].GetPass() << std::endl;
    }
  }
  else {
    std::cout << "Unable to open file!" << std::endl;
  }
  myAdmin.close();
}

void rootMenu(){
  while(true){
    system("clear");
    switch(adminMe){
      case Stand:
        std::cout << "[add] a product" <<std::endl;
        std::cout << "[fill] a product" << std::endl;
        std::cout << "[remove] a product" << std::endl;
        std::cout << "[sort] product/s" << std::endl;
        std::cout << "[exit]" << std::endl;
        std::cout << "Input: ";
        getline(std::cin, userInput);
        if(userInput == "add"){
          adminMe = Add;
        }
        else if(userInput == "fill"){
          adminMe = Fill;
        }
        else if (userInput == "remove"){
          adminMe = Remove;
        }
        else if (userInput == "exit"){
          adminMe = CloseMe;
        }
        else if (userInput == "sort"){
          adminMe = Sort;
        }
        else {
          std::cout << "Unknown Input!" << std::endl;
          adminMe = Stand;
        }
        break;
      case Add:
        system("clear");
        AddMenu();
        adminMe = Stand;
        break;
      case Fill:
        system("clear");
        fillMenu();
        adminMe = Stand;
        break;
      case Remove:
        removeMenu();
        adminMe = Stand;
        break;
      case Sort:
        system("clear");
        sortingMenu();
        adminMe = Stand;
        break;
      case CloseMe:
        adminMe = Stand;
        break;
    }
    if(adminMe == CloseMe){
      break;
    }
  }
}

void MenuAdmin(){
  while(true){
    system("clear");
    switch(myAdmin){
      case Pause:
        std::cout << "[login]" << std::endl;
        std::cout << "[signup]" << std::endl;
        std::cout << "[exit]" << std::endl;
        std::cout << "Input: ";
        std::cin >> userInput;
        std::cin.ignore();
        if(userInput == "login"){
          myAdmin = Login;
        }
        else if(userInput == "signup"){
          myAdmin = SignUp;
        }
        else if(userInput == "exit"){
          myAdmin = Exit;
        }
        else {
          std::cout << "Unknown Input!" << std::endl;
          myAdmin = Pause;
        }
        break;
      case Login:
        granted = loginUser();
        if(granted){
        rootMenu();
        name_exists = false;
        pass_exists = false;
        granted = false;
        }
        myAdmin = Pause;
        break;
      case SignUp:
        signUser();
        myAdmin = Pause;
        break;
      case Exit:
        myAdmin = Pause;
        break;
    }
    if(myAdmin == Exit){
      break;
    }
  }
}
