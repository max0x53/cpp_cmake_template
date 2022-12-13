set(CMAKE_SYSTEM_NAME Android)

# https://source.android.com/docs/setup/start/build-numbers
if(NOT DEFINED CMAKE_ANDROID_API)
	set(CMAKE_ANDROID_API "31")
endif()

if(NOT DEFINED CMAKE_ANDROID_ARCH_ABI)
	set(CMAKE_ANDROID_ARCH_ABI "arm64-v8a")
endif()

if(NOT DEFINED CMAKE_ANDROID_NDK)
	set(CMAKE_ANDROID_NDK "$ENV{HOME}/Android/Sdk/ndk/25.1.8937393")
endif()

# https://cmake.org/cmake/help/latest/variable/CMAKE_ANDROID_STL_TYPE.html#variable:CMAKE_ANDROID_STL_TYPE
if(NOT DEFINED CMAKE_ANDROID_STL_TYPE)
	set(CMAKE_ANDROID_STL_TYPE c++_shared)
endif()
