#pragma once

template <typename T>
class List {
private:
    T* data;
    int capacity;
    int size;

public:
    List(int initialCapacity = 10);
    ~List();

    int Count() const;
    void Add(const T& item);
    T& operator[](int index);
    const T& operator[](int index) const;
    // Add more methods as needed
};

template <typename T>
List<T>::List(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    data = new T[capacity];
}

template <typename T>
List<T>::~List() {
    delete[] data;
}

template <typename T>
int List<T>::Count() const {
    return size;
}

template <typename T>
void List<T>::Add(const T& item) {
    if (size >= capacity) {
        // Resize the array if needed
        int newCapacity = capacity * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size] = item;
    ++size;
}

template <typename T>
T& List<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& List<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
