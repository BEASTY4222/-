#include <iostream>
#include "raylib.h"

#include "QvorovMainFrame.h"

int main()
{
    int screenWidth = 950;
    int screenHeight = 750;
    bool fullScreen = false;
    std::cout << "full screen or windowed mode?" << std::endl;
    std::string mode;
    std::cin >> mode;
    if(mode[0] == 'f' || mode[0] == 'F'){
        fullScreen = true;
        screenWidth = GetMonitorWidth(0);
        screenHeight = GetMonitorHeight(0);

    }else{
        screenWidth = 950;
        screenHeight = 750;
    }

    // Initialize window
    InitWindow(screenWidth, screenHeight, "Peyo Qvorov Interview");
    InitAudioDevice();
    
    QvorovMainFrame mainFrame(fullScreen);

    // Main game loop
    while (!WindowShouldClose()) {

		mainFrame.runMath();

        BeginDrawing();
        ClearBackground({ 230, 200, 170, 255 });
        
		mainFrame.runVisuals();


        EndDrawing();
    }

    // Cleanup
    CloseWindow();
	CloseAudioDevice();

    return 0;
}
