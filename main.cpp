#include <SDL2/SDL.h>
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

// Kiểm tra xem chuột có nằm trong hình vuông không
bool IsMouseInsideSquare(int mouseX, int mouseY, int squareX, int squareY, int squareSize) {
    return (mouseX >= squareX && mouseX <= squareX + squareSize &&
            mouseY >= squareY && mouseY <= squareY + squareSize);
}

int main(int argc, char* argv[]) {
    // Khởi tạo SDL2
    SDL_Init(SDL_INIT_VIDEO);

    // Tạo cửa sổ
    SDL_Window* window = SDL_CreateWindow("Moving Square", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Tạo renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_Renderer* renderer2 = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Khởi tạo biến vị trí của hình vuông và chuột
    int squareX1 = 640;     int squareX2 = 640;
    int squareY1 = 680;     int squareY2 = 40;
    int mouseX = 0;
    int mouseY = 0;
    bool mousePressed1 = false; // Biến để theo dõi trạng thái chuột
    bool mousePressed2 = false;

    // Kích thước hình vuông
    int squareSize1 = 20;              int squareSize2 = 20;

    // Vòng lặp chính
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        // Xử lý sự kiện
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&mouseX, &mouseY);
                if (IsMouseInsideSquare(mouseX, mouseY, squareX1, squareY1, squareSize1)) {
                    mousePressed1 = true;
                }
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&mouseX, &mouseY);
                if (IsMouseInsideSquare(mouseX, mouseY, squareX2, squareY2, squareSize2)) {
                    mousePressed2 = true;
                }
            }
            else if (event.type == SDL_MOUSEBUTTONUP) {
                mousePressed1 = false;
                mousePressed2 = false;
            }
            else if (event.type == SDL_MOUSEMOTION && mousePressed1) {
                SDL_GetMouseState(&mouseX, &mouseY);
                squareX1 = mouseX - squareSize1 / 2;
                squareY1 = mouseY - squareSize1 / 2;
            }
            else if (event.type == SDL_MOUSEMOTION && mousePressed2) {

                SDL_GetMouseState(&mouseX, &mouseY);
                squareX2 = mouseX - squareSize2 / 2;
                squareY2 = mouseY - squareSize2 / 2;
            }
        }

        // Xóa màn hình
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_Rect square1 = {squareX1, squareY1, squareSize1, squareSize1}; // Kích thước hình vuông
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &square1);
        //SDL_RenderPresent(renderer1);

        //SDL_SetRenderDrawColor(renderer2, 0, 0, 0, 255);
        //SDL_RenderClear(renderer2);
        SDL_Rect square2 = {squareX2, squareY2, squareSize2, squareSize2};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &square2);
        SDL_RenderPresent(renderer);
    }

/**    quit = false;
    //SDL_Event event2;
    while (!quit) {
        // Xử lý sự kiện
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                // Kiểm tra xem chuột có nằm trong hình vuông không
                SDL_GetMouseState(&mouseX, &mouseY);
                if (IsMouseInsideSquare(mouseX, mouseY, squareX2, squareY2, squareSize2)) {
                    // Bắt đầu giữ chuột
                    mousePressed = true;
                }
            } else if (event.type == SDL_MOUSEBUTTONUP) {
                // Thả chuột
                mousePressed = false;
            } else if (event.type == SDL_MOUSEMOTION && mousePressed) {
                // Lấy vị trí chuột khi di chuyển chuột
                SDL_GetMouseState(&mouseX, &mouseY);

                // Cập nhật vị trí hình vuông theo vị trí mới của chuột
                squareX2 = mouseX - squareSize2 / 2;
                squareY2 = mouseY - squareSize2 / 2;
            }
        }

        // Xóa màn hình
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Vẽ hình vuông
        SDL_Rect square2 = {squareX2, squareY2, squareSize2, squareSize2}; // Kích thước hình vuông
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Màu trắng
        SDL_RenderFillRect(renderer, &square2);

        // Cập nhật cửa sổ
        SDL_RenderPresent(renderer);
    } **/
    // Giải phóng bộ nhớ và thoát SDL
    SDL_DestroyRenderer(renderer);    //SDL_DestroyRenderer(renderer2);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
