#include "list.hpp"

Figures::Figures() : size(0), figures{nullptr} {}

size_t Figures::getSize() const {return this->size;}

Figures::Figures(const size_t &n, unsigned char t) {
    this->size = n;
    figures = new Figure*[this->size];
    for (size_t i = 0; i < this->size; ++i) {
        figures[i] = nullptr;
    }
}

Figures::Figures(const std::initializer_list<unsigned char> &t, size_t flag) {
    this->size = t.size();
    figures = new Figure*[this->size];
    size_t i = 0;
    for(const unsigned char &c : t) {
        if (flag == 1) {
            figures[i] = new Octagon();
        } else if (flag == 2) {
            figures[i] = new Square();
        } else if (flag == 3) {
            figures[i] = new Triangle();
        }
        ++i;
    }
}

void Figures::addFigure(Figure* figure) {
    Figure** newFigures = new Figure*[this->size + 1];
    for (size_t i = 0; i < this->size; ++i) {
        newFigures[i] = figures[i];
    }
    newFigures[this->size] = figure;
    delete[] figures;
    figures = newFigures;
    ++this->size;
}

void Figures::deleteFigure(size_t ind) {
    if (ind < this->size) {
        delete figures[ind];
        for (size_t i = 0; i < this->size; ++i) {
            figures[i] = figures[i + 1];
        }
        --this->size;
    } else {
        throw std::logic_error("Out of bounds");
    }
}

Figure* Figures::getFigure(size_t ind) {
    if (ind < this->size) {
        return figures[ind];
    }
    return nullptr;
}

Figures::~Figures() noexcept {
    for (size_t i = 0; i < size; ++i) {
        if (figures[i]) {
            delete figures[i];
            figures[i] = nullptr;
        }
    }
    size = 0;
    delete[] figures;
    figures = nullptr;
}