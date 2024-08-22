#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int NUM_CITIES = 5;
const int INF = 1e9;


string cityNames[NUM_CITIES] = {
    "Toronto", "Mississauga", "Markham", "Brampton", "Etobicoke"
};


int distances[NUM_CITIES][NUM_CITIES] = {
    {0, 25, 30, 20, 35},
    {25, 0, 40, 15, 30},
    {30, 40, 0, 45, 20},
    {20, 15, 45, 0, 40},
    {35, 30, 20, 40, 0}
};


int calculateTotalDistance(const vector<int>& path) {
    int totalDistance = 0;
    for (int i = 0; i < NUM_CITIES - 1; ++i) {
        totalDistance += distances[path[i]][path[i + 1]];
    }

    totalDistance += distances[path[NUM_CITIES - 1]][path[0]];
    return totalDistance;
}

int main() {
    vector<int> cities;
    for (int i = 1; i < NUM_CITIES; ++i) {
        cities.push_back(i);
    }

    vector<int> shortestPath;
    int minDistance = INF;

    cout << "All Permutations:" << endl;
    do {
        vector<int> path = {0};
        path.insert(path.end(), cities.begin(), cities.end());
        int totalDistance = calculateTotalDistance(path);
        if (totalDistance < minDistance) {
            minDistance = totalDistance;
            shortestPath = path;
        }

        cout << cityNames[0] << " -> ";
        for (int city : cities) {
            cout << cityNames[city] << " -> ";
        }
        cout << cityNames[0] << ", Total Distance: " << totalDistance << " km" << endl;
    } while (next_permutation(cities.begin(), cities.end()));

    cout << "\nShortest path: " << cityNames[0] << " -> ";
    for (int city : shortestPath) {
        cout << cityNames[city] << " -> ";
    }
    cout << cityNames[0] << endl;
    cout << "Total distance: " << minDistance << " km" << endl;

    return 0;
}
