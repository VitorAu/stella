#include "Engine.hpp"

#include <raylib.h>

#include "ecs/Scene.hpp"

Scene m_scene;

Engine::Engine(int screenWidth, int screenHeight, const char *screenTitle)
    : m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_screenTitle(screenTitle)
{
}

Engine::~Engine()
{
}

void Engine::Init()
{
    ChangeDirectory(GetApplicationDirectory());

    InitWindow(m_screenWidth, m_screenHeight, m_screenTitle);
    SetTargetFPS(60);

    auto player = m_scene.SceneAddEntity("player");
    CTransform transform;
    transform.m_x = 200.0f;
    transform.m_y = 200.0f;

    CRender render;
    render.m_tex = LoadTexture("assets/char.png");
    render.m_srcRec = {0, 0, 48, 48};
    render.m_destRec = {200, 200, 100, 100};
    render.m_vecOrigin = {render.m_destRec.width, render.m_destRec.height};
    render.m_rotation = 0.0f;

    CInput input;

    m_scene.SceneAddTransform(transform, *player);
    m_scene.SceneAddRender(render, *player);
    m_scene.SceneAddInput(input, *player);

    m_isRunning = true;
}

void Engine::Update()
{
    while (m_isRunning)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        m_scene.Update();

        EndDrawing();

        if (WindowShouldClose()) m_isRunning = false;
    }
}

void Engine::Quit()
{
    CloseWindow();
}
