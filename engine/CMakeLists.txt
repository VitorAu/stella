add_library(engine STATIC)

target_sources(engine
        PRIVATE
        src/Engine.cpp

        src/ecs/Entity.cpp
        src/ecs/EntityManager.cpp
        src/ecs/Scene.cpp

        src/systems/InputSystem.cpp
        src/systems/MovementSystem.cpp
)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(engine PUBLIC vendor)

add_subdirectory(vendor)
