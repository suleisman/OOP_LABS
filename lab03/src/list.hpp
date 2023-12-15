#pragma once

#include "figure.hpp"
#include "triangle.hpp"
#include "octagon.hpp"
#include "square.hpp"

class Figures {
    public:
        Figures();
        size_t getSize() const;

        Figures(const size_t &n, unsigned char t);
        Figures(const std::initializer_list<unsigned char> &t, size_t flag);

        void addFigure(Figure *figure);
        void deleteFigure(size_t ind);
        Figure* getFigure(size_t ind);    

        ~Figures() noexcept;
    private:
        size_t size;
        Figure** figures;
};