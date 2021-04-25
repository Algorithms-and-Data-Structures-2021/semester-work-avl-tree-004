#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;

// абсолютный путь до набора данных
static constexpr auto kDatasetPathInsert = string_view{PROJECT_DATASET_DIR_INSERT};
static constexpr auto kDatasetPathFind = string_view{PROJECT_DATASET_DIR_FIND};
static constexpr auto kDatasetPathErase = string_view{PROJECT_DATASET_DIR_ERASE};

int main() {
  const auto pathToFind = string(kDatasetPathFind);
  const auto pathToErase = string(kDatasetPathErase);
  const auto pathToInsert = string(kDatasetPathInsert);
  cout << "Dataset pathToInsert: " << pathToInsert << endl;
  cout << "Dataset pathToFind: " << pathToFind << endl;
  cout << "Dataset pathToErase: " << pathToErase << endl;

  vector<string> output_streams;
  output_streams.emplace_back("/100.csv");
  output_streams.emplace_back("/500.csv");
  output_streams.emplace_back("/1000.csv");
  output_streams.emplace_back("/5000.csv");
  output_streams.emplace_back("/10000.csv");
  output_streams.emplace_back("/50000.csv");
  output_streams.emplace_back("/100000.csv");
  output_streams.emplace_back("/500000.csv");
  output_streams.emplace_back("/1000000.csv");
  output_streams.emplace_back("/5000000.csv");

  vector<int> integers = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000};

  while (!integers.empty()) {
    auto outputStreamForFind = ofstream(pathToFind + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamForErase = ofstream(pathToErase + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamForInsert = ofstream(pathToInsert + output_streams.front(), ios::ios_base::trunc);

    const auto seed = chrono::system_clock::now().time_since_epoch().count();
    auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
    auto dist = uniform_int_distribution(0, 10000000);  // равновероятное распределение генерируемых чисел

    if (outputStreamForFind) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamForFind << dist(engine) << ',';
      }
      outputStreamForFind << dist(engine) << '\n';
    }

    if (outputStreamForErase) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamForErase << dist(engine) << ',';
      }
      outputStreamForErase << dist(engine) << '\n';
    }

    if (outputStreamForInsert) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamForInsert << dist(engine) << ',';
      }
      outputStreamForInsert << dist(engine) << '\n';
    }

    integers.erase(integers.begin());
    output_streams.erase(output_streams.begin());
  }

  return 0;
}