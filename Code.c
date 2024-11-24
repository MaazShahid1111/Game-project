#include <raylib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char word[30];
    char hint[50];
} GameItem;

GameItem countries[] = {
    {"ARGENTINA", "A country known for tango and football."},
    {"BRAZIL", "Famous for its Amazon rainforest."},
    {"CANADA", "Known for maple syrup and hockey."},
    {"CHINA", "The most populous country."},
    {"FRANCE", "Home to the Eiffel Tower."},
    {"GERMANY", "Known for its engineering and Oktoberfest."},
    {"INDIA", "The country of spices and diverse cultures."},
    {"ITALY", "Famous for its pizza and ancient Rome."},
    {"JAPAN", "Land of the rising sun and sushi."},
    {"MEXICO", "Famous for tacos and mariachi music."},
    {"SPAIN", "Known for flamenco dancing and paella."},
    {"RUSSIA", "The largest country in the world."},
    {"AUSTRALIA", "Famous for kangaroos and the Outback."},
    {"EGYPT", "Home to ancient pyramids."},
    {"SOUTHAFRICA", "Known for its safaris and wildlife."},
    {"THAILAND", "Famous for its tropical beaches and temples."},
    {"TURKEY", "The country that bridges Europe and Asia."},
    {"NEWZEALAND", "Known for its stunning landscapes and Maori culture."},
    {"GREECE", "Home to ancient philosophers and mythology."},
    {"SWITZERLAND", "Famous for chocolate and the Alps."}
};

GameItem animals[] = {
    {"ELEPHANT", "The largest land animal."},
    {"GIRAFFE", "The tallest animal on Earth."},
    {"TIGER", "A big cat known for its stripes."},
    {"LION", "The king of the jungle."},
    {"KANGAROO", "A marsupial that carries its young in a pouch."},
    {"PENGUIN", "A flightless bird that swims in the Antarctic."},
    {"PANDA", "A black and white bear that eats bamboo."},
    {"CHEETAH", "The fastest land animal."},
    {"DOLPHIN", "A highly intelligent aquatic mammal."},
    {"EAGLE", "A bird of prey with sharp vision."},
    {"KOALA", "A marsupial that feeds on eucalyptus leaves."},
    {"CROCODILE", "A large reptile with a powerful bite."},
    {"HIPPOPOTAMUS", "A massive semi-aquatic mammal."},
    {"PEACOCK", "A bird known for its colorful feathers."},
    {"RHINOCEROS", "A large mammal with a horn on its nose."},
    {"WOLF", "A wild canine known for its pack behavior."},
    {"OTTER", "A playful aquatic mammal."},
    {"SLOTH", "A slow-moving tree-dwelling animal."},
    {"BAT", "The only mammal capable of true flight."},
    {"FLAMINGO", "A bird known for its pink feathers."}
};

GameItem movies[] = {
    {"INCEPTION", "A movie about dream manipulation."},
    {"AVATAR", "A sci-fi movie set on an alien planet."},
    {"TITANIC", "A historical romance on a sinking ship."},
    {"JOKER", "A film about the rise of a villain."},
    {"GLADIATOR", "A Roman epic with a fight for vengeance."},
    {"INTERSTELLAR", "A space epic about saving humanity."},
    {"FROZEN", "A Disney movie with a magical ice queen."},
    {"AVENGERS", "A superhero movie with Earth's mightiest heroes."},
    {"BATMAN", "A movie about a masked vigilante of Gotham."},
    {"ALADDIN", "A Disney movie featuring a magical lamp."},
    {"SPIDERMAN", "A superhero who can climb walls."},
    {"HARRY", "A young wizard's fight against dark forces."},
    {"LIONKING", "A story about a lion cub finding his destiny."},
    {"CINDERELLA", "A fairytale about a girl and her glass slipper."},
    {"MATRIX", "A sci-fi film about simulated reality."},
    {"PARASITE", "A Korean thriller about class disparity."},
    {"TOYSTORY", "An animated film about toys coming to life."},
    {"UP", "A story about an old man and a floating house."},
    {"COCO", "A boy's journey in the Land of the Dead."},
    {"SHREK", "An animated film about an ogre and his adventures."}
};

