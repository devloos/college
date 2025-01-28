#ifndef LIST_H_
#define LIST_H_
#include <functional>
#include <iterator>

#include "../utility/Utility.h"

template <typename T>
struct Sentry {
  Sentry* next = nullptr;
  Sentry* prev = nullptr;
  T data;
};

template <typename T>
class List {
 private:
  Sentry<T>* head = nullptr;
  Sentry<T>* tail = nullptr;
  int length = 0;

 public:
  ~List() noexcept {
    this->clear();
  }

 public:
  bool isEmpty() const {
    return this->length <= 0 ? true : false;
  }

  int size() const {
    return this->length;
  }

  void clear() noexcept {
    if (this->isEmpty()) return;

    Sentry<T>* iter = this->head;

    while (iter != nullptr) {
      this->head = iter->next;
      delete iter;
      iter = this->head;
    }

    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert(const T &data) {
    if (this->isEmpty()) {
      this->insertEmpty(data);
      return;
    }

    Sentry<T>* node = new Sentry<T>;

    if (node == nullptr) {
      throw Utility::Exception(
          Utility::Exception::Level::ERROR, "Memory allocation failed");
    }

    node->data = data;

    Sentry<T>* iter = this->head;
    bool inserted = false;

    while (iter != nullptr && !inserted) {
      if (node->data < iter->data) {
        node->next = iter;
        node->prev = iter->prev;
        iter->prev = node;
        // if true we are at front of list
        if (node->prev == nullptr) {
          this->head = node;
        } else {
          node->prev->next = node;
        }

        inserted = true;
      }
      iter = iter->next;
    }

    // if (at end of the list and didnt insert)
    if (!inserted) {
      node->prev = this->tail;
      node->next = nullptr;
      this->tail->next = node;
      this->tail = node;
    }

    node = nullptr;
    this->length++;
    return;
  }

  T peek() const {
    if (this->isEmpty())
      throw Utility::Exception(Utility::Exception::Level::ERROR, "Peeking on empty list");
    return this->head->data;
  }

  T back() const {
    if (this->isEmpty())
      throw Utility::Exception(Utility::Exception::Level::ERROR, "Backing on empty list");
    return this->tail->data;
  }

  Sentry<T>* begin() const {
    return this->head;
  }

  Sentry<T>* end() const {
    return this->tail->next;
  }

  T* find(std::function<bool(const T &data)> func) {
    auto iter = this->begin();
    while (iter != this->end()) {
      if (func(iter->data)) {
        return &iter->data;
      }
      iter = iter->next;
    }
    return nullptr;
  }

  bool remove(std::function<bool(const T &data)> func) {
    auto iter = this->begin();

    auto free = [&](auto &iter) {
      iter->next = nullptr;
      iter->prev = nullptr;
      delete iter;
      iter = nullptr;
      this->length--;
      return true;
    };

    while (iter != this->end()) {
      if (!func(iter->data)) {
        iter = iter->next;
        continue;
      }
      // Just free if length 1
      if (this->length < 1) {
        return free(iter);
      }

      // Front of list
      if (iter == this->head) {
        this->head = iter->next;
        this->head->prev = nullptr;
        // Back of list
      } else if (iter == this->tail) {
        this->tail = iter->prev;
        this->tail->next = nullptr;
      } else {
        iter->prev->next = iter->next;
        iter->next->prev = iter->prev;
      }
      return free(iter);
    }
    return false;
  }

  void sort() {
    if (this->length <= 1) return;
    Sentry<T>* iter = this->begin();

    while (iter != this->end()) {
      Sentry<T>* innerIter = iter;
      Sentry<T>* smallest = iter;

      while (innerIter != this->end()) {
        if (innerIter->data < smallest->data) {
          smallest = innerIter;
        }
        innerIter = innerIter->next;
      }

      if (smallest == iter) {
        iter = iter->next;
        continue;
      }

      // if last node then update tail
      if (smallest == this->tail) {
        this->tail = smallest->prev;
        this->tail->next = nullptr;
      }

      // if first iteration
      if (iter == this->head) {
        this->head = smallest;
        this->head->next = iter;
        iter->prev = this->head;
        this->head->prev = nullptr;
      } else {
        Sentry<T>* node = smallest;
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = iter;
        node->prev = iter->prev;
        iter->prev->next = node;
        iter->prev = node;
      }
    }
  }

 private:
  void insertEmpty(const T &data) {
    Sentry<T>* node = new Sentry<T>;
    if (node == nullptr) {
      throw Utility::Exception(
          Utility::Exception::Level::ERROR, "Memory allocation failed");
    }

    this->head = node;
    this->tail = node;
    this->length++;

    this->head->data = data;

    node = nullptr;
    return;
  }
};

#endif  // LIST_H_
