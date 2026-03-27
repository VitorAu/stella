#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine
{
  private:
    const int m_screenWidth;
    const int m_screenHeight;
    const char *m_screenTitle;
    bool m_isRunning;

  public:
    Engine(int, int, const char *);
    ~Engine();

    void Init();
    void Update();
    void Quit();
};

#endif // !ENGINE_HPP
