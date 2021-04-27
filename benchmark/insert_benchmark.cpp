//
// Created by Семен Соколов on 25.04.2021.
//
#include <fstream>
#include <iostream>
#include <string>       // string
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>
#include <sstream>

// подключаем вашу структуру данных
#include "AVLTree.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR_INSERT};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

int main() {

  // Tip 1: входные аргументы позволяют более гибко контролировать параметры вашей программы
  const auto path = string(kDatasetPath);
  const auto output_path = string(kProjectPath) + "/benchmark/result/insertResults.csv";

  auto output_file1 = ofstream(output_path);
  output_file1.close();
  // работа с набором данных
  vector<string> files = {"100", "500", "1000", "5000", "10000", "50000", "100000", "500000", "1000000", "5000000"};
  AVLTree<int> avlTree;

  for (const string& file : files) {  // Проходим по всем 10 .csv файлам
    for (int i = 1; i < 11; i++) {    // Запускаем замерку времени 10 раз
      auto input_file = ifstream(path + "/" + file + ".csv");
      auto time_diff_insert = chrono::nanoseconds::zero();
      cout << (path + "/" + file) << endl;

      input_file = ifstream(path + "/" + file + ".csv");

      //         здесь находится участок кода, время которого необходимо замерить
      if (input_file) {
        int line_number = 0;
        for (string line; getline(input_file, line, ','); /* ... */) {
          auto ss = stringstream(line);
          const auto time_point_before_insert = chrono::high_resolution_clock::now();
          avlTree.insert(stoi(line));
          const auto time_point_after_insert = chrono::high_resolution_clock::now();
          line_number++;
          time_diff_insert += time_point_after_insert - time_point_before_insert;
        }
      }

      const auto time_elapsed_ns_insert = chrono::duration_cast<chrono::nanoseconds>(time_diff_insert).count();
      cout << time_elapsed_ns_insert << endl;

      avlTree.clear();
      input_file.close();

      //Открываем файл для записи и вносим полученые данные
      auto output_file = fstream(output_path, ios::app);
      output_file << file << "," << i << "," << time_elapsed_ns_insert << endl;
      output_file.close();
    }
  }
  return 0;
}
