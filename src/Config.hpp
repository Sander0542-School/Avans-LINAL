#ifndef LINAL_ASSESSMENT_CONFIG_HPP
#define LINAL_ASSESSMENT_CONFIG_HPP


namespace linal
{
    class Config
    {
        private:
            Config() : DebugMode(false)
            {
            }

        public:
            Config(Config const&) = delete;

            void operator=(Config const&) = delete;

            static Config& Instance()
            {
                static Config instance;
                return instance;
            }

            bool DebugMode;
    };
}

#endif //LINAL_ASSESSMENT_CONFIG_HPP
