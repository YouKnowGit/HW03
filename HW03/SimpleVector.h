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
    // ������ (�⺻�� Ȱ������ �ϳ��� �����ڷ� ����)
    SimpleVector(int capacity = 10)
        : currentSize(0), currentCapacity(capacity) {
        data = new T[currentCapacity];
    }

    // ���� ������
    SimpleVector(const SimpleVector& other)
        : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        data = new T[currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
    }

    // �Ҹ���
    ~SimpleVector() {
        delete[] data;
    }

    // push_back
    void push_back(const T& value) {
        if (currentSize >= currentCapacity) {   // ���� ����
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

    // ���� ���� ����
    int size() const {
        return currentSize;
    }

    // �迭 ��ü �뷮
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

    // ������
    void print() const {
        for (int i = 0; i < currentSize; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
