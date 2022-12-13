cmake_minimum_required(VERSION 3.21)

project(hello_world)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(HELLO_WORLD_TARGET_NAME hello_world)

add_executable(${HELLO_WORLD_TARGET_NAME}
    src/main.cpp
)

target_include_directories(${HELLO_WORLD_TARGET_NAME} PRIVATE
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_link_libraries(${HELLO_WORLD_TARGET_NAME} PRIVATE
	spdlog::spdlog
	math
)

target_compile_options(${HELLO_WORLD_TARGET_NAME} PUBLIC
	$<$<CONFIG:Release>:-Os;-flto;>
	$<$<CONFIG:Debug>:-Wall;-Werror;-Wextra;>

	-fno-exceptions

	PRIVATE
	-fvisibility=hidden
)
