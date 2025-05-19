#include <iostream>
#include <stdexcept>
#include <vector>

template<typename E>
class MyArrayList{
private:
    E* data;
    int size;
    int cap;
    static const int INIT_CAP=1;

public:
    MyArrayList(){
        this->data=new E[INIT_CAP];
        this->size=0;
        this->cap= INIT_CAP;
    }

    MyArrayList(int initCapacity){
        this->data=new E[initCapacity];
        this->size = 0;
        this->cap=initCapacity;
    }

    void addLast(E e){
        if(size==cap){
            resize(2*cap);
        }
        data[size] = e;
        size++;
    }

    void add(int index , E e){
        checkPositionIndex(index);
        if(size==cap){
            resize(cap*2);
        }

        for (int i=size-1;i>=index;i--){
            data[i+1]=data[i];
        }

        data[index]=e;
        size++;
    }

    void addFirst(E e){
        add(0,e);
    }

    E removeLast(int index){
        checkElementIndex(index);
         
        if(size == cap / 4){
            resize(cap/2);
        }

        E deletedVal = data[index];
        size--;

        return deletedVal;
    }

    E removeFirst(){
        return remove(0);
    }

    E get(int index){
        checkElementIndex(index);
        return data[index];
    }

    E set(int index, E element){
        checkElementIndex(index);

        E oldVal=data[index];
        data[index]=element;
        return oldVal;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        if (size==0){
            return true;
        }
        else {
            return false;
        }
    }

    void resize(int newCap){
        E* temp=new E[newCap];

        for(int i=0;i<size;i++){
            temp[i]=data[i];
        }

        delete[] data;

        data=temp;
        cap=newCap;
    }

    bool isElementIndex(int index){
        return index>=0 && index<size;
    }

    bool isPositionIndex(int index){
        return  index>=0 && index<=size;
    }

    void checkElementIndex(int index){
        if(!isElementIndex(index)){
            throw std::out_of_range("Index out of bounds");
        }
    }

    void checkPositionIndex(int index){
        if(!isPositionIndex(index)){
            throw std::out_of_range("Index out of bounds");
        }
    }

    void display(){
        std::cout<<"size = "<<size<<"cap = " << cap<<std::endl;
        for(int i = 0;i<size;i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<std::endl;
    }

    ~MyArrayList(){
        delete [] data;
    }

};



template<typename E>
class CycleArray{
    std::unique_ptr<E[]> CArray;
    int start;
    int end;
    int size;
    int count;

    CycleArray():CycleArray(1){}

    explicit CycleArray(int size):start(0),end(0),count(0),size(size){
        CArray=std::unique_ptr<E[]>(size);
    }
};



int main(){
    MyArrayList<int> arr(3);
    arr.display();
    arr.addLast(1);
    arr.display();
    arr.add(1, 3);
    arr.display();
}