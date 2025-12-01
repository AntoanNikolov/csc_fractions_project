#include <string>
struct Time
{
    int hours, minutes, seconds;

    Time(); // constructor
    std::string to_string();
};