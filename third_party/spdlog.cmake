set(SPDLOG_ENABLE_PCH ON CACHE BOOL "Build library using precompiled header to speed up compilation time")
set(SPDLOG_NO_EXCEPTIONS ON CACHE BOOL "Compile with -fno-exceptions. Call abort() on any spdlog exceptions")

Include(FetchContent)

FetchContent_Declare(
  spdlog 
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.11.0
)

FetchContent_MakeAvailable(spdlog)

