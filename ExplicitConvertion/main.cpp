#include <iostream>


class MyArray{
    public:
        int length;
        int* array;
        explicit MyArray(int length){
            this->length=length;
            this->array = static_cast<int *>(malloc(this->length* sizeof(int)));
        }
        void add(int index,int number) const{
            this->array[index]=number;
        }
        [[nodiscard]] int get(int index)const{
            return this->array[index];
        }
        void changeLength(int i){
            this->array = static_cast<int *>(malloc(i * sizeof(int)));
            this->length=i;
        }
        bool compareEquality(const int x[]) const{
            int counter{0};
            for(int i=0;i<this->length;i++){
                if(this->array[i]==x[i]){
                    counter++;
                }
            }
            if(counter==this->length){
                return true;
            }
            return false;
        }
};
int main() {
    MyArray array = *new MyArray(5);
    int x[5] ={1,2,3,4,5};
    for(int i=0;i<array.length;i++){
        array.add(i,i+1);
    }
    for(int i=0;i<array.length;i++){
        std::cout<<array.get(i)<<std::endl;
    }
    bool  result = array.compareEquality(x);
    std::cout<<result;
    return 0;
}
