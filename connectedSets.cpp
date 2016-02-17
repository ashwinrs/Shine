/*
    Connected Sets / Number of Islands in a 2D array

    problem explained in http://www.geeksforgeeks.org/find-number-of-islands/

    Give both iterative and recursive solution
*/

#include <iostream>
#include <vector>

using namespace std;

#define COL 5
#define ROW 5

bool isValid(int i, int j){
    if(i < ROW && i >= 0 && j < COL && j >= 0)
        return true;
    return false;
}

//recursive solution. Which explores an unexplored
void exploreLand(int arr[][COL],int i, int j){
    //Return
    //if already explored
    //if out of bounds
    //if not a land
    if(arr[i][j] == 2 || !isValid(i,j) || arr[i][j] == 0) return;

    //mark the land explored;
    arr[i][j] = 2;
    exploreLand(arr,i-1,j-1);
    exploreLand(arr,i-1,j);
    exploreLand(arr,i-1,j+1);
    exploreLand(arr,i,j-1);
    exploreLand(arr,i,j+1);
    exploreLand(arr,i+1,j-1);
    exploreLand(arr,i+1,j);
    exploreLand(arr,i+1,j+1);

}

int connectedSetsIter(int arr[][COL]){
    int result = 0;

    for(int i = 0; i < ROW ; i++){
        for(int j = 0; j < COL; j++){
            if(arr[i][j] == 1){
                //go explore the land
                exploreLand(arr,i,j);
                result++;
            }
        }
    }

return result;
}


int main(){
    int arr[][COL] ={
    {0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}};
    cout << connectedSetsIter(arr) << endl;

    for(int i = 0; i < ROW ; i++){
        for(int j = 0; j < COL; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return -1;
}
