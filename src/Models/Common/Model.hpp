#ifndef LINAL_OPDRACHTEN_IMODEL_HPP
#define LINAL_OPDRACHTEN_IMODEL_HPP

#include "FriendOperators.hpp"
#include "Stringable.hpp"

namespace linal::models::common
{
    template<class T>
    class Model : public FriendOperators<T>, public Stringable
    {

    };
}

#endif //LINAL_OPDRACHTEN_IMODEL_HPP
