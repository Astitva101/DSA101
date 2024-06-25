#include <iostream>
using namespace std;

// Function to solve Tower of Hanoi and print the moves
int toh(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        cout << "move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        return 1;
    }

    int count1 = toh(n-1, from_rod, aux_rod, to_rod);
    cout << "move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    int count2 = toh(n-1, aux_rod, to_rod, from_rod);

    return count1 + 1 + count2;
}

int main() {
    int n = 3; // number of disks
    int from = 1, to = 3, aux = 2; // rods: 1, 2, 3

    cout << "Total moves: " << toh(n, from, to, aux) << endl;

    return 0;
}
