#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Possible movement directions: up, down, left, right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// BFS function to find the shortest path in a maze
int shortestPathInMaze(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> destination) {
    int rows = maze.size();
    int cols = maze[0].size();

    // Check if start or destination is blocked
    if (maze[start.first][start.second] == 1 || maze[destination.first][destination.second] == 1) {
        return -1;
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(rows, vector<int>(cols, -1)); // Stores distance from start

    // Initialize BFS
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // If we reached the destination, return the shortest path length
        if (x == destination.first && y == destination.second) {
            return dist[x][y];
        }

        // Explore 4 possible movements
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check boundaries and if the cell is open and not visited
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && maze[nx][ny] == 0 && dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1; // Update distance
            }
        }
    }
    return -1; // No path found
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> maze(rows, vector<int>(cols));
    cout << "Enter the maze matrix (0 for open, 1 for wall):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    pair<int, int> start, destination;
    cout << "Enter start coordinates (row col): ";
    cin >> start.first >> start.second;
    cout << "Enter destination coordinates (row col): ";
    cin >> destination.first >> destination.second;

    int result = shortestPathInMaze(maze, start, destination);

    if (result != -1)
        cout << "Shortest path length: " << result << endl;
    else
        cout << "No valid path exists!" << endl;

    return 0;
}

