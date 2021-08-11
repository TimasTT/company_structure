add_library(commands STATIC
        source/commands.cpp
        include/commands.hpp)

target_include_directories(commands PUBLIC
        include)
target_link_libraries(commands company_structure)
