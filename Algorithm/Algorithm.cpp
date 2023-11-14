#include <iostream>
#include <vector>
#include <string>
#include <cmath>

namespace my
{
    class Algorithms
    {
    public:
        template <typename T, std::size_t N>
        void linearSearch(T(&arr)[N], T elm)
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
        void linearSearch(typename std::vector<T>::iterator it_first, typename std::vector<T>::iterator it_last, T elm)
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

        template <typename T, std::size_t N>
        void binarySearch(T(&arr)[N], T elm)
        {
            bool truth_value = false;
            std::size_t left = 0;
            std::size_t right = N - 1;
            while (left <= right)
            {
                std::size_t mid = (left + right) / 2;
                if (arr[mid] > elm)
                {
                    right = mid - 1;
                }
                else if (arr[mid] < elm)
                {
                    left = mid + 1;
                }
                else if (arr[mid] == elm)
                {
                    truth_value = true;
                    break;
                }
            }
            std::cout << truth_value;
        }

        template <typename T>
        void binarySearch(std::vector<T>& arr, T elm)
        {
            bool truth_value = false;
            std::size_t left = 0;
            std::size_t right = arr.size() - 1;
            while (left <= right)
            {
                std::size_t mid = (left + right) / 2;
                if (elm < arr[mid])
                {
                    right = mid - 1;
                }
                else if (elm > arr[mid])
                {
                    left = mid + 1;
                }
                else if (elm == arr[mid])
                {
                    truth_value = true;
                    break;
                }
            }
            std::cout << truth_value;
        }

        template <typename T>
        void binarySearch(T* first_, T* last_, T elm)
        {
            std::vector<int> temp_elm_storage{};
            for (auto ptr = first_; ptr <= last_; ++ptr)
            {
                temp_elm_storage.push_back(*ptr);
            }
            bool truth_value = false;
            std::size_t left = 0;
            std::size_t right = temp_elm_storage.size() - 1;
            while (left <= right)
            {
                std::size_t mid = (left + right) / 2;
                if (elm < temp_elm_storage[mid])
                {
                    right = mid - 1;
                }
                else if (elm > temp_elm_storage[mid])
                {
                    left = mid + 1;
                }
                else if (elm == temp_elm_storage[mid])
                {
                    truth_value = true;
                    break;
                }
            }
            std::cout << truth_value;
        }

        template <typename T>
        void binarySearch(typename std::vector<T>::iterator it_first, typename std::vector<T>::iterator it_last, T elm)
        {
            bool truth_value = false;
            std::vector<T> temp_elm_storage{};
            for (auto ptr = it_first; ptr <= it_last; ++ptr)
            {
                temp_elm_storage.push_back(*ptr);
            }
            std::size_t left = 0;
            std::size_t right = temp_elm_storage.size()-1;
            while (left <= right)
            {
                std::size_t mid = (left + right) / 2;
                if (elm < temp_elm_storage[mid])
                {
                    right = mid - 1;
                }
                else if (elm > temp_elm_storage[mid])
                {
                    left = mid + 1;
                }
                else if (elm == temp_elm_storage[mid])
                {
                    truth_value = true;
                    break;
                }
            }
            std::cout << truth_value;
        }

        template <typename T,std::size_t N>
        void ternarySearch(T(&arr)[N],T elm)
        {
            bool truth_value=false;
            std::size_t left=0;
            std::size_t right=N-1;
            while(left!=right)
            {
                std::size_t mid1=left+(right-left)/3;
                std::size_t mid2=right-(right+left)/3;
                if(elm==arr[mid1])
                {
                    truth_value=true;
                }
                else if(elm==arr[mid2])
                {
                    truth_value=true;
                }
                else if(elm<arr[mid1])
                {
                    right=mid1-1;
                }
                else if(elm>arr[mid2])
                {
                    left=mid2+1;
                }
                else
                {
                    left=mid1+1;
                    right=mid2-1;
                }
            }
            std::cout<<truth_value;
        }
        
        template <typename T, std::size_t N>
        void jumpSearch(T(&arr)[N],T elm)
        {
            int jump_index=static_cast<int>(sqrt(N));
            bool truth_value=false;
            int i=0;
            while(i<N)
            {
                if(arr[i]==elm)
                {
                    truth_value=true;
                }
                else if(arr[i]!=elm)
                {
                    int temp=i;
                    i+=jump_index;  
                    if(elm<arr[i])
                    {
                        for(int j=temp;j<=i;j++)
                        {
                            if(arr[j]==elm)
                            {
                                truth_value=true;
                            }
                        }
                    }
                }
            }
            std::cout<<truth_value;
        }
    };
}


int main()
{
    std::vector<int> array{ 1,2,3,4,5,6,7,8 };
    int arr[16]{0, 1, 1, 2, 3, 5, 8, 13, 21,34, 55, 89, 144, 233, 377, 610 };
    my::Algorithms obj;
    obj.linearSearch<int>(array.begin(), array.end(), 9);
    obj.jumpSearch<int,16>(arr,55);
    std::cout << "Hello World!\n";
}
