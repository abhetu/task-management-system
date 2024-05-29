#include "Utils.h"
#include <iomanip>
#include <sstream>

std::time_t stringToTime(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream ss(timeStr);
    ss >> std::get_time(&tm, "%Y-%m
