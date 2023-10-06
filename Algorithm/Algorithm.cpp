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

        template <typename T,std::size_t N>
        void binarySearch(T(&arr)[N],T elm)
        {
            bool truth_value=false;
            std::size_t left=0;
            std::size_t right=N-1;
            while(left<=right)
            {
                std::size_t mid=(left+right)/2;
                if(arr[mid]>elm)
                {
                    right=mid-1;
                }
                else if(arr[mid]<elm)
                {
                    left=mid+1;
                }
                else if(arr[mid]==elm)
                {
                    truth_value=true;
                    break;
                }
            }
            std::cout<<truth_value;
        }
        
        
        template <typename T>
        void binarySearch(T * first_,T *last_,T elm)
        {
            bool truth_value=false;
            std::vector<int> temp_elm_storage{};
            for(auto ptr=first_;ptr<=last_;++ptr)
            {
                temp_elm_storage.push_back(*ptr);
            }
            auto left=temp_elm_storage.begin();
            auto right=temp_elm_storage.end();
            while(left<=right)
            {
                auto mid=left++;
                if(elm<*mid)
                {
                    right=mid-1;
                }
                else if(elm>*mid)
                {
                    left=mid+1;
                }
                else if(elm==*mid)
                {
                    truth_value=true;
                    break;
                }
            }
            std::cout<<truth_value;
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

