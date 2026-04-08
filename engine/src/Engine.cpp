#include "Engine.hpp"

#include <raylib.h>

#include "ecs/Scene.hpp"

Scene m_scene;

Engine::Engine(const int screenWidth, const int screenHeight, const char *screenTitle)
    : m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_screenTitle(screenTitle)
{
}

Engine::~Engine() = default;

void Engine::Init()
{
    ChangeDirectory(GetApplicationDirectory());

    InitWindow(m_screenWidth, m_screenHeight, m_screenTitle);
    SetTargetFPS(60);

    // initializing player entity
    auto player = m_scene.SceneAddEntity("player");
    CInput input;
    CController controller;
    CPosition position;
    CRigidBody rigidBody;
    CRender render;
    CCamera camera;

    controller.m_controllerMode = ControllerMode::PLAYER;
    position.m_position = {100.0f, 100.0f};
    rigidBody.m_maxVelocity = 400.0f;
    rigidBody.m_maxAcceleration = 4000.0f;
    rigidBody.m_friction = 10.0f;
    render.m_texture = LoadTexture("assets/sprites/char.png");
    render.m_srcRect = {0, 0, 48, 48};
    render.m_scale = 10.0f;
    camera.m_target = player->Id();
    camera.m_camera.target = {position.m_position.x + 20.0f, position.m_position.y + 20.0f};
    camera.m_camera.offset = {m_screenWidth / 2.0f, m_screenHeight / 2.0f};
    camera.m_camera.rotation = 0.0f;
    camera.m_camera.zoom = 1.0f;

    m_scene.SceneAddInput(*player, input);
    m_scene.SceneAddController(*player, controller);
    m_scene.SceneAddPosition(*player, position);
    m_scene.SceneAddRigidBody(*player, rigidBody);
    m_scene.SceneAddRender(*player, render);
    m_scene.SceneAddCamera(*player, camera);

    // initializing refrence entity for player movement
    auto refrence = m_scene.SceneAddEntity("refrence");
    CPosition positionRef;
    CRender renderRef;

    positionRef.m_position = {100.0f, 100.0f};
    renderRef.m_texture = LoadTexture("assets/sprites/char.png");
    renderRef.m_srcRect = {0, 0, 48, 48};
    renderRef.m_scale = 10.0f;

    m_scene.SceneAddPosition(*refrence, positionRef);
    m_scene.SceneAddRender(*refrence, renderRef);

    m_running = true;
}

void Engine::Update()
{
    while (m_running)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (CCamera *camera = m_scene.ActiveCamera())
        {
            BeginMode2D(camera->m_camera);
            m_scene.Update();

            EndMode2D();
        }
        else
        {
            m_scene.Update();
        }

        EndDrawing();

        if (WindowShouldClose())
        {
            m_running = false;
        }
    }
}

void Engine::Quit()
{
    CloseWindow();
}
