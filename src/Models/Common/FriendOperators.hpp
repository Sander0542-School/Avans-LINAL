#ifndef LINAL_ASSESSMENT_FRIENDOPERATORS_HPP
#define LINAL_ASSESSMENT_FRIENDOPERATORS_HPP

namespace linal::models::common
{
    template<class T>
    class FriendOperators
    {
        public:
            friend T operator+(T lhs, const T& rhs)
            {
                lhs += rhs;
                return lhs;
            }

            friend T operator-(T lhs, const T& rhs)
            {
                lhs -= rhs;
                return lhs;
            }

            template<typename Numeric>
            friend T operator*(T lhs, const Numeric& scalar)
            {
                lhs *= scalar;
                return lhs;
            }
    };
}

#endif //LINAL_ASSESSMENT_FRIENDOPERATORS_HPP
