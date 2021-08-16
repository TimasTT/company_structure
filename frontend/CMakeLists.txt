find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(main_window STATIC
    main_window/main_window.cpp
    main_window/main_window.h
    main_window/main_window.ui)
target_include_directories(main_window PUBLIC
    main_window/)
target_link_libraries(main_window PUBLIC
    commands company_structure Qt6::Widgets)
