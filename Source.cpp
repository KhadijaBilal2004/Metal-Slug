#include <iostream>
#include <raylib.h>

const int SCREEN_WIDTH = 1150;
const int SCREEN_HEIGHT = 380;

struct Player 
{
    Texture2D texture;
    Vector2 position;
    float speed;
};

void InitPlayer(Player& player)
{
    player.texture = LoadTexture("player1.png");  
    player.position = { 100, float(SCREEN_HEIGHT - player.texture.height - 10) };
    player.speed = 200.0f;
}
void DrawPlayer(Player& player) 
{
    DrawTexture(player.texture, player.position.x, player.position.y, WHITE);
}

int main() 
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Metal Slug - Starter");
    SetTargetFPS(60);
    Player player;
    InitPlayer(player);
    Texture2D b1 =LoadTexture("b1_metal_slug.png");
    Texture2D b2 = LoadTexture("b2_metal_slug.png");
    b1.height = SCREEN_HEIGHT;
    b2.height = SCREEN_HEIGHT;
    b1.width = SCREEN_WIDTH;
    b2.width = SCREEN_WIDTH;

    int b1x = 0;
    int b2x = SCREEN_WIDTH;
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime(); 
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(b1, b1x, 0, WHITE);
        DrawTexture(b2, b2x, 0, WHITE);
        if (IsKeyDown(KEY_RIGHT))
        {
            player.position.x += player.speed * deltaTime;
            b1x -= 2;
            b2x -= 2;
        }
        if (IsKeyDown(KEY_LEFT))
        {
            player.position.x -= player.speed * deltaTime;
       
        }
        if (b1x <= -SCREEN_WIDTH)
        {
            b1x *= -1;
        }
        if (b2x <= -SCREEN_WIDTH)
        {
            b2x *= -1;
        }
        DrawPlayer(player);
        DrawText("Move with Arrow Keys", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadTexture(player.texture);
    CloseWindow();

    return 0;
}
