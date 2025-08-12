#include "restore.h"
#include <iostream>
#include <fstream>


namespace restore{

  void load_todo(){
    std::ifstream file("task.txt");
    std::string line;

    while(std::getline(file, line)){
      std::cout<<"\n"<<std::endl;
      std::cout<<line<<std::endl;
    }
    file.close();


  }
  
}
