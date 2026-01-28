add_executable(game main.cpp)

# target_sources(game PRIVATE src/main.cpp)

target_link_libraries(game PRIVATE engine)

add_custom_command(
        TARGET game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/game/assets
        $<TARGET_FILE_DIR:game>/assets
)
