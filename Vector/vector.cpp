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
        static inline size_type array_size{0};

    public:
        Vector()
        {
            array = nullptr;
            array_size = 0;
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
            if (array == nullptr)
            {
                array_size = obj.array_size;
                array = new T[array_size];
                for (int i = 0; i < array_size; i++)
                {
                    array[i] = obj.array[i];
                }
            }
            else
            {
                delete[] array;
                array_size = obj.array_size;
                array = new T[array_size];
                for (int i = 0; i < array_size; i++)
                {
                    array[i] = obj.array[i];
                }
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
        constexpr size_type capacity()const noexcept
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
        constexpr void clear()noexcept
        {
            delete[] array;
            array = nullptr;
            array_size = 0;
        }
        void insert(size_type pos, const_reference value)
        {
            const size_type temp_counter = array_size;
            array_size = array_size + 1;
            T* temp = new T[array_size];
            for (int i = 0; i < pos; i++)
            {
                temp[i] = array[i];
            }
            temp[pos] = value;
            size_type j = pos;
            for (size_type i = pos + 1; i < array_size; i++)
            {
                if (j < temp_counter)
                {
                    temp[i] = array[j];
                    j++;
                }
            }
            delete[] array;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;
            temp = nullptr;
            if (array == nullptr)
            {
                array_size = 1;
                array = new T[array_size];
                array[pos] = value;
            }
        }
        void insert(size_type pos, T&& value)
        {
            const size_type temp_counter = array_size;
            array_size = array_size + 1;
            T* temp = new T[array_size];
            for (int i = 0; i < pos; i++)
            {
                temp[i] = array[i];
            }
            temp[pos] = value;
            size_type j = pos;
            for (size_type i = pos + 1; i < array_size; i++)
            {
                if (j < temp_counter)
                {
                    temp[i] = array[j];
                    j++;
                }
            }
            delete[] array;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;
            temp = nullptr;
            if (array == nullptr)
            {
                array_size = 1;
                array = new T[array_size];
                array[pos] = value;
            }
        }
        void insert(size_type pos, size_type count, const_reference value)
        {
            const size_type temp_counter = array_size;
            array_size = array_size + count;
            T* temp = new T[array_size];
            for (int i = 0; i < pos; i++)
            {
                temp[i] = array[i];
            }
            for (int i = pos; i < pos + count; i++)
            {
                temp[i] = value;
            }
            size_type j = pos;
            for (size_type i = pos + count; i < array_size; i++)
            {
                if (j < temp_counter)
                {
                    temp[i] = array[j];
                    j++;
                }
            }
            delete[] array;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;
            temp = nullptr;
        }
        void insert(size_type pos, std::initializer_list<T> init_insert)
        {
            const size_type temp_counter = array_size;
            const size_type init_list_counter = init_insert.size();
            array_size = array_size + init_insert.size();
            T* temp = new T[array_size];
            for (int i = 0; i < pos; i++)
            {
                temp[i] = array[i];
            }
            const T* ptr = init_insert.begin();
            for (int i = pos; i < pos + init_list_counter; i++)
            {
                if (ptr != init_insert.end())
                {
                    temp[i] = *ptr;
                    ptr++;
                }
            }
            size_type j = pos;
            for (size_type i = pos + init_list_counter; i < array_size; i++)
            {
                if (j < temp_counter)
                {
                    temp[i] = array[j];
                    j++;
                }
            }
            delete[] array;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;
            temp = nullptr;
        }
        constexpr void erase(const_reference pos)
        {
            const size_type tempHolder = array_size;
            array_size = array_size - 1;
            T* temp = new T[array_size];
            for (int i = 0; i < pos; i++)
            {
                temp[i] = array[i];
            }
            size_type j = pos + 1;
            for (int i = pos; i < array_size; i++)
            {
                if (j < tempHolder)
                {
                    temp[i] = array[j];
                    j++;
                }
            }
            delete[] array;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;
            temp = nullptr;
        }
        constexpr void erase(const_reference first, const_reference last)
        {
            const size_type tempHolder = array_size;
            array_size = array_size - (last - first);
            T* temp = new T[array_size];
            for (int i = 0; i < first; i++)
            {
                temp[i] = array[i];
            }
            size_type j = last;
            for (int i = first; i < array_size; i++)
            {
                if (j < tempHolder)
                {
                    temp[i] = array[j];
                    j++;
                }
            }
            delete[] array;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;
            temp = nullptr;
        }
        constexpr void push_back(const_reference element)
        {
            const size_type tempHolder = array_size;
            array_size = array_size + 1;
            T* temp = new T[array_size];
            for (int i = 0; i < tempHolder; i++)
            {
                temp[i] = array[i];
            }
            temp[array_size - 1] = element;
            delete[] array;
            array = new T[array_size]; 
            for (int i = 0; i < array_size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;
            temp = nullptr;
        }
        constexpr void pop_back()
        {
            array_size = array_size - 1;
            T* temp = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = new T[array_size];
            for (int i = 0; i < array_size; i++)
            {
                array[i] = temp[i];
            }
            delete[] temp;;
            temp = nullptr;
        }
        constexpr void resize(size_type count)
        {
            if (count > array_size)
            {
                const size_type tempHolder = array_size;
                array_size = count;
                T* temp = new T[array_size];
                for (int i = 0; i < tempHolder; i++)
                {
                    temp[i] = array[i];
                }
                delete[] array;
                array = new T[array_size];
                for (int i = 0; i < tempHolder; i++)
                {
                    array[i] = temp[i];
                }
                delete[] temp;
                temp = nullptr;
            }
            else if (count < array_size)
            {
                array_size = count;
                T* temp = new T[array_size];
                for (int i = 0; i < count; i++)
                {
                    temp[i] = array[i];
                }
                delete[] array;
                array = new T[array_size];
                for (int i = 0; i < array_size; i++)
                {
                    array[i] = temp[i];
                }
                delete[] temp;
                temp = nullptr;
            }
            else
            {
                array_size = count;
                array = new T[count];
            }
        }
        constexpr void resize(size_type count, const value_type& value)
        {
            if (array == nullptr)
            {
                array_size = count;
                array = new T[array_size];
                for (int i = 0; i < array_size; i++)
                {
                    array[i] = value;
                }
            }
            if (count > array_size)
            {
                const size_type tempHolder = array_size;
                array_size = count;
                T* temp = new T[array_size];
                for (int i = 0; i < tempHolder; i++)
                {
                    temp[i] = array[i];
                }
                delete[] array;
                array = new T[array_size];
                for (int i = 0; i < tempHolder; i++)
                {
                    array[i] = temp[i];
                }
                for (int i = tempHolder; i < array_size; i++)
                {
                    array[i] = value;
                }
                delete[] temp;
                temp = nullptr;
            }
            else
            {
                array_size = count;
                T* temp = new T[array_size];
                for (int i = 0; i < count; i++)
                {
                    temp[i] = array[i];
                }
                delete[] array;
                array = new T[array_size];
                for (int i = 0; i < array_size; i++)
                {
                    array[i] = temp[i];
                }
                delete[] temp;
                temp = nullptr;
            }
        }
        constexpr void swap(Vector& obj)
        {
            if (array == nullptr)
            {
                array_size = obj.array_size;
                array = new T[array_size];
                for (int i = 0; i < array_size; i++)
                {
                    array[i] = obj.array[i];
                }
            }

            const size_type max_temp_size = std::max(array_size, obj.array_size);
            T* temp = new T[max_temp_size];
            const size_type size1 = array_size;
            const size_type size2 = obj.array_size;
            for (int i = 0; i < array_size; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = new T[size2];
            for (int i = 0; i < size2; i++)
            {
                array[i] = obj.array[i];
            }
            delete[] obj.array;
            obj.array = new T[size1];
            for (int i = 0; i < size1; i++)
            {
                obj.array[i] = temp[i];
            }
            delete[] temp;
            temp = nullptr;
        }
        ~Vector()
        {
            delete[] array;
            array = nullptr;
            array_size = 0;
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
        
        bool operator== (Vector<T>& obj)
        {
            if (array_size == obj.array_size)
            {
                for (int i = 0; i < std::min(array_size, obj.array_size); i++)
                {
                    if (array[i] != obj.array[i])
                    {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        bool operator!= (Vector<T>& obj)
        {
            if (array_size == obj.array_size)
            {
                for (int i = 0; i < std::min(array_size, obj.array_size); i++)
                {
                    if (array[i] != obj.array[i])
                    {
                        return true;
                    }
                }
                return false;
            }
            return true;
        }
    };

}


int main()
{
    my::Vector<int> v{1, 2, 3, 4, 5, 6};
    my::Vector<int> v0{1, 2, 3, 4, 5, 6};
    if(v==v0)
    {
        std::cout<<"equal\n";
    }
    else{std::cout<<"not equal\n";}
    v0.swap(v);
    v.print();
    std::cout << "\n";
    std::cout << v.empty() << "\n";
    my::Vector<int> dem = { 2,3,4,5,6,7,1,2,3,4,4,5,6,7,8,90,1,2,3,4,5,6 };
    std::cout << "size of array before reserve is : " << dem.size() << "\n";
    dem.reserve(4);
    std::cout << "size of array after reserve is : " << dem.size() << "\n";
    dem.assign({ 1,2,3,4,5 });
    dem.insert(0, { 8,6,9,3 });
    dem.print(); std::cout << "\n";
    dem.erase(1, 3);
    dem.print(); std::cout << "\n";
    dem.at(1) = 78;
    dem[2] = 8;
    std::cout << dem[2] << "\n";
    dem.print();
    dem.push_back(99);
    std::cout << "\n";
    dem.print();
    dem.pop_back();
    std::cout << "\n";
    dem.print();
    std::cout << "\nHello World!\n";
}
