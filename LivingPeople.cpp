/*
Problem Type - Two array if else method

Problem from - Cracking the coding interview. Moderate 16.10

Living People: Given an array of people with birth year and death year, find the max number of year the people were alive.

algorithm: sort the birth year and death year. Add 1 when a birth happens, subtract 1 when a death happens.
           Run time = O(P log P) where P is the array of people

Command to run - g++ -std=c++11 LivingPeople.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class People{
public:
    unsigned int birth_year;
    unsigned int death_year;

    People(unsigned int birth_year, unsigned int death_year){
        this->birth_year = birth_year;
        this->death_year = death_year;
    }
};

bool less_than_birth_year(const People& people1, const People& people2){
    return (people1.birth_year < people2.birth_year);
}

bool less_than_death_year (const People& people1, const People& people2){
    return (people1.death_year < people2.death_year);
}

class Solution{
        vector<unsigned int> getArray(vector<People> people, bool isBirth){
            vector<unsigned int> result;

            result.reserve(people.size());

            if(isBirth){
                //use transform with lambda function
                transform(people.begin(), people.end(), back_inserter(result),[](const People& p) { return p.birth_year; });
            }else{
                //use transform with lambda function
                transform(people.begin(), people.end(), back_inserter(result),[](const People& p) { return p.death_year; });
            }
            return result;
        }
public:
        int getYearWithMaxPeopleAlive(vector<People> people){
            sort(people.begin(), people.end(), less_than_birth_year);
            vector<unsigned int> sorted_by_birth = getArray(people, true);

            sort(people.begin(), people.end(), less_than_death_year);
            vector<unsigned int> sorted_by_death = getArray(people,false);

            int max_people_alive = 0;
            int max_people_alive_year = 0;
            int running_max_people_alive = 0;
            int birth_year_index = 0;
            int death_year_index = 0;

            //write the crux here
            while( birth_year_index < sorted_by_birth.size()){
                if(sorted_by_birth[birth_year_index] <= sorted_by_death[death_year_index]){
                    running_max_people_alive++;

                    if(running_max_people_alive > max_people_alive){
                        max_people_alive = running_max_people_alive;
                        max_people_alive_year = sorted_by_birth[birth_year_index];
                    }

                    birth_year_index++;
                }else{
                    running_max_people_alive--;
                    death_year_index++;
                }
            }
            return max_people_alive_year;
        }
};

int main(){
    vector<People> peoples;
    peoples.push_back(People(9,76));
    peoples.push_back(People(23,66));
    peoples.push_back(People(13,93));

    Solution s;

    cout << "Year with max people alive "<< s.getYearWithMaxPeopleAlive(peoples) << endl;

}
