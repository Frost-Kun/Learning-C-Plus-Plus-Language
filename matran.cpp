#include<bits/stdc++.h>

using namespace std;
void rotateLayer(vector<vector<int>>& matrix, int layer, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> layerElements;
    for (int j = layer; j < cols - layer; ++j) 
        layerElements.push_back(matrix[layer][j]);
    for (int i = layer + 1; i < rows - layer; ++i) 
        layerElements.push_back(matrix[i][cols - layer - 1]);
    for (int j = cols - layer - 2; j >= layer; --j) 
        layerElements.push_back(matrix[rows - layer - 1][j]);
    for (int i = rows - layer - 2; i > layer; --i) 
        layerElements.push_back(matrix[i][layer]);

    k = k % layerElements.size();

    // Xoay phần tử trong lớp
    rotate(layerElements.rbegin(), layerElements.rbegin() + k, layerElements.rend());

    // Đưa phần tử trở lại ma trận
    int idx = 0;
    for (int j = layer; j < cols - layer; ++j) 
        matrix[layer][j] = layerElements[idx++];
    for (int i = layer + 1; i < rows - layer; ++i) 
        matrix[i][cols - layer - 1] = layerElements[idx++];
    for (int j = cols - layer - 2; j >= layer; --j) 
        matrix[rows - layer - 1][j] = layerElements[idx++];
    for (int i = rows - layer - 2; i > layer; --i) 
        matrix[i][layer] = layerElements[idx++];
}

// Hàm xoay toàn bộ ma trận
void rotateMatrix(vector<vector<int>>& matrix, vector<int> rotations) {
    int layers = min(matrix.size(), matrix[0].size()) / 2;

    for (int layer = 0; layer < layers; ++layer) {
        rotateLayer(matrix, layer, rotations[layer]);
    }
}

// Hàm in ma trận
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> rotations = {1};

    cout << "Ma trận ban đầu:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix, rotations);

    cout << "Ma trận sau khi xoay:" << endl;
    printMatrix(matrix);

    return 0;
}