GameItem games[] = {
    {"CHESS", "A strategic board game."},
    {"MONOPOLY", "A board game about property trading."},
    {"POKEMON", "A franchise involving capturing creatures."},
    {"MARIO", "A video game series featuring a plumber."},
    {"ZELDA", "A video game series featuring a hero named Link."},
    {"PACMAN", "A classic arcade game."},
    {"TETRIS", "A tile-matching puzzle game."},
    {"FORTNITE", "A popular battle royale video game."},
    {"MINECRAFT", "A sandbox game about building and exploration."},
    {"OVERWATCH", "A team-based shooter game."},
    {"PUBG", "A battle royale game with last-player standing."},
    {"FIFA", "A football simulation video game."},
    {"CALLDUTY", "A first-person shooter series."},
    {"HALO", "A sci-fi game about a super-soldier."},
    {"DOOM", "A classic first-person shooter game."},
    {"SCRABBLE", "A word game using letter tiles."},
    {"UNO", "A card game with colorful rules."},
    {"FALLOUT", "A post-apocalyptic role-playing game."},
    {"CYBERPUNK", "A futuristic open-world RPG."},
    {"SIMS", "A life simulation video game."}
};

int numCountries = sizeof(countries) / sizeof(countries[0]);
int numAnimals = sizeof(animals) / sizeof(animals[0]);
int numMovies = sizeof(movies) / sizeof(movies[0]);
int numGames = sizeof(games) / sizeof(games[0]);

// Rest of the code remains unchanged


void displayHangman(int attempts) {
    Vector2 base = {600, 300};
    int lineThickness = 6; // Set line thickness
    
    // Draw the base of the gallows (platform)
    DrawRectangle(base.x - 25, base.y, 100, 10, WHITE); // Platform

    // Vertical pole (thicker)
    DrawLineEx((Vector2){base.x, base.y - 200}, (Vector2){base.x, base.y}, lineThickness, WHITE);

    // Top horizontal bar (thicker)
    DrawLineEx((Vector2){base.x, base.y - 200}, (Vector2){base.x + 50, base.y - 200}, lineThickness, WHITE);
    
    // Rope hanging from the bar
    DrawLineEx((Vector2){base.x + 50, base.y - 200}, (Vector2){base.x + 50, base.y - 150}, lineThickness, WHITE);

    // Optional: Draw a small support at the top to make it more realistic
    DrawLineEx((Vector2){base.x + 50, base.y - 200}, (Vector2){base.x + 60, base.y - 200}, lineThickness, WHITE);

    // If there are attempts left, draw the hangman figure:
    if (attempts <= 5) {
        // Head (solid circle with same thickness as body parts)
        DrawCircle(base.x + 50, base.y - 130, 20, WHITE); 
    }
    if (attempts <= 4) {
        // Body (thicker)
        DrawLineEx((Vector2){base.x + 50, base.y - 110}, (Vector2){base.x + 50, base.y - 50}, lineThickness, WHITE);
    }
    if (attempts <= 3) {
        // Left Arm (thicker)
        DrawLineEx((Vector2){base.x + 50, base.y - 90}, (Vector2){base.x + 30, base.y - 70}, lineThickness, WHITE);
    }
    if (attempts <= 2) {
        // Right Arm (thicker)
        DrawLineEx((Vector2){base.x + 50, base.y - 90}, (Vector2){base.x + 70, base.y - 70}, lineThickness, WHITE);
    }
    if (attempts <= 1) {
        // Left Leg (thicker)
        DrawLineEx((Vector2){base.x + 50, base.y - 50}, (Vector2){base.x + 30, base.y - 20}, lineThickness, WHITE);
    }
    if (attempts == 0) {
        // Right Leg (thicker)
        DrawLineEx((Vector2){base.x + 50, base.y - 50}, (Vector2){base.x + 70, base.y - 20}, lineThickness, WHITE);
    }
}
void showWelcomeScreen() {
    Texture2D bg = LoadTexture("HMBG.png"); // Load background image
    
    while (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Scale and draw background image to fit the screen
        Vector2 scale = {(float)GetScreenWidth() / bg.width, (float)GetScreenHeight() / bg.height};
        DrawTextureEx(bg, (Vector2){0, 0}, 0.0f, scale.x, WHITE);
        
        // Display welcome message
        const char* message = "Welcome to Hangman!";
        const char* instruction = "Click anywhere to start.";
        int messageWidth = MeasureText(message, 40);
        int instructionWidth = MeasureText(instruction, 30);
        
        DrawText(message, (GetScreenWidth() - messageWidth) / 2, GetScreenHeight() / 2 - 40, 40, WHITE);
        DrawText(instruction, (GetScreenWidth() - instructionWidth) / 2, GetScreenHeight() / 2 + 10, 30, WHITE);
        
        EndDrawing();
    }
    
    UnloadTexture(bg); // Unload background texture after the welcome screen
}


