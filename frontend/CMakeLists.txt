find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(main_window STATIC
    main_window/main_window.cpp
    main_window/main_window.h
    main_window/main_window.ui
    add_department_window/add_department.cpp
    add_department_window/add_department.h
    add_department_window/add_department.ui
    delete_department_window/delete_department.cpp
    delete_department_window/delete_department.h
    delete_department_window/delete_department.ui
    add_worker_window/add_worker_window.cpp
    add_worker_window/add_worker_window.h
    add_worker_window/add_worker_window.ui
    delete_worker_window/delete_worker.cpp
    delete_worker_window/delete_worker.h
    delete_worker_window/delete_worker.ui
    change_department_name_window/change_department_name.cpp
    change_department_name_window/change_department_name.h
    change_department_name_window/change_department_name.ui
    )
target_include_directories(main_window PUBLIC
    main_window/)
target_link_libraries(main_window PUBLIC
    commands company_structure Qt6::Widgets)
