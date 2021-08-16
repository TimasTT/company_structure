add_library(commands STATIC
        source/commands_pool.cpp
        include/commands_pool.hpp
        source/commands_tasks.cpp
        include/commands_tasks.hpp)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

target_include_directories(commands PUBLIC
        include)
target_link_libraries(commands company_structure Qt6::Core Qt6::Widgets)
