# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.31.5)


# Название проекта
project(MyProject)

# Устанавливаем флаги компилятора для C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Включаем автоматическую обработку moc, uic, rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(Qt6_DIR /Users/developmarin/Qt/6.8.2/macos/lib/cmake/Qt6)
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core Svg)

set(mysql-concpp_DIR /Users/developmarin/Desktop/libraries/ConnectorC++)
find_package(mysql-concpp REQUIRED)

set(PROTO_FILES Tracker.proto)
find_package(Protobuf REQUIRED CONFIG)



# Добавление директорий с заголовочными файлами
include_directories("${PROJECT_SOURCE_DIR}/Header Servers")
include_directories("${PROJECT_SOURCE_DIR}/Header Views")
include_directories("${mysql_concpp_DIR}/include/jdbc")
include_directories("/Users/developmarin/Desktop/libraries/ConnectorC++/include/jdbc")

# Поиск всех .cpp файлов в Source Server и Sources View
file(GLOB SOURCE_SERVERS "${PROJECT_SOURCE_DIR}/Source Servers/*.cpp")
file(GLOB SOURCE_VIEWS "${PROJECT_SOURCE_DIR}/Source Views/*.cpp")

file(GLOB HEADER_SERVERS "${PROJECT_SOURCE_DIR}/Header Servers/*.hpp")
file(GLOB HEADER_VIEWS "${PROJECT_SOURCE_DIR}/Header Views/*.hpp")

# Добавление main.cpp к списку исходных файлов
list(APPEND SOURCE ${SOURCE_SERVERS} ${SOURCE_VIEWS} main.cpp)
list(APPEND HEADER ${HEADER_SERVERS} ${HEADER_VIEWS} main.hpp)

# Добавляем исполняемый файл
add_executable(server ${SOURCE} ${HEADER})

#добовляем путь для Хэдеров
target_include_directories(server PRIVATE /Users/developmarin/Desktop/libraries/boost)
# Добавляем пути к заголовочным файлам mysql-concpp

# Связывание библиотек
target_link_libraries( server PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core Qt6::Svg )
target_link_libraries( server PRIVATE /Users/developmarin/Desktop/libraries/ConnectorC++/lib64/libmysqlcppconn.10.9.2.0.dylib )
target_link_libraries( server PRIVATE protobuf::libprotobuf)



