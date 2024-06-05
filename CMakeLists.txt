cmake_minimum_required(VERSION 3.29)

project ("samp-rce-fix"
	VERSION 0.0
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

include(FetchContent)

FetchContent_Declare(
	RakHook
	GIT_REPOSITORY https://github.com/imring/RakHook.git
	GIT_TAG 625fd17897395997feb56ae293c7c07dbe49d26b
)
FetchContent_MakeAvailable(rakhook)

add_library(${PROJECT_NAME} SHARED)
target_link_libraries(${PROJECT_NAME} PUBLIC rakhook)
target_sources(${PROJECT_NAME} PRIVATE
	src/main.cpp
)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	OUTPUT_NAME ${PROJECT_NAME}
	SUFFIX ".asi"
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)