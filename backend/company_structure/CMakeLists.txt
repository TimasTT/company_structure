add_library(company_structure STATIC
        source/company_structure.cpp
        include/company_structure.hpp)

target_include_directories(company_structure PUBLIC
        include)