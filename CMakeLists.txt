cmake_minimum_required(VERSION 3.24)

project(
    DontEatSpellTomes
	VERSION 1.2.2
	LANGUAGES CXX
)

# Papyrus API version
set(API_VERSION 2)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_IGNORE_PATH "${PROJECT_BINARY_DIR}")
list(APPEND CMAKE_MODULE_PATH
	"${PROJECT_SOURCE_DIR}/cmake"
	"${PROJECT_SOURCE_DIR}/tools/SKSE-CMakeModules/Modules"
	"${PROJECT_SOURCE_DIR}/tools/BethesdaCMakeModules/Modules"
)
include(SKSEPlugin)
include(Papyrus)

set(SKSE_USE_XBYAK ON)
set(SKSE_SUPPORT_VR ON)

SKSEPlugin_Add(
	${PROJECT_NAME}
	SOURCE_DIR src
	SOURCES
		.clang-format
		.editorconfig
		README.md
		vcpkg.json
	PRECOMPILE_HEADERS
		src/PCH.h
)

target_compile_definitions(
	${PROJECT_NAME}
	PRIVATE
		DEST_API_VERSION=${API_VERSION}
)

file(GLOB SDK_SOURCES
	LIST_DIRECTORIES false
	CONFIGURE_DEPENDS
	"scripts/SDK/*.psc"
)

Papyrus_Add(
	"SDK"
	GAME ${SkyrimSE_PATH}
	IMPORTS
		"${CMAKE_CURRENT_SOURCE_DIR}/scripts/SDK"
		"$ENV{SKSE64Path}/Scripts/Source"
	SOURCES ${SDK_SOURCES}
	OPTIMIZE
	ANONYMIZE
	COMPONENT Data
)

Papyrus_Add(
	"Example"
	GAME ${SkyrimSE_PATH}
	IMPORTS
		"${CMAKE_CURRENT_SOURCE_DIR}/scripts/Example"
		"${CMAKE_CURRENT_SOURCE_DIR}/scripts/SDK"
		"$ENV{SKSE64Path}/Scripts/Source"
	SOURCES
		"${CMAKE_CURRENT_SOURCE_DIR}/scripts/Example/DEST_PlayerSpellLearningScript.psc"
	OPTIMIZE
	ANONYMIZE
	COMPONENT Example_Data
)

install(
	FILES
		"${CMAKE_CURRENT_SOURCE_DIR}/data/$<IF:$<BOOL:BUILD_SKYRIMVR>,SkyrimVR,SkyrimSE>/DontEatSpellTomes.esp"
	DESTINATION "."
	COMPONENT Example_Plugin
)

install(
	FILES
		"${CMAKE_CURRENT_SOURCE_DIR}/data/Fomod/info.xml"
		"${CMAKE_CURRENT_SOURCE_DIR}/data/Fomod/ModuleConfig.xml"
		"${CMAKE_CURRENT_SOURCE_DIR}/data/Fomod/dest_card.png"
	DESTINATION "fomod"
	COMPONENT Fomod
	EXCLUDE_FROM_ALL
)
