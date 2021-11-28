#ifndef LINAL_ASSESSMENT_DEBUG_HPP
#define LINAL_ASSESSMENT_DEBUG_HPP

#include <iostream>

namespace linal::engine
{
    namespace Debug
    {
        void Log(const std::string& message, const std::string& caller = __builtin_FUNCTION(), const std::string& file = __builtin_FILE(), int line = __builtin_LINE())
        {
            std::cout << "INFO | " << caller << " | " << file << ":" << line << " | " << message << "\n";
        }

        void LogError(const std::string& error, const std::string& caller = __builtin_FUNCTION(), const std::string& file = __builtin_FILE(), int line = __builtin_LINE())
        {
            std::cerr << "ERROR | " << caller << " | " << file << ":" << line << " | " << error << std::endl;
        }

        void LogWarning(const std::string& warning, const std::string& caller = __builtin_FUNCTION(), const std::string& file = __builtin_FILE(), int line = __builtin_LINE())
        {
            std::cerr << "WARNING | " << caller << " | " << file << ":" << line << " | " << warning << std::endl;
        }
    }
}

#endif //LINAL_ASSESSMENT_DEBUG_HPP
