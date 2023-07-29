#include <iostream>
#include <initializer_list>

namespace my
{
    template <typename T>
    class Vector
    {
    private:
        typedef T value_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef unsigned long long size_type;

        const T* beg_ptr = nullptr;
        const T* end_ptr = nullptr;

    private:
        T* array;
        static inline size_type array_size;

    public:
        Vector()
        {
            array = nullptr;
        }
        Vector(size_type count)
        {
            array_size = count;
            array = new T[count];
        }
        Vector(size_type count, T element)
        {
            array_size = count;
            array = new T[count];
            for (int i = 0; i < count; i++)
            {
                array[i] = element;
            }
        }
        Vector(const Vector& obj)
        {
            array_size = obj.array_size;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = obj.array[i];
            }
        }
        Vector(std::initializer_list<T> init_obj)
        {
            array_size = init_obj.size();
            array = new T[array_size];
            size_type i = 0;
            for (const T* ptr = init_obj.begin(); ptr != init_obj.end(); ptr++)
            {
                array[i] = *ptr;
                i++;
            }
        }
        void operator=(const Vector& obj)
        {
            array_size = obj.array_size;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = obj.array[i];
            }
        }
        void operator=(std::initializer_list<T> init_copy)
        {
            array_size = init_copy.size();
            array = new T[array_size];
            size_type i = 0;
            for (const T* ptr = init_copy.begin(); ptr != init_copy.end(); ptr++)
            {
                array[i] = *ptr;
                i++;
            }
        }
        void assign(size_type count, value_type elms)
        {
            if (array == nullptr)
            {
                array_size = count;
                array = new T[count];
            }
            else
            {
                delete[] array;
                array_size = count;
                array = new T[count];
            }
            for (size_type i = 0; i < array_size; i++)
            {
                array[i] = elms;
            }
        }
        void assign(std::initializer_list<T> init_elms)
        {
            if (array == nullptr)
            {
                array_size = init_elms.size();
                array = new T[array_size];
            }
            else
            {
                delete[] array;
                array_size = init_elms.size();
                array = new T[array_size];
            }
            size_type i = 0;
            for (const T* ptr = init_elms.begin(); ptr != init_elms.end(); ptr++)
            {
                array[i] = *ptr;
                i++;
            }
        }
        reference at(size_type pos)const
        {
            if (pos > 0 && pos < array_size)
            {
                return array[pos];
            }
            std::cout << "ERROR : OUT_OF_RANGE\n";
        }
        reference operator[](const size_type pos)const
        {
            if (pos > 0 && pos < array_size)
            {
                return array[pos];
            }
            std::cout << "ERROR : OUT_OF_RANGE\n";
        }
        const_reference front()const
        {
            return array[0];
        }
        const_reference back()const
        {
            return array[array_size - 1];
        }
        const T* const data()const
        {
            if (array == nullptr)
            {
                return nullptr;
            }
            return array;
        }
        [[nodiscard]] constexpr bool empty()const noexcept
        {
            if (array == nullptr)
            {
                return true;
            }
            return false;
        }
        constexpr size_type size()const noexcept
        {
            return array_size;
        }
        constexpr void reserve(size_type r_count)
        {
            if (array == nullptr)
            {
                array_size = r_count;
                array = new T[array_size];
            }
            else
            {
                size_type temp_count_handler = array_size;
                array_size = array_size + r_count;
                T* temp = new T[array_size];
                for (int i = 0; i < temp_count_handler; i++)
                {
                    temp[i] = array[i];
                }
                delete[] array;
                array = new T[array_size];
                for (int i = 0; i < temp_count_handler; i++)
                {
                    array[i] = temp[i];
                }
                delete[] temp;
                temp = nullptr;
            }
        }
        ~Vector()
        {
            delete[] array;
        }
        void print()
        {
            for (int i = 0; i < array_size; i++)
            {
                std::cout << array[i];
            }
        }
        const T* begin()const
        {
            beg_ptr = &array[0];
            return (beg_ptr);
        }
        const T* end()const
        {
            end_ptr = &array[array_size - 1];
            return (end_ptr);
        }
    };
}


int main()
{
    my::Vector<int> v{1, 2, 3, 4, 5, 6};
    std::cout << v.empty() << "\n";
    my::Vector<int> dem = {2,3,4,5,6,7,1,2,3,4,4,5,6,7,8,90,1,2,3,4,5,6};
    std::cout << "\size of array before reserve is : " << dem.size() << "\n";
    dem.reserve(4);
    std::cout << "\size of array after reserve is : " << dem.size() << "\n";
    dem.assign({1,2,3,4,5});
    dem.at(1) = 78;
    dem[2] = 8;
    std::cout << dem[2]<<"\n";
    dem.print();
    std::cout << "\nHello World!\n";
}

