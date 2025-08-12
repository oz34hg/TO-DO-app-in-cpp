#include "utils.h"
#include "restore.h"
#include "store.h"
#include <fstream>
#include <string>
#include <iostream>



namespace utils {
  void delete_task(int num) {
    std::ifstream in("task.txt");
    std::ofstream out("temp.txt");
    std::string line;
    int count = 1;
    bool found = false;

    while (std::getline(in, line)) {
        if (line.find(std::to_string(num) + " :") != 0) {
            size_t pos = line.find(':');
            out << count++ << " :" << line.substr(pos + 1) << '\n';
        } else {
            found = true;
        }
    }

    in.close();
    out.close();
    std::remove("task.txt");
    std::rename("temp.txt", "task.txt");

    std::cout << (found ? "Task deleted.\n" : "Task not found.\n");
}
 


    bool menu_choice_executing(int user_menu_choice){
      std::string task;
      int task_number_delete;
      switch (user_menu_choice) {
        case 0:
          std::cout<<"Exiting....\n";
            return false;
        case 1:
          restore::load_todo();
          break;
        case 2:
          std::cout<<"\n\nWhat is the number of the task that you want to delete"<<std::endl;
          std::cin>>task_number_delete;
          utils::delete_task(task_number_delete);
          break;
        case 3:
          std::cout<<"\n\nWrite the task that you want to add below"<<std::endl;
          std::cin.ignore();
          std::getline(std::cin, task);
          store::add_task(task);
          break;
        default:
          std::cout<<"\033[31mChoose one of the available answers\033[0m"<<std::endl;
          break;
          
      }
      std::cout<<std::endl;
      return true;

    }

    
    void logo(std::string filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;  
    }

    file.close();
}


  int menu(){
  int user_menu_choice;

  std::cout<<"\033[1m\n\n======MENU======\n\n\033[0m"<<std::endl;
  std::cout<<"\033[32m======1. LOAD TO-DO======\033[0m"<<std::endl;
  std::cout<<"\033[32m======2. DELETE TASK======\033[0m"<<std::endl;
  std::cout<<"\033[32m======3. ADD NEW TASK======\033[0m"<<std::endl;
  std::cout<<"\033[32m======0. CLOSE TODO APP======\033[0m"<<std::endl;
  std::cout<<"\033[33m------choose your option------\033[0m\n\033[36mchoice->\033[0m";
  if(!(std::cin>>user_menu_choice)){
    std::cout<<"\033[31mERROR *only numbers accepted in the menu*\n\033[0m";
  }

  return user_menu_choice;
  }


}

