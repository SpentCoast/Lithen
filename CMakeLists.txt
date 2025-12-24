cmake_minimum_required(VERSION 3.10)
project(Lithen VERSION 1.0)

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
	"Lithen/src/*.h"
	"Lithen/src/*.cpp"
)
target_precompile_headers(Engine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Lithen/src/lnpch.h")
target_sources(Engine PRIVATE ${ENGINE_SOURCES})


target_include_directories(Engine PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/Lithen/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/Lithen/vendor/spdlog/include"
)

target_compile_definitions(Engine PRIVATE LN_BUILD_DLL)
target_compile_definitions(Engine PUBLIC
	$<$<PLATFORM_ID:Windows>:LN_PLATFORM_WINDOWS>
	$<$<CONFIG:Debug>:LN_DEBUG>
	$<$<CONFIG:Release>:LN_RELEASE>
	$<$<CONFIG:Dist>:LN_DIST>
)

set_target_properties(Engine PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_BASE}/Lithen"
	LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_BASE}/Lithen"
	RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_BASE}/Lithen"
)

set_property(TARGET Engine PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<%<CONFIG:Debug>:Debug>")
# -------------------------------

# --------- Lithen App ---------
add_executable(LithenApp)
file(GLOB_RECURSE LITHEN_APP_SOURCES
	"Sandbox/src/*.h"
	"Sandbox/src/*.cpp"
)
target_sources(LithenApp PRIVATE ${LITHEN_APP_SOURCES})

target_link_libraries(LithenApp PRIVATE Engine)

target_compile_definitions(LithenApp PUBLIC
	$<$<PLATFORM_ID:Windows>:LN_PLATFORM_WINDOWS>
	$<$<CONFIG:Debug>:LN_DEBUG>
	$<$<CONFIG:Release>:LN_RELEASE>
	$<$<CONFIG:Dist>:LN_DIST>
)

target_include_directories(Engine PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/Lithen/src"
	"${CMAKE_CURRENT_SOURCE_DIR}/Lithen/vendor/spdlog/include"
)

set_target_properties(LithenApp PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_BASE}/Sandbox"
)

add_custom_command(TARGET LithenApp POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:Engine>
	$<TARGET_FILE_DIR:LithenApp>
)

set_property(TARGET LithenApp PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<%<CONFIG:Debug>:Debug>")
# ---------------------------------
