/** Attribution: Code adapted from "enum to string in modern C++11 / C++14 / C++17 and future C++20"
https://stackoverflow.com/questions/28828957/enum-to-string-in-modern-c11-c14-c17-and-future-c20
**/

#include <iostream>
#include <map>
#include <string>

// example enum class with seasons as members
enum class Season
{
    Spring = 1,
    Summer = 2,
    Autumn = 3,
    Winter = 4
};

std::string printEnumMember(Season my_season)
{
    const std::map<Season, const char *> SeasonStrings{
        {Season::Spring, "Spring"},
        {Season::Summer, "Summer"},
        {Season::Autumn, "Autumn"},
        {Season::Winter, "Winter"}
        };
    // auto: variable declaration for a complicated types e.g. pointers to members
    auto season_string = SeasonStrings.find(my_season);
    return season_string == SeasonStrings.end() ? "Out of range?" : season_string->second;
}

int main()
{   
    Season current_season = Season::Autumn; 
    std::cout << "Current season: " << printEnumMember(current_season) << std::endl;
    return 0;
}