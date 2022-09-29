install(
	FILES
		"$<TARGET_FILE:${PROJECT_NAME}>"
		"$<TARGET_PDB_FILE:${PROJECT_NAME}>"
	DESTINATION "SKSE/Plugins"
	COMPONENT SKSEPlugin
)

install(
	FILES ${SDK_OUTPUT}
	DESTINATION "Scripts"
	COMPONENT Data
)

install(
	FILES ${SDK_SOURCES}
	DESTINATION "Source/Scripts"
	COMPONENT Data
)

if(NOT BUILD_SKYRIMVR)
	install(
		FILES
			"${CMAKE_CURRENT_SOURCE_DIR}/data/SkyrimSE/DontEatSpellTomes.esp"
		DESTINATION "."
		COMPONENT Example_Plugin
	)
else()
	install(
		FILES
			"${CMAKE_CURRENT_SOURCE_DIR}/data/SkyrimVR/DontEatSpellTomes.esp"
		DESTINATION "."
		COMPONENT Example_Plugin
	)
endif()

install(
	FILES ${Example_OUTPUT}
	DESTINATION "Scripts"
	COMPONENT Example_Data
)

install(
	FILES ${Example_SOURCES}
	DESTINATION "Source/Scripts"
	COMPONENT Example_Data
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
