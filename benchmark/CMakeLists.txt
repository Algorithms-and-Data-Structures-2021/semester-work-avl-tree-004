# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.
add_executable(insertBenchmark insertBenchmark.cpp)
add_executable(findBenchmark findBenchmark.cpp)
add_executable(eraseBenchmark eraseBenchmark.cpp)

# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(insertBenchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(findBenchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(eraseBenchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})