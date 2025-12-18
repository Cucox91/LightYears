# Creating an Executable File. This is like the staring point of the app.
add_executable(
	${LIGHT_YEARS_GAME_TARGET_NAME} 
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
)

# Tis will target the include directories so the can be referenced on the project.
target_include_directories(
	${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


# This will link our project to the downloaded libraries.
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-audio)

# We are going to create a finction that copy the DLLs to the Executable Path Folder.

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	# Copy (If Different) the sfml-window DLL to executable file location.
	add_custom_command(
		TARGET ${TARGET_NAME}
		POST_BUILD
		COMMAND
		${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:${LIB_NAME}>						# Generative Elements is the name of this syntaxis. Is kind of a placeholder.
		$<TARGET_FILE_DIR:${TARGET_NAME}>				# Generative Elements is the name of this syntaxis. Is kind of a placeholder.
	)
endfunction()

CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-window ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_GAME_TARGET_NAME})