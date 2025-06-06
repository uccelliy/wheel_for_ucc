#include <memory>
#include <vector>





template<typename E>
class CycleArray {
    std::unique_ptr<E[]> CArray;
    int start;
    int end;
    int size;
    int count;

    CycleArray() :CycleArray(1) {}

    explicit CycleArray(int size) :start(0), end(0), count(0), size(size) {
        CArray = std::unique_ptr<E[]>(size);
    }
};