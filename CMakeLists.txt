cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME Ray-Tracer)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#set (SOURCE_DIR ${PROJECT_SOURCE_DIR}/Source source)
#set (VENDOR_DIR ${PROJECT_SOURCE_DIR}/Dependencies vendor)
#set (GLAD_DIR ${PROJECT_SOURCE_DIR}/Dependencies/GLAD)

file(GLOB_RECURSE SOURCE_FILE "${PROJECT_SOURCE_DIR}/Core/src/*.cpp")
file(GLOB_RECURSE INCLUDE_FILE "${PROJECT_SOURCE_DIR}/Core/include/*.h")


add_executable(${PROJECT_NAME}
			${SOURCE_FILE}
			${INCLUDE_FILE})

source_group("Source Files" FILES ${SOURCE_FILE})
source_group("Header Files" FILES ${INCLUDE_FILE})

set_property(TARGET ${PROJECT_NAME} PROPERTY

VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")

#add STB
target_include_directories(${PROJECT_NAME} PUBLIC "external/STB")

#add Maths Library
set(MATHS_DIR "LibMaths")
file(GLOB_RECURSE MATH_SOURCES "${MATHS_DIR}/*.cpp" "${MATHS_DIR}/*.h")
add_library(libMaths STATIC EXCLUDE_FROM_ALL "${MATH_SOURCES}")
target_include_directories(libMaths PRIVATE ${MATHS_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${MATHS_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${MATHS_LIB})

#add SFML
set(SFML_DIR "external/SFML-2.5.1")
file(GLOB_RECURSE SFML_SOURCES "${SFML_DIR}/*.cpp" "${SFML_DIR}/*.hpp")
add_library(SFML STATIC EXCLUDE_FROM_ALL "${SFML_SOURCES}")
target_include_directories(SFML PRIVATE ${SFML_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${SFML_LIB})