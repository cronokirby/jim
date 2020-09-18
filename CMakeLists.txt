project(jim)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

add_executable(jim
    src/main.cpp
)
target_link_libraries(jim ${GTKMM_LIBRARIES})
