# This `CMakeLists.txt` does not require other statements such as the minimum version and project name.
# This is because `hello_world` is an executable of `cpp_cmake_template` and is not intended to be built outside of this build context.

option(MATH_BUILD_SHARED "Build shared library instead of static" OFF)

option(MATH_BUILD_TESTS "Build tests" OFF)

set(MATH_TARGET_NAME math)

set(MATH_SRCS
	src/add.cpp
	src/multiply.cpp
)

if(MATH_BUILD_SHARED)
	add_library(${MATH_TARGET_NAME} SHARED)
else()
	add_library(${MATH_TARGET_NAME} STATIC)
endif()

target_sources(${MATH_TARGET_NAME} PRIVATE ${MATH_SRCS})

target_include_directories(${MATH_TARGET_NAME} PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

if(MATH_BUILD_TESTS)
	message(STATUS "Building tests")
	include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/catch2_tests.cmake)

	# Ensures that the correct headers and compiler definitions are present in `compile_commands.json`.
	# Enabling intellisense to function as expected improving debugging of tests.
	target_link_libraries(${MATH_TARGET_NAME} PRIVATE Catch2::Catch2)
	target_compile_definitions(${MATH_TARGET_NAME} PRIVATE MATH_ENABLE_TEST)

	set(MATH_TEST_TARGET_NAME test_${MATH_TARGET_NAME})

	add_executable(${MATH_TEST_TARGET_NAME} ${MATH_SRCS})

	target_link_libraries(${MATH_TEST_TARGET_NAME} PRIVATE Catch2::Catch2WithMain)
	target_compile_definitions(${MATH_TEST_TARGET_NAME} PRIVATE MATH_ENABLE_TEST)

	catch_discover_tests(${MATH_TEST_TARGET_NAME})
endif()
