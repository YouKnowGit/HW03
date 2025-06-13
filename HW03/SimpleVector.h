#include <iostream>
#include <algorithm> // std::sort
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;
    int currentSize;
    int currentCapacity;

public:
    // 생성자 (기본값 활용으로 하나의 생성자로 통일)
    SimpleVector(int capacity = 10)
        : currentSize(0), currentCapacity(capacity) {
        data = new T[currentCapacity];
    }

    // 복사 생성자
    SimpleVector(const SimpleVector& other)
        : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        data = new T[currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
    }

    // 소멸자
    ~SimpleVector() {
        delete[] data;
    }

    // push_back
    void push_back(const T& value) {
        if (currentSize >= currentCapacity) {   // 도전 과제
            resize(currentCapacity + 5);
        }
        data[currentSize++] = value;
    }

    // pop_back
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }

    // 현재 원소 개수
    int size() const {
        return currentSize;
    }

    // 배열 전체 용량
    int capacity() const {
        return currentCapacity;
    }

    // resize
    void resize(int newCapacity) {
        if (newCapacity <= currentCapacity) return;

        T* newData = new T[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        currentCapacity = newCapacity;
    }

    // sortData
    void sortData() {
        std::sort(data, data + currentSize);
    }

    // 디버깅용
    void print() const {
        for (int i = 0; i < currentSize; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
