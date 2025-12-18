cmake_minimum_required(VERSION 3.10)
project(LithenEngine VERSION 1.0)

# ---------- Global Setup ---------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DIST "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_DIST "${CMAKE_EXE_LINKER_FLAGS_RELEASE}" CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_DIST "${CMAKE_SHARED_LINKER_FLAGS_RELEASE}" CACHE STRING "" FORCE)
# ---------------------------------

# ---------- Helpers ---------
if(WIN32)
	set(OUTPUT_BASE "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>-x64")
endif()

if(MSVC)
	add_compile_options(/utf-8)
endif()
# ----------------------------

# --------- Engine Core ---------
add_library(Engine SHARED)
file(GLOB_RECURSE ENGINE_SOURCES
	"Engine/src/*.h"
	"Engine/src/*.cpp"
)
target_precompile_headers(Engine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Engine/src/lnpch.h")
target_sources(Engine PRIVATE ${ENGINE_SOURCES})


target_include_directories(Engine PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/Engine/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/Engine/vendor/spdlog/include"
)

target_compile_definitions(Engine PRIVATE LN_BUILD_DLL)
target_compile_definitions(Engine PUBLIC
	$<$<PLATFORM_ID:Windows>:LN_PLATFORM_WINDOWS>
	$<$<CONFIG:Debug>:LN_DEBUG>
	$<$<CONFIG:Release>:LN_RELEASE>
	$<$<CONFIG:Dist>:LN_DIST>
)

set_target_properties(Engine PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_BASE}/Engine"
	LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_BASE}/Engine"
	RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_BASE}/Engine"
)

set_property(TARGET Engine PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<%<CONFIG:Debug>:Debug>")
# -------------------------------

# --------- Sandbox (App) ---------
add_executable(Sandbox)
file(GLOB_RECURSE SANDBOX_SOURCES
	"Sandbox/src/*.h"
	"Sandbox/src/*.cpp"
)
target_sources(Sandbox PRIVATE ${SANDBOX_SOURCES})

target_link_libraries(Sandbox PRIVATE Engine)

target_compile_definitions(Sandbox PUBLIC
	$<$<PLATFORM_ID:Windows>:LN_PLATFORM_WINDOWS>
	$<$<CONFIG:Debug>:LN_DEBUG>
	$<$<CONFIG:Release>:LN_RELEASE>
	$<$<CONFIG:Dist>:LN_DIST>
)

target_include_directories(Engine PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/Engine/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/Engine/vendor/spdlog/include"
)

set_target_properties(Sandbox PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_BASE}/Sandbox"
)

add_custom_command(TARGET Sandbox POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:Engine>
	$<TARGET_FILE_DIR:Sandbox>
)

set_property(TARGET Sandbox PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<%<CONFIG:Debug>:Debug>")
# ---------------------------------
