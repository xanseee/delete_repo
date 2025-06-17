# basic
cmake_minimum_required(VERSION 3.30)
set(PROJECT_NAME Fight_ClubX)

project(${PROJECT_NAME} VERSION 1.0.0)	

set(SOURCES Source/Test.cpp)

set(MATH_SOURCES Source/Utils/Math.cpp)
set(MATH_INCLUDES Source/Utils/Math.h)

set(DLL_GAME_SOURCES
	Source/Game/Weapon.cpp
	Source/Game/Character.cpp)

set(DLL_GAME_INCLUDES 
	Source/Game/Weapon.h 
	Source/Game/Character.h)

source_group("Source Files" FILES "Source/Utils/Math.cpp")
source_group("Header Files" FILES "Source/Utils/Math.h")

source_group("Source Files/Game" FILES "Source/Game/Weapon.cpp" "Source/Game/Character.cpp")
source_group("Header Files/Game" FILES "Source/Game/Weapon.h" "Source/Game/Character.h")

#common options
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_SUPPRESS_REGENERATION TRUE)

message("Cmake configuration files ${CMAKE_CONFIGURATION_TYPES}")

# find libs
find_package(nlohmann_json REQUIRED)

# targets
add_executable(${PROJECT_NAME} ${SOURCES})
add_library(MathLib STATIC ${MATH_SOURCES} ${MATH_INCLUDES})
add_library(GameLib SHARED ${DLL_GAME_SOURCES} ${DLL_GAME_INCLUDES})
add_executable(${PROJECT_NAME}TestRunner Source/Tests/main.cpp)

add_executable(ChuckNorris Source/ChuckNorris/main.cpp)

target_compile_definitions(GameLib PRIVATE _EXPORTING)
target_compile_definitions(MathLib PRIVATE _EXPORTING)
target_compile_definitions(${PROJECT_NAME} PUBLIC _IMPORTING)

option(SKIP_GAME_OPT "Skip game" OFF)
if(SKIP_GAME_OPT)
	target_compile_definitions(${PROJECT_NAME} PUBLIC SKIP_GAME)
endif()

# link libraries

target_link_libraries(${PROJECT_NAME} PRIVATE GameLib)
target_link_libraries(GameLib PRIVATE MathLib)
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE MathLib)
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE GameLib)
target_link_libraries(ChuckNorris nlohmann_json::nlohmann_json)

#includes
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_include_directories(GameLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_include_directories(${PROJECT_NAME}TestRunner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)