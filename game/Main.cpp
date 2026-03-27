#include <cstdlib>

#include "Engine.hpp"

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
const char *SCREEN_TITLE = "Stella";

int main()
{
  Engine engine(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
  
  engine.Init();
  engine.Update();
  engine.Quit();

  return EXIT_SUCCESS;
}
