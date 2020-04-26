cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(SOURCE_FILES
        src/Student.cpp
        src/model/Client.cpp
        include/model/Client.hpp
        )

#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)