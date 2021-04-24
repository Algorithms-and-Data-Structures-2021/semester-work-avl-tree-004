# AVL Tree

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-avl-tree-004/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-avl-tree-004/actions/workflows/cmake.yml)

## Краткое описание семестрового проекта:

- _AVL Tree_
- _АВЛ-дерево (англ. AVL-Tree) — сбалансированное двоичное дерево поиска, в котором поддерживается следующее свойство: для каждой его вершины высота её двух поддеревьев различается не более чем на 1._
- _Первоначально АВЛ-дерево было придумано для организации перебора в шахматных программах. Также используется для сортировки массивов и списков. Еще удобно для хранения индексов и проверки существования элементов в БД._
- _Основные операции над структурой: `вставка`, `поиск`, `удаление`, `поиск минимума и максимума`, `полная очистка`, `отображение структуры в консоль`._
- _Вставка, удаление и все операции поиска работают за `O(log(N)`, полная очистка и отображение структуры в консоль работают за `O(N)`._
- _Интересные факты о структуре:_

_1) АВЛ — аббревиатура, образованная первыми буквами фамилий создателей (советских учёных) Георгия Максимовича Адельсон-Вельского и Евгения Михайловича Ландиса._

_2) Советская шахматная программа «Каисса», в котором использовалось АВЛ-дерево, стала первым официальным чемпионом мира в 1974 году._

## _Имя команды и участники_: 

###忍イティサ

| Фамилия Имя           | Вклад (%) | Титул                 |
| :---:                 |   :---:   |  :---:                |
| Semyon Sokolov        | 33        |  Raikage              |
| Sonya Kurguskina      | 33        |  Mizukage             |
| Zukhra Shagiakhmetova | 33        |  Hokage               |

**Девиз команды**
> _Никогда не сдаваться... Встать, когда все рухнуло — вот настоящая сила._
>
> _Как ни крутись, а задница — сзади..._

## Структура проекта

**Проект состоит из следующих частей:**

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Системные требования
**Рекомендованные системные требования:**

_1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше)._

_2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше)._

_3. Рекомендуемый объем оперативной памяти - не менее 4 ГБ._

_4. Свободное дисковое пространство объемом ~ 1,5 ГБ (набор данных для контрольных тестов)._

## Сборка и запуск

_Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы._

### Пример (Windows)

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-avl-tree-004.git
```

#### Генерация тестовых данных

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

```shell
# Перейдите в папку генерации набора данных
cd dataset

# Перейдите в файл
generate_csv_dataset.cpp

# Запустите метод 
main()

# В папке dataset есть папка data, в ней еще 3 папки (erase, find, insert)
cd data

# После запуска скрипта, в этих папках появятся файлы для контрольного тестирования
cd erase
cd find 
cd insert
```

Тестовые данные представлены в CSV формате (см.
[`dataset/data/dataset-example.csv`](dataset/data/dataset-example.csv)):

```csv
623,24,35,231,2,10,64,463,4,893
```

По названию папок, например: `/dataset/data/insert`, можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `100.csv`, `250k.csv`, `5kk.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

#### Контрольные тесты (benchmarks)

_Опишите, как запустить контрольные тесты, что они из себя представляют, какие метрики замеряют (время работы,
потребление памяти и пр.)._

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

**Примечание**. Во избежание "захламления" репозитория большим объёмом данных рекомендуется указать ссылку на архив с
набором данных, который при необходимости можно скачать по ссылке. Наборы данных должны находиться в папке семестровой
работы на [Google Drive](https://drive.google.com/drive/folders/17-qridbMXFnz3E-6UjOj0WD1H0jWtpz3?usp=sharing).

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `random_search_benchmark` | поиск элементов по случайному индексу   | _время_         |
| `add_benchmark`           | добавление элементов в структуру данных | _время, память_ |
| ...                       | ...                                     | ...             |

##### Примеры запуска

```shell
./benchmark <input> <output> --trials 50
```

- `<input>` - входной файл с набором данных в формате CSV;
- `<output>` - выходной файл с результатами контрольного теста;
- `--trials` - количество прогонов на наборе данных и т.д.

Добавление 10000 случайных элементов в структуру данных (повторить операцию 50 раз и вычислить среднее время работы и
потребляемую память):

```
./add_benchmark.exe ../dataset/data/add/10000.csv metrics.txt --trials 50
``` 

где `<input> = ../dataset/data/add/10000.csv` и `<output> = metrics.txt`.

**Примечание**. Файл с метриками не обязателен, можете выводить данные в стандартный поток вывода (т.е. консоль).

## Источники

_Список использованных при реализации структуры данных источников._

_**Это не плагиат, это уважение чужого труда и помощь своим сокурсникам более подробно разобраться в теме.**_
