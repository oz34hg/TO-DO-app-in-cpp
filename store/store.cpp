#include "store.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>


namespace store {
  


void add_task(std::string task) {
    std::string filename = "task.txt";

    if (!std::filesystem::exists(filename)) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file.close();
            std::cout << "tasks file created successfully" << std::endl;
        } else {
            std::cerr << "failed to create the file" << std::endl;
        }
    }

    //  Read the last line to get the last task number
    std::ifstream read_file(filename);
    std::string line, last_line;
    while (std::getline(read_file, line)) {
        if (!line.empty()) last_line = line;
    }
    read_file.close();

    int task_number = 1;  // default if file is empty
    if (!last_line.empty()) {
        size_t colon = last_line.find(':');
        if (colon != std::string::npos) {
            task_number = std::stoi(last_line.substr(0, colon)) + 1;
        }
    }

    //  Append new task
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << task_number << " : " << task << std::endl;
        file.close();
        std::cout << "task successfully added to the list" << std::endl;
    } else {
        std::cerr << "failed to open the file" << std::endl;
    }
}

}
