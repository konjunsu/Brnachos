mkdir out
cp -f ./img/*.* out/
cp -f ./fonts/*.* out/
g++ ./src/Choices.cpp ./src/GameObject.cpp ./src/GameText.cpp ./src/Projectile.cpp ./src/main.cpp ./src/functions.cpp ./src/worlds.cpp -o ./out/test2 -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -m32

