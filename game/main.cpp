#include "Engine.hpp"

const int screenWidth = 800;
const int screenHeight = 640;
const char *screenTitle = "Stella";

int main()
{
    Engine engine(screenWidth, screenHeight, screenTitle);

    engine.Init();
    engine.Update();
    engine.Quit();

    return 0;
}
