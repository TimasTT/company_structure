add_library(parser STATIC
        source/parser.cpp
        include/parser.hpp)

target_include_directories(company_structure PUBLIC
        include)
