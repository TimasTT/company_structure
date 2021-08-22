add_library(parser STATIC
        source/parser.cpp
        include/parser.hpp)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt6 COMPONENTS Core REQUIRED)

target_link_libraries(parser PUBLIC Qt6::Core)

target_include_directories(company_structure PUBLIC
        include)
