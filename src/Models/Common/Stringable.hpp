#ifndef LINAL_ASSESSMENT_STRINGABLE_HPP
#define LINAL_ASSESSMENT_STRINGABLE_HPP

#include <string>

namespace linal::models::common
{
    class Stringable
    {
        public:
            [[nodiscard]] virtual std::string ToString() const = 0;
    };
}

#endif //LINAL_ASSESSMENT_STRINGABLE_HPP
