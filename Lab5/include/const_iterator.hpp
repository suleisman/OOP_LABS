#pragma once

#include <memory>
#include <iterator>

namespace const_iterators {
    
    template <class Node, class T>
    class ConstIterator {
    private:
        const Node* node;

    public:
        using value_type = const T;
        using reference = const T&;
        using pointer = const T*;
        using difference_type = std::ptrdiff_t;
        using Iterator_category = std::forward_iterator_tag;

        explicit ConstIterator(Node* ptr) : node(ptr) {}

        reference operator*() const {
            if (node == nullptr) {
                throw std::out_of_range("Iterator dereference out of bounds");
            }
            return node->value;
        }

        pointer operator->() const {
            if (node == nullptr) {
                throw std::out_of_range("Iterator dereference out of bounds");
            }
            return &node->value; 
        }

        ConstIterator& operator++() {
            if (node == nullptr) {
                throw std::out_of_range("Iterator out of bounds");
            }
            node = node->next.get();
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const ConstIterator& other) const {
            return node == other.node;
        }

        bool operator!=(const ConstIterator& other) const {
            return node != other.node;
        }
    };
};