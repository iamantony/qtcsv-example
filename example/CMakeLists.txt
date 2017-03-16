cmake_minimum_required(VERSION 2.8.11)

project (example)

if(USE_QT4)
    find_package(Qt4 REQUIRED)
    set(QT_CORE_TARGET Qt4::QtCore)
else()
    # if cmake failed to find Qt5Core configuration file, set path manually:
    #list(APPEND CMAKE_PREFIX_PATH "/path/to/Qt/lib/cmake/Qt5Core/")

    find_package(Qt5Core REQUIRED)
    set(QT_CORE_TARGET Qt5::Core)
endif(USE_QT4)

# define names
set(BINARY_NAME ${PROJECT_NAME})

# instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# add also the header part to source files. this is necessary for correct automoc
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(${BINARY_NAME} ${SOURCE_FILES} )

TARGET_LINK_LIBRARIES(${BINARY_NAME} PRIVATE ${QT_CORE_TARGET} qtcsv)

# provide current project dir for projects header search path
target_include_directories(${BINARY_NAME} PRIVATE .)
