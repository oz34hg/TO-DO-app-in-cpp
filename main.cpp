#include <iostream>
#include <fstream>
#include <string>
#include "utils/utils.h"





int main(){
  utils::logo("ascii.txt");

  bool running = true;
  
  while(running){
  int user_menu_choice = utils::menu();
  running = utils::menu_choice_executing(user_menu_choice);
  }

  return 0;
}
