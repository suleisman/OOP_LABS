#pragma once

#include <functional>
#include "include/allocator.hpp"
#include "include/iterator.hpp"
#include "include/const_iterator.hpp"

template <class T, class Allocator = std::allocator<T> >
class List {
private:
    struct Node;
    using NodeAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
    using NodePointer = std::unique_ptr<Node, std::function<void(Node*)> >;
    struct Node {
        NodePointer next;
        T data;
        Node(const T &item) : data(item), next(nullptr) {}
    };
    NodePointer head;
    Node *tail;
    size_t size;

public:
    using iterator = Iterator<Node, T>;
    using const_iterator = const_iterators::ConstIterator<Node, T>;

    List() : size(0), head(nullptr, NodeDelete{nullptr}), tail(nullptr) {}

    void PushBack(const T& item) {
        Node* node = allocateNode(item);
        if (size == 0) {
            head = NodePointer(node, NodeDelete{&nodeAllocator});
            tail = head.get();
        } else {
            tail->next = NodePointer(node, NodeDelete{&nodeAllocator});
            tail = node;
        }
        ++size;
    }

    void PushFront(const T& item) {
        Node* node = allocateNode(item);
        node->next = std::move(head);
        head = NodePointer(node, NodeDelete{&nodeAllocator});
        if (size == 0) {
            tail = head.get();
        }
        ++size;
    }

    void PopBack() {
        if (size == 0) {
            throw std::logic_error("List is empty");
        }
        if (head.get() == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node *node = head.get();
            for (; (node->next).get() != tail; node = (node->next).get());
            tail = node;
            tail->next = nullptr;
        }
        --size;
    }
    
    void PopFront() {
        if (size == 0) {
            throw std::logic_error("List is empty");
        }
        head = std::move(head->next);
        if (head.get() == nullptr) {
            tail = nullptr;
        }
        --size;
    }

    T& Head() {
        if (size == 0) {
            throw std::logic_error("List is empty");
        }
        return head->data;
    }

    T& Tail() {
        if (size == 0) {
            throw std::logic_error("List is empty");
        }
        return tail->data;
    }

    void Insert(iterator pos, const T& item) {
        if (pos == this->begin()) {
            this->PushFront(item);
        } else {
            Node *prevNode = head.get(); 
            for (; (prevNode->next).get() <= pos.get(); prevNode = (prevNode->next).get());
            Node* newNode = allocateNode(item);
            newNode->next = std::move(prevNode->next);
            prevNode->next = NodePointer(newNode, NodeDelete{&nodeAllocator});
            ++size;
        }
    }

    void Erase(iterator pos) {
        if (pos == this->end()) {
            throw std::logic_error("Try to erase the end iterator");
        } else if (pos == this->begin()) {
            this->PopFront();
        } else if (pos.get() == tail) {
            this->PopBack();
        } else {
            Node *prevNode = head.get();
            for (; (prevNode->next).get() <= pos.get(); prevNode = (prevNode->next).get());
            prevNode->next = std::move((pos.get())->next);
            --size;
        }
    }

    bool IsEmpty() {
        return size == 0;
    }

    int Size() {
        return size;
    }

    void Clear() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    iterator begin() const {
        return iterator(head.get());
    }

    iterator end() const {
        return iterator(nullptr);
    }

    const_iterator cbegin() const {
        return const_iterator(head.get());
    }

    const_iterator cend() const {
        return const_iterator(nullptr);
    }

private:
    NodeAllocator nodeAllocator;

    struct NodeDelete {
        NodeAllocator* allocator;

        void operator()(Node* ptr) const {
            if (ptr != nullptr) {
                std::allocator_traits<NodeAllocator>::destroy(*allocator, ptr);
                allocator->deallocate(ptr, 1);
            }
        }
    };

    Node* allocateNode(const T& item) {
        Node* node = nodeAllocator.allocate(1);
        std::allocator_traits<NodeAllocator>::construct(nodeAllocator, node, item);
        return node;
    }

};