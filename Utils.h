#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <ctime>

std::time_t stringToTime(const std::string& timeStr);
std::string timeToString(std::time_t time);

#endif // UTILS_H
