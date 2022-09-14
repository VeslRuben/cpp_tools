

// maze generator
// 1. generate a maze with a random algorithm
// 2. print the maze
// 3. solve the maze
// 4. print the solution

#include "matrix.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

// generate a random maze
Matrix::Matrix2 generate_maze(int height, int width) {
    // create a matrix with all walls
    Matrix::Matrix2 maze = Matrix::zeros(height, width);

    // create a random number generator
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(0, 1);

    for (int row = 1; row < height - 1; row += 2) {
        for (int col = 1; col < width - 1; col += 2) {
            maze(row, col) = 1;
        }
    }

    for (int row = 2; row < height - 2; row += 2) {
        for (int col = 2; col < width - 2; col += 2) {
            maze(row, col) = -1;
        }
    }

    // create start and end points
    maze(0, 1) = 1;
    maze(height - 1, width - 2) = 1;

    // traverse the maze and create a random path
    std::vector<int> row_stack;
    std::vector<int> col_stack;
    int row = 1;
    int col = 1;
    maze(row, col) = 1;
    while (true) {
        std::vector<int> neighbors;
        if (row > 2 && maze(row - 1, col) == 0) {
            neighbors.push_back(0);
        }
        if (row < height - 3 && maze(row + 1, col) == 0) {
            neighbors.push_back(1);
        }
        if (col > 2 && maze(row, col - 1) == 0) {
            neighbors.push_back(2);
        }
        if (col < width - 3 && maze(row, col + 1) == 0) {
            neighbors.push_back(3);
        }

        if (neighbors.size() > 0) {
            //int direction = neighbors[distribution(generator) % neighbors.size()];
            // shuffle the neighbors
            std::shuffle(neighbors.begin(), neighbors.end(), generator);
            for (int i = 0; i < neighbors.size(); i++) {
                int direction = neighbors[i];
                // value random number between 0 and -1
                int value = distribution(generator) * 2 - 1;
                if (i == 0) {
                    value = 1;
                }
                if (direction == 0) {
                    maze(row - 1, col) = value;
                    row = i == 0 ? row - 2 : row;
                } else if (direction == 1) {
                    maze(row + 1, col) = value;
                    row = i == 0 ? row + 2 : row;
                } else if (direction == 2) {
                    maze(row, col - 1) = value;
                    col = i == 0 ? col - 2 : col;
                } else if (direction == 3) {
                    maze(row, col + 1) = value;
                    col = i == 0 ? col + 2 : col;
                }
                maze(row, col) = 1;
                row_stack.push_back(row);
                col_stack.push_back(col);
            }
        } else if (row_stack.size() > 0) {
            row = row_stack.back();
            row_stack.pop_back();
            col = col_stack.back();
            col_stack.pop_back();
        } else {
            break;
        }
    }

    return maze;
}

// print the maze
void print_maze(Matrix::Matrix2 maze) {
    for (int i = 0; i < maze.getHeight(); i++) {
        for (int j = 0; j < maze.getWidth(); j++) {
            if (maze.get(i, j) == 1) {
                std::cout << "██";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

// solve the maze
Matrix::Matrix2 solve_maze(Matrix::Matrix2 maze) {
    std::vector<int> directions = {0, 1, 2, 3};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(directions.begin(), directions.end(), g);
    int x = 1;
    int y = 1;
    maze.put(2, x, y);
    while (x != maze.getHeight() - 2 || y != maze.getWidth() - 2) {
        int direction = directions.back();
        directions.pop_back();
        if (direction == 0 && x > 1 && maze.get(x - 1, y) == 0) {
            maze.put(2, x - 1, y);
            x -= 1;
        } else if (direction == 1 && y < maze.getWidth() - 2 && maze.get(x, y + 1) == 0) {
            maze.put(2, x, y + 1);
            y += 1;
        } else if (direction == 2 && x < maze.getHeight() - 2 && maze.get(x + 1, y) == 0) {
            maze.put(2, x + 1, y);
            x += 1;
        } else if (direction == 3 && y > 1 && maze.get(x, y - 1) == 0) {
            maze.put(2, x, y - 1);
            y -= 1;
        }
        if (directions.empty()) {
            directions = {0, 1, 2, 3};
            std::shuffle(directions.begin(), directions.end(), g);
        }
    }
    return maze;
}

// print the solution
void print_solution(Matrix::Matrix2 maze) {
    for (int i = 0; i < maze.getHeight(); i++) {
        for (int j = 0; j < maze.getWidth(); j++) {
            if (maze.get(i, j) == 1) {
                std::cout << "██";
            } else if (maze.get(i, j) == 2) {
                std::cout << "  ";
            } else {
                std::cout << "░░";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    Matrix::Matrix2 maze = generate_maze(17, 13);
    print_maze(maze);
    std::cout << std::endl;
    //Matrix::Matrix2 solution = solve_maze(maze);
    //print_solution(solution);
    return 0;
}