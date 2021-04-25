//
// Created by Семен Соколов on 25.04.2021.
//
#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>
#include <sstream>

// подключаем вашу структуру данных
#include "AVLTree.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR_FIND};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {
  // Tip 1: входные аргументы позволяют более гибко контролировать параметры вашей программы
  const auto path = string(kDatasetPath);
  const auto output_path = string(kProjectPath) + "/benchmark/result/findMaxAndMinResults.csv";

  auto output_file1 = ofstream(output_path);
  output_file1.close();
  // работа с набором данных
  vector<string> files = {"100", "500", "1000", "5000", "10000", "50000", "100000", "500000", "1000000", "5000000"};
  AVLTree<int> avlTree;

  for (string file : files) {       // Проходим по всем 10 .csv файлам
    for (int i = 1; i < 11; i++) {  // Запускаем замерку времени 10 раз
      string line = "1";
      auto input_file = ifstream(path + "/" + file + ".csv");
      auto time_diff_find_max_min = chrono::nanoseconds::zero();
      cout << (path + "/" + file) << endl;

      if (input_file) {
        int line_number = 0;
        for (string line; getline(input_file, line, ','); /* ... */) {
          auto ss = stringstream(line);  // оборачиваем строку в объект "поток"
          avlTree.insert(stoi(line));
          line_number++;
        }
      }
      input_file.close();

      //         здесь находится участок кода, время которого необходимо замерить

      const auto time_point_before_find_max_min = chrono::steady_clock::now();
      avlTree.find_max();
      avlTree.find_min();
      const auto time_point_after_find_max_min = chrono::steady_clock::now();
      time_diff_find_max_min += time_point_after_find_max_min - time_point_before_find_max_min;

      const auto time_elapsed_ns_erase = chrono::duration_cast<chrono::nanoseconds>(time_diff_find_max_min).count();
      cout << time_elapsed_ns_erase << endl;

      avlTree.clear();

      //Открываем файл для записи и вносим полученые данные
      auto output_file = fstream(output_path, ios::app);
      output_file << file << "," << i << "," << time_elapsed_ns_erase << endl;
      output_file.close();
    }
  }
  return 0;
}