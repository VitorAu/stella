add_library(engine STATIC)

add_subdirectory(vendor)

target_sources(engine PRIVATE 
  src/Engine.cpp

  src/ecs/Entity.cpp
  src/ecs/EntityManager.cpp
  src/ecs/Scene.cpp

  src/systems/Systems.cpp
)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(engine PRIVATE vendor)

