#pragma once

#ifndef UTIL_HPP_GLCNLISE
#define UTIL_HPP_GLCNLISE

#include <string>
#include <vector>

namespace WebWx {
    namespace Util {

        std::uint64_t GetUtcMilli();

        std::vector<std::string> split(const std::string &s, char delim);

        std::string& RemoveSpaces(std::string& s);

        int GetIntAfterTheLastEqual(const std::string& s);

        std::string UrlEncode(const std::string& value);
    }
}

#endif /* end of include guard: UTIL_HPP_GLCNLISE */
