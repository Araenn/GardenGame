#include "testObjects.h"

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>> &matrix) {
    for (int i = 0; i < 5; i++) {
        cout << "["; 
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main(int argc, char *argv[]) {

    vector<vector<int>> matrix;

    for (int i = 0; i < 5; i++) {
        vector<int> line;
        for (int j = 0; j < 5; j++) {
            line.push_back(j);
        }
        matrix.push_back(line);
    }

    printMatrix(matrix);

    matrix[2][4] = 12;

    printMatrix(matrix);


    return 0;
}