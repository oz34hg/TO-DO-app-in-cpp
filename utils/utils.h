#ifndef UTILS_H
#define UTILS_H

#include <string>


namespace utils{
  int menu();
  void logo(std::string filename);
  bool menu_choice_executing(int user_menu_choice);  
  void delete_task(std::string task);
}


#endif
