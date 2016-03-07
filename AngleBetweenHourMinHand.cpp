#include <iostream>

using namespace std;

int getAngleBetweenHourAndMinuteHand(int hour, int minute){

    if(hour > 23 || hour < 0) return -1;

    if(minute < 0 || minute > 59) return -1;

    int minuteAngle = 360 * (minute/60);
    int hourAngle = (360 *((hour%12)/12))+((360/12)*(minute/60));

    int diff = abs(minuteAngle-hourAngle);
    return min(360-diff,diff);
}


int main(){
    cout << endl << getAngleBetweenHourAndMinuteHand(12,00);
}
