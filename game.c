#include <raylib.h>
#include <raymath.h>

#define BALL_RADIUS 100.0
#define GRAVITY 1000.0

static Vector2 ball_position = {0};
static Vector2 ball_velocity = {200, 200};

void game_frame()
{
    BeginDrawing();
        ClearBackground((Color){20, 20, 20, 255});
        float dt = GetFrameTime();
        ball_velocity.y += GRAVITY*dt;
        float x = ball_position.x + ball_velocity.x*dt;
        if (x - BALL_RADIUS < 0.0 || x + BALL_RADIUS >= GetScreenWidth()) {
            ball_velocity.x *= -1.0f;
        } else {
            ball_position.x = x;
        }
        float y = ball_position.y + ball_velocity.y*dt;
        if (y - BALL_RADIUS < 0.0 || y + BALL_RADIUS >= GetScreenHeight()) {
            ball_velocity.y *= -1.0f;
        } else {
            ball_position.y = y;
        }
        DrawCircleV(ball_position, BALL_RADIUS, RED);
    EndDrawing();
}

void game_init()
{
    InitWindow(800, 600, "Hello, from WebAssembly");
    SetTargetFPS(60);

    int w = GetScreenWidth();
    int h = GetScreenHeight();
    ball_position.x = w/2;
    ball_position.y = h/2;
}

void game_over()
{
    CloseWindow();
}

#ifndef PLATFORM_WEB
int main()
{
    game_init();
    while (!WindowShouldClose()) {
        game_frame();
    }
    game_over();
    return 0;
}
#endif
