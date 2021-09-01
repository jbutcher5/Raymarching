echo "Compiling..."
g++ -w -std=c++17 -lraylib -lGL -lm -pthread -ldl -g ./src/*.cpp -o main
echo "Compiled!"
