#ifndef LINAL_ASSESSMENT_COLOR_HPP
#define LINAL_ASSESSMENT_COLOR_HPP

namespace linal::engine
{
    class Color
    {
        private:
            double r;
            double g;
            double b;
            double a;

            static Color _white;
            static Color _red;
            static Color _green;
            static Color _blue;
            static Color _cyan;
            static Color _magenta;
            static Color _yellow;
            static Color _black;
            static Color _purple;
            static Color _lime;
            static Color _orange;
            static Color _transparent;

        public:
            Color(double red, double green, double blue) : r{red}, g{green}, b{blue}, a{255}
            {
            }

            Color(double red, double green, double blue, double alpha) : r{red}, g{green}, b{blue}, a{alpha}
            {
            }

            [[nodiscard]] double R() const
            {
                return r;
            }

            [[nodiscard]] double G() const
            {
                return g;
            }

            [[nodiscard]] double B() const
            {
                return b;
            }

            [[nodiscard]] double A() const
            {
                return a;
            }

            static const Color& white()
            {
                return _white;
            }

            static const Color& red()
            {
                return _red;
            }

            static const Color& green()
            {
                return _green;
            }

            static const Color& blue()
            {
                return _blue;
            }

            static const Color& cyan()
            {
                return _cyan;
            }

            static const Color& magenta()
            {
                return _magenta;
            }

            static const Color& yellow()
            {
                return _yellow;
            }

            static const Color& black()
            {
                return _black;
            }

            static const Color& purple()
            {
                return _purple;
            }

            static const Color& lime()
            {
                return _lime;
            }

            static const Color& orange()
            {
                return _orange;
            }

            static const Color& transparent()
            {
                return _transparent;
            }
    };
}

#endif //LINAL_ASSESSMENT_COLOR_HPP
