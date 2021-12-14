#ifndef LINAL_OPDRACHTEN_IUPDATABLE_HPP
#define LINAL_OPDRACHTEN_IUPDATABLE_HPP

#include "Engine/Window.hpp"
#include "Models/Models.hpp"

namespace linal::entities::common
{
    class IUpdatable
    {
        public:
            virtual void OnUpdate() = 0;
    };
}

#endif //LINAL_OPDRACHTEN_IUPDATABLE_HPP
