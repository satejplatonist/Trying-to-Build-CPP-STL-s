#include <iostream>
#include <vector>
#include <string>

namespace my
{
    class Algorithms
    {
    public:
        template <typename T,std::size_t N>
        void linearSearch(T(&arr)[N],T elm)
        {
            bool truth_value = false;
            for (int i = 0; i < sizeof(arr) / sizeof(T); i++)
            {
                if (arr[i] == elm)
                {
                    truth_value = true;
                    break;
                }
            }
            std::cout << truth_value;
        }

        template <typename T>
        void linearSearch(std::vector<T>& arr, T elm)
        {
            bool truth_value = false;
            for (auto ptr = arr.begin(); ptr < arr.end(); ptr++)
            {
                if (*ptr == elm)
                {
                    truth_value = true;
                    break;
                }
            }
            std::cout << truth_value;
        }

        template <typename T>
        void linearSearch(T* _first, T* _last, T elm)
        {
            bool truth_value = false;
            for (auto ptr = _first; ptr <= _last; ptr++)
            {
                if (*ptr == elm)
                {
                    truth_value = true;
                    break;
                }
            }
            std::cout << truth_value;
        }

        template <typename T>
        void linearSearch(typename std::vector<T>::iterator it_first, typename std::vector<T>::iterator it_last,T elm)
        {
            bool truth_value = false;
            for (auto ptr = it_first; ptr < it_last; ptr++)
            {
                if (*ptr == elm)
                {
                    truth_value = true;
                    break;
                }
            }
            std::cout << truth_value;
        }
    };
}


int main()
{
    std::vector<int> arr{ 1,2,3,4,5,6,7,8 };
    my::Algorithms obj;
    obj.linearSearch<int>(arr.begin(),arr.end(),9);
    std::cout << "Hello World!\n";
}

