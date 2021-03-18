# CloudCompare example for standard plugins

# REPLACE ALL 'DarkThemePlugin' OCCURENCES BY YOUR PLUGIN NAME
# AND ADAPT THE CODE BELOW TO YOUR OWN NEEDS!

# Add an option to CMake to control whether we build this plugin or not
option( PLUGIN_DARK_THEME "Install example plugin" OFF )

if ( PLUGIN_DARK_THEME )
	project( DarkThemePlugin )
	 
	AddPlugin( NAME ${PROJECT_NAME} )
		
	add_subdirectory( include )
	add_subdirectory( src )

	target_sources(${PROJECT_NAME}
			PRIVATE
			${CMAKE_CURRENT_LIST_DIR}/qdarkstyle/style.qrc
			)


	# set dependencies to necessary libraries
	# target_link_libraries( ${PROJECT_NAME} LIB1 )
endif()
