# The minimum version of cmake needed for the project
# I believe 3.18 is the latest, but this should be a reasonable version for now
cmake_minimum_required(VERSION 3.10)
# Then we declare our project, which is at version 0.1
project(jim VERSION 0.1)

# We declare that we're using C++ 17, and require that as well
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# We need PkgConfig, since we'll be using the gtkmm third party library later in the project
find_package(PkgConfig REQUIRED)

# Make sure that we have the package gtkmm, and then set the related variables
pkg_check_modules(GTKMM gtkmm-3.0)
# Add the directories we'll use to link with gtkmm later
link_directories(${GTKMM_LIBRARY_DIRS})
# Setup the include directories so that we can see the header files
include_directories(${GTKMM_INCLUDE_DIRS})
# Include the other miscellaneous definitions that we might need
add_definitions(${GTKMM_CFLAGS_OTHER})

# Now we have our main executable, which is produced by our project
add_executable(jim
    src/main.cpp
)
# We link the executable with gtkmm, since it depends on that to work
target_link_libraries(jim ${GTKMM_LIBRARIES})
# We also want to have compiler warnings for this target, but not set them globally
target_compile_options(jim PRIVATE -Werror -Wall -Wextra)
