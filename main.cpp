#include <SDL2/SDL.h>
#include <windows.h>
#include <iostream>

// Khai báo kích thước cửa sổ và thanh máu
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int BAR_WIDTH = 200;
const int BAR_HEIGHT = 25;

int main(int argc, char *argv[]) {
    //SetConsoleOutputCP(65001);

    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Tạo cửa sổ
    SDL_Window *window = SDL_CreateWindow("Kiểm tra sức khoẻ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Tạo renderer để vẽ lên cửa sổ
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;}
    SDL_Renderer *renderer1 = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Màu sắc cho thanh máu
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);

    // Vị trí của thanh máu
    SDL_Rect healthBarRect1 = {50, 50, BAR_WIDTH, BAR_HEIGHT};
    SDL_Rect healthBarRect2 = {50, 100, BAR_WIDTH, BAR_HEIGHT};
    SDL_Rect healthBarRect3 = {50, 150, BAR_WIDTH, BAR_HEIGHT};

    // Sức khỏe hiện tại (giả định)
    float currentHealth1 = 100, currentHealth2 = 100, currentHealth3 = 100;

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Giảm sức khỏe mỗi vòng lặp chạy
        currentHealth1 -= 0.1f;
        // Đảm bảo sức khỏe không nhỏ hơn 0
        if (currentHealth1 < 0) {
            currentHealth1 = 0;  }
        if(currentHealth1==0)currentHealth2 -= 0.1f;
        if (currentHealth2 < 0) {
            currentHealth2 = 0;  }
        if(currentHealth2==0)currentHealth3 -= 0.1f;
        if (currentHealth3 < 0) {
            currentHealth3 = 0;
        }

        // Cập nhật kích thước của thanh máu
        healthBarRect1.w = static_cast<int>((currentHealth1 / 40) * BAR_WIDTH);
        healthBarRect2.w = static_cast<int>((currentHealth2 / 40) * BAR_WIDTH);
        healthBarRect3.w = static_cast<int>((currentHealth3 / 40) * BAR_WIDTH);

        // Xóa màn hình
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Vẽ thanh máu
        int heal_sta_1 = 0, heal_sta_2=255;
        if(currentHealth1>=50)
        {
            SDL_SetRenderDrawColor(renderer, heal_sta_1, heal_sta_2, 0, 0);
            SDL_RenderFillRect(renderer, &healthBarRect1);
        }
        else
        {
            heal_sta_1 = 255; heal_sta_2=0;
            SDL_SetRenderDrawColor(renderer, heal_sta_1, heal_sta_2, 0, 0);
            SDL_RenderFillRect(renderer, &healthBarRect1);
        }
        if(currentHealth2>=50)
        {
            SDL_SetRenderDrawColor(renderer, heal_sta_1, heal_sta_2, 0, 0);
            SDL_RenderFillRect(renderer, &healthBarRect2);
        }
        else
        {
            heal_sta_1 = 255; heal_sta_2=0;
            SDL_SetRenderDrawColor(renderer, heal_sta_1, heal_sta_2, 0, 0);
            SDL_RenderFillRect(renderer, &healthBarRect2);
        }
        if(currentHealth3>=50)
        {
            SDL_SetRenderDrawColor(renderer, heal_sta_1, heal_sta_2, 0, 0);
            SDL_RenderFillRect(renderer, &healthBarRect3);
        }
        else
        {
            heal_sta_1 = 255; heal_sta_2=0;
            SDL_SetRenderDrawColor(renderer, heal_sta_1, heal_sta_2, 0, 0);
            SDL_RenderFillRect(renderer, &healthBarRect3);
        }
        //SDL_SetRenderDrawColor(renderer, heal_sta_1, heal_sta_2, 0, 0);
        //SDL_RenderFillRect(renderer, &healthBarRect1);
        //SDL_RenderFillRect(renderer, &healthBarRect2);
        //SDL_RenderFillRect(renderer, &healthBarRect3);

        // Cập nhật màn hình
        SDL_RenderPresent(renderer);

        // Thời gian chờ
        if (currentHealth3>0)
            SDL_Delay(1000 / 60);
        else{SDL_DestroyRenderer(renderer);
             SDL_DestroyWindow(window);
             SDL_Quit();}
    }

    // Giải phóng bộ nhớ và thoát SDL
    //SDL_DestroyRenderer(renderer);
    //SDL_DestroyWindow(window);
    //SDL_Quit();

    return 0;
}
