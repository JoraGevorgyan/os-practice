set(BINARY ${CMAKE_PROJECT_NAME})

set(INCLUDE_DIR ../lib/calculator ../lib/printer)

include_directories(${INCLUDE_DIR})

add_executable(${BINARY}_exec main.cpp)

target_link_libraries(${BINARY}_exec PUBLIC
					  ${BINARY}_calculator ${BINARY}_printer)