void displayWord(const char *word, int *found, int length) {
    Vector2 position = {200, 400};
    char display[100] = {0};
    int j;

    for (j = 0; j < length; j++) {
        display[j * 2] = found[j] ? word[j] : '_';
        display[j * 2 + 1] = ' ';
    }
    DrawText(display, position.x, position.y, 40, WHITE);
}

int isComplete(int *found, int length) {
    for (int j = 0; j < length; j++) {
        if (!found[j]) return 0;
    }
    return 1;
}

void chooseGenre(GameItem** selectedGenre, int* numItems) {
    int genreChoice = 0;
    Texture2D bg = LoadTexture("HMBG.png"); // Load background image
    
    // Get screen width and height for centering the buttons
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    
    // Define button sizes
    int buttonWidth = 200;
    int buttonHeight = 50;
    
    // Calculate the x and y positions to center the buttons
    Rectangle countryBtn = {screenWidth / 2 - buttonWidth / 2, screenHeight / 2 - buttonHeight / 2 - 75, buttonWidth, buttonHeight}; // "Countries" button
    Rectangle animalBtn = {screenWidth / 2 - buttonWidth / 2, screenHeight / 2 - buttonHeight / 2 - 25, buttonWidth, buttonHeight};  // "Animals" button
    Rectangle movieBtn = {screenWidth / 2 - buttonWidth / 2, screenHeight / 2 - buttonHeight / 2 + 25, buttonWidth, buttonHeight};   // "Movies" button
    Rectangle gameBtn = {screenWidth / 2 - buttonWidth / 2, screenHeight / 2 - buttonHeight / 2 + 75, buttonWidth, buttonHeight};    // "Games" button

    while (genreChoice == 0) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Scale and draw background image to fit the screen
        Vector2 scale = {(float)screenWidth / bg.width, (float)screenHeight / bg.height};
        DrawTextureEx(bg, (Vector2){0, 0}, 0.0f, scale.x, WHITE);

        // Draw genre buttons
        DrawRectangleRec(countryBtn, WHITE);
        DrawText("1. Countries", countryBtn.x + 20, countryBtn.y + 15, 20, BLACK);
        
        DrawRectangleRec(animalBtn, WHITE);
        DrawText("2. Animals", animalBtn.x + 20, animalBtn.y + 15, 20, BLACK);
        
        DrawRectangleRec(movieBtn, WHITE);
        DrawText("3. Movies", movieBtn.x + 20, movieBtn.y + 15, 20, BLACK);

        DrawRectangleRec(gameBtn, WHITE);
        DrawText("4. Games", gameBtn.x + 20, gameBtn.y + 15, 20, BLACK);

        // Check if the mouse is hovering over any of the genre buttons
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, countryBtn)) {
            DrawRectangleRec(countryBtn, GRAY); // Highlight button on hover
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                *selectedGenre = countries;
                *numItems = numCountries;
                genreChoice = 1;
            }
        }
        if (CheckCollisionPointRec(mousePoint, animalBtn)) {
            DrawRectangleRec(animalBtn, GRAY); // Highlight button on hover
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                *selectedGenre = animals;
                *numItems = numAnimals;
                genreChoice = 2;
            }
        }
        if (CheckCollisionPointRec(mousePoint, movieBtn)) {
            DrawRectangleRec(movieBtn, GRAY); // Highlight button on hover
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                *selectedGenre = movies;
                *numItems = numMovies;
                genreChoice = 3;
            }
        }
        if (CheckCollisionPointRec(mousePoint, gameBtn)) {
            DrawRectangleRec(gameBtn, GRAY); // Highlight button on hover
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                *selectedGenre = games;
                *numItems = numGames;
                genreChoice = 4;
            }
        }

        EndDrawing();
    }

    UnloadTexture(bg); // Unload the background image after genre selection
}


