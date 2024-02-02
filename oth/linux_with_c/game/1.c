#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define DELAY 100

// Define constants for direction
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Define struct for snake body
typedef struct {
    int x;
    int y;
} SnakeSegment;

// Define struct for snake
typedef struct {
    SnakeSegment body[WIDTH * HEIGHT];
    int length;
    int direction;
} Snake;

// Define struct for food
typedef struct {
    int x;
    int y;
} Food;

// Function to initialize the game
void initGame(Snake *snake, Food *food) {
    // Initialize snake
    snake->length = 1;
    snake->body[0].x = WIDTH / 2;
    snake->body[0].y = HEIGHT / 2;
    snake->direction = RIGHT;

    // Initialize food
    generateFood(snake, food);
}

// Function to generate food
void generateFood(Snake *snake, Food *food) {
    do {
        food->x = rand() % (WIDTH - 2) + 1; // Avoid placing food on the walls
        food->y = rand() % (HEIGHT - 2) + 1; // Avoid placing food on the walls
    } while (checkFoodCollision(*snake, *food));
}

// Function to draw the game board
void drawBoard(Snake snake, Food food) {
    clear();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                printw("#");
            else if (i == food.y && j == food.x)
                printw("@");
            else {
                int isSnakeSegment = 0;
                for (int k = 0; k < snake.length; k++) {
                    if (snake.body[k].x == j && snake.body[k].y == i) {
                        printw("O");
                        isSnakeSegment = 1;
                        break;
                    }
                }
                if (!isSnakeSegment)
                    printw(" ");
            }
        }
        printw("\n");
    }
    refresh();
}

// Function to update the snake's position
void updateSnake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    switch (snake->direction) {
        case UP:
            snake->body[0].y--;
            break;
        case DOWN:
            snake->body[0].y++;
            break;
        case LEFT:
            snake->body[0].x--;
            break;
        case RIGHT:
            snake->body[0].x++;
            break;
    }
}

// Function to check for collision with food
int checkFoodCollision(Snake snake, Food food) {
    if (snake.body[0].x == food.x && snake.body[0].y == food.y)
        return 1;
    return 0;
}

// Function to check for collision with walls or self
int checkCollision(Snake snake) {
    if (snake.body[0].x == 0 || snake.body[0].x == WIDTH - 1 || snake.body[0].y == 0 || snake.body[0].y == HEIGHT - 1)
        return 1;
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
            return 1;
    }
    return 0;
}

// Function to update the game
void updateGame(Snake *snake, Food *food) {
    int ch = getch();
    switch (ch) {
        case KEY_UP:
            if (snake->direction != DOWN)
                snake->direction = UP;
            break;
        case KEY_DOWN:
            if (snake->direction != UP)
                snake->direction = DOWN;
            break;
        case KEY_LEFT:
            if (snake->direction != RIGHT)
                snake->direction = LEFT;
            break;
        case KEY_RIGHT:
            if (snake->direction != LEFT)
                snake->direction = RIGHT;
            break;
        case 'q':
            endwin();
            exit(0);
    }
    updateSnake(snake);
    if (checkFoodCollision(*snake, *food)) {
        snake->length++;
        generateFood(snake, food);
    }
}

// Main function
int main() {
    Snake snake;
    Food food;
    int gameOver = 0;

    // Seed random number generator
    srand(time(NULL));

    // Initialize ncurses
    initscr();
    noecho();
    curs_set(0);

    // Enable keypad input
    keypad(stdscr, TRUE);

    // Initialize game
    initGame(&snake, &food);

    // Main game loop
    while (!gameOver) {
        drawBoard(snake, food);
        updateGame(&snake, &food);
        if (checkCollision(snake)) {
            gameOver = 1;
            printw("Game Over!\n");
            refresh();
            sleep(2);
        }
        usleep(DELAY);
    }

    // Clean up
    endwin();

    return 0;
}
