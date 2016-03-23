#include <cctype>
#include <chrono>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

#include "util.hpp"

using namespace WebWx::Util;

std::uint64_t GetUtcMilli()
{
    return std::chrono::duration_cast< std::chrono::milliseconds > ( std::chrono::system_clock::now().time_since_epoch()).count();
}

std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::string& RemoveSpaces(std::string& s)
{
    s.erase(std::remove_if(s.begin(), s.end(), [](char x){return std::isspace(x);}), s.end());
    return s;
}

int GetIntAfterTheLastEqual(const std::string& s)
{
    int last = s.find_last_of("=");
    return std::atoi(s.substr(last + 1, s.size() - last - 1).c_str());
}

std::string UrlEncode(const std::string& value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (auto i = value.cbegin(), n = value.cend(); i != n; ++i) {
        std::string::value_type c = (*i);
        // Keep alphanumeric and other accepted characters intact
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }
        // Any other characters are percent-encoded
        escaped << '%' << std::setw(2) << int((unsigned char) c);
    }

    return escaped.str();
}
