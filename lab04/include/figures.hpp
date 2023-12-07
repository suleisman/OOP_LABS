#pragma once

#include <memory>

#include "figure.hpp"
#include "triangle.hpp"
#include "octagon.hpp"
#include "square.hpp"

template <class T>
class Figures {
public:
    Figures() : size(0), figures(nullptr) {}

    Figures(const size_t &n, unsigned char t) {
        figures = std::make_unique<std::unique_ptr<Figure<T> >[]>(n);
        for (size_t i = 0; i < n; ++i) {
            figures[i] = nullptr;
        }
        this->size = n;
    }

    Figures(std::initializer_list<unsigned char> &t, size_t flag) {
        this->size = t.size();
        figures = std::make_unique<std::unique_ptr<Figure<T> >[]>(this->size);
        size_t i = 0;
        for (const unsigned char &c : t) {
            if (flag == 1) {
                figures[i] = std::make_unique<Octagon<T>>();
            } else if (flag == 2) {
                figures[i] = std::make_unique<Square<T>>();
            } else if (flag == 3) {
                figures[i] = std::make_unique<Triangle<T>>();
            }
            ++i;
        }
    }

    size_t getSize() const {
        return this->size;
    }

    void addFigure(std::unique_ptr< Figure<T> > figure) {
        auto newFigures = std::make_unique<std::unique_ptr<Figure<T>>[]>(size + 1);
        for (size_t i = 0; i < this->size; ++i) {
            newFigures[i] = std::move(this->figures[i]);
        }
        newFigures[this->size] = std::move(this->figure);
        this->figures = std::move(newFigures);
        ++this->size;
    }

    void deleteFigure(size_t ind) {
        if (ind < this->size) {
            this->figures[ind].reset();
            for (size_t i = 0; i < this->size - 1; ++i) {
                this->figures[i] = std::move(this->figures[i + 1]);
            }
            --this->size;
        }
        else {
            throw std::logic_error("Array out of bounds");
        }
    }

    std::unique_ptr< Figure<T> > getFigure(size_t ind) {
        if (ind < this->size) {
            return std::move(figures[ind]);
        }
        return nullptr;
    }

private:
    size_t size;
    std::unique_ptr<std::unique_ptr<Figure<T> >[] > figures;
};