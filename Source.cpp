#include <iostream>
#include <climits>
using namespace std;

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1,  1, -2,  2, -2, 2, -1, 1 };

// Bai 1: in vi tri knight cua (i,j)
void knight_moves(int i, int j, int n, int m) {
    cout << "Cac vi tri knight cua (" << i << "," << j << "):" << endl;
    bool found = false;
    for (int k = 0; k < 8; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
            cout << "  (" << ni << ", " << nj << ")" << endl;
            found = true;
        }
    }
    if (!found) cout << "  Khong co vi tri hop le!" << endl;
}

// Bai 2: tim 2 vi tri knight co tong nho nhat
void min_knight_sum(int A[][100], int n, int m) {
    int minSum = INT_MAX;
    int r1, c1, r2, c2;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
                    int sum = A[i][j] + A[ni][nj];
                    if (sum < minSum) {
                        minSum = sum;
                        r1 = i; c1 = j;
                        r2 = ni; c2 = nj;
                    }
                }
            }

    cout << "Hai vi tri: (" << r1 << "," << c1 << ") va (" << r2 << "," << c2 << ")" << endl;
    cout << "Tong nho nhat: " << minSum << endl;
}

int main() {
    // --- Test case bai 1 ---
    cout << "=== Bai 1: knight_moves ===" << endl;

    // Test 1: vi tri goc (1,1) tren bang 5x5 - chi co 2 nuoc di
    knight_moves(1, 1, 5, 5); // mong doi: (2,3) va (3,2)

    // Test 2: vi tri giua (3,3) tren bang 5x5 - co nhieu nuoc di
    knight_moves(3, 3, 5, 5); // mong doi: 8 nuoc di

    // Test 3: vi tri tren bang nho 2x2 - khong co nuoc di hop le
    knight_moves(1, 1, 2, 2); // mong doi: khong co vi tri hop le

    // --- Test case bai 2 ---
    cout << "\n=== Bai 2: min_knight_sum ===" << endl;

    // Test 1: ma tran 3x3
    int A1[100][100] = {
        {0, 0, 0, 0},
        {0, 1, 2, 3},
        {0, 4, 5, 6},
        {0, 7, 8, 9}
    };
    cout << "Ma tran 3x3:" << endl;
    min_knight_sum(A1, 3, 3); // mong doi: (1,1)+(2,3) = 1+6 = 7

    // Test 2: ma tran 4x4 co so am
    int A2[100][100] = {
        {0,  0,  0,  0,  0},
        {0, -5,  3,  2,  1},
        {0,  4, -3,  6,  0},
        {0,  7,  8, -2,  5},
        {0,  1,  2,  3,  4}
    };
    cout << "Ma tran 4x4 co so am:" << endl;
    min_knight_sum(A2, 4, 4); // mong doi: (-5)+(-2) = -7

    // Test 3: ma tran 5x5
    int A3[100][100] = {
        {0,  0,  0,  0,  0,  0},
        {0,  9,  8,  7,  6,  5},
        {0,  4,  3,  2,  1,  0},
        {0, -1, -2, -3, -4, -5},
        {0,  0,  1,  2,  3,  4},
        {0,  5,  6,  7,  8,  9}
    };
    cout << "Ma tran 5x5:" << endl;
    min_knight_sum(A3, 5, 5); // mong doi: (-5)+(-4) = -9

    return 0;
}