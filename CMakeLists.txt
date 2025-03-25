# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.31.5)


# Название проекта
project(serverGPSn)

# Устанавливаем флаги компилятора для C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Включаем автоматическую обработку moc, uic, rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)



set(mysql-concpp_DIR /Users/developmarin/Desktop/libraries/ConnectorC++)
find_package(mysql-concpp REQUIRED)

set(PROTO_FILES Tracker.proto)
find_package(Protobuf REQUIRED CONFIG)



# Добавление директорий с заголовочными файлами
include_directories("${PROJECT_SOURCE_DIR}/Header Servers")

# Поиск всех .cpp файлов в Source Server и Sources View
file(GLOB SOURCE_SERVERS "${PROJECT_SOURCE_DIR}/Source Servers/*.cpp")

file(GLOB HEADER_SERVERS "${PROJECT_SOURCE_DIR}/Header Servers/*.hpp")

# Добавление main.cpp к списку исходных файлов
list(APPEND SOURCE ${SOURCE_SERVERS} main.cpp)
list(APPEND HEADER ${HEADER_SERVERS} main.hpp)

# Добавляем исполняемый файл
add_executable(server ${SOURCE} ${HEADER})

#добовляем путь для Хэдеров
target_include_directories(server PRIVATE /Users/developmarin/Desktop/libraries/boost)
target_include_directories(server PRIVATE "${mysql-concpp_DIR}/include/jdbc")# Добавляем пути к заголовочным файлам mysql-concpp

# Связывание библиотек
target_link_libraries( server PRIVATE ${mysql-concpp_DIR}/lib64/libmysqlcppconn.10.9.2.0.dylib )
target_link_libraries( server PRIVATE protobuf::libprotobuf)