int main() {
    InitWindow(800, 600, "Hangman Game");
    SetTargetFPS(60);
    showWelcomeScreen(); // Call the welcome screen function

    // Load background image
    Texture2D bg = LoadTexture("HMBG.png");

    char playAgain = 'Y';
    while (playAgain == 'Y') {
        GameItem* selectedGenre = NULL;
        int numItems = 0;
        chooseGenre(&selectedGenre, &numItems);

        srand(time(NULL));
        int randomIndex = rand() % numItems;

        const char *word = selectedGenre[randomIndex].word;
        const char *hint = selectedGenre[randomIndex].hint;
        int length = strlen(word);
        int found[100] = {0};
        int attempts = 6;
        char guessedLetter = '\0';
        int gameOver = 0;
        int win = 0;

        // Game loop
        while (!WindowShouldClose() && attempts > 0 && !gameOver) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            // Scale and draw background image to fit the screen
            Vector2 scale = {(float)GetScreenWidth() / bg.width, (float)GetScreenHeight() / bg.height};
            DrawTextureEx(bg, (Vector2){0, 0}, 0.0f, scale.x, WHITE);

            DrawText("HANGMAN GAME", 20, 20, 30, WHITE);
            DrawText(TextFormat("Hint: %s", hint), 20, 80, 20, WHITE);
            DrawText(TextFormat("Attempts left: %d", attempts), 20, 120, 20, WHITE);

            displayWord(word, found, length);

            for (int key = KEY_A; key <= KEY_Z; key++) {
                if (IsKeyPressed(key)) {
                    guessedLetter = (char)(key - KEY_A + 'A');
                    break;
                }
            }

            if (guessedLetter != '\0') {
                int letterFound = 0;

                for (int j = 0; j < length; j++) {
                    if (toupper(word[j]) == guessedLetter) {
                        found[j] = 1;
                        letterFound = 1;
                    }
                }
                if (!letterFound) attempts--;
                guessedLetter = '\0';

                if (isComplete(found, length)) {
                    gameOver = 1;
                    win = 1;
                }
            }

            displayHangman(attempts);

            if (attempts == 0 && !win) {
                DrawText("You lost!", 200, 500, 30, WHITE);
                DrawText(TextFormat("The word was: %s", word), 200, 540, 30, WHITE);
                gameOver = 1;
            } else if (win) {
                DrawText("Congratulations! You guessed the word!", 200, 500, 30, WHITE);
            }

            EndDrawing();
        }

           // Display "Play Again" button and win/loss message
        while (gameOver) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            // Scale and draw background image again to fit the screen
            Vector2 scale = {(float)GetScreenWidth() / bg.width, (float)GetScreenHeight() / bg.height};
            DrawTextureEx(bg, (Vector2){0, 0}, 0.0f, scale.x, WHITE);

            // Calculate the width of the win/loss message
            const char* message = win ? "Congratulations, you won!" : "You lost!";
            const char* wordMessage = TextFormat("The word was: %s", word);
            int messageWidth = MeasureText(message, 30);
            int wordMessageWidth = MeasureText(wordMessage, 30);

            // Calculate x and y to center the text
            int messageX = (GetScreenWidth() - messageWidth) / 2;
            int messageY = GetScreenHeight() / 2 - 50;  // Position above word message
            int wordMessageX = (GetScreenWidth() - wordMessageWidth) / 2;
            int wordMessageY = GetScreenHeight() / 2 + 10; // Position below win/loss message

            // Draw centered win/loss message
            DrawText(message, messageX, messageY, 30, WHITE);
            DrawText(wordMessage, wordMessageX, wordMessageY, 30, WHITE);

            // Draw "Play Again" button
            Rectangle playAgainBtn = {GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 100, 200, 50};
            DrawRectangleRec(playAgainBtn, WHITE);
            DrawText("Play Again", playAgainBtn.x + 20, playAgainBtn.y + 15, 20, BLACK);

            // Check if the mouse is hovering over the "Play Again" button
            Vector2 mousePoint = GetMousePosition();
            if (CheckCollisionPointRec(mousePoint, playAgainBtn)) {
                DrawRectangleRec(playAgainBtn, GRAY); // Highlight button on hover
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    playAgain = 'Y'; // Set 'Y' to restart the game
                    gameOver = 0; // Restart the game loop
                }
            }

            EndDrawing();
        }


        if (playAgain != 'Y') break;
    }

    // Unload background texture
    UnloadTexture(bg);

    CloseWindow();
    
    return 0;
}