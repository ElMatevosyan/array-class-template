#include <iostream>
#include <vector>
#include <algorithm>
 
template<typename T>
class Array 
{
private:
    T* m_arr;
    int m_size;

public:
    Array()
        :m_size(3)
    {
        m_arr = new T[m_size]{};
    }
    
    Array(unsigned int n)
    {
        m_arr = new T[n];
        m_size = n;
        for(int i=0; i<m_size; i++)
            m_arr[i] = rand()%25;
    }
void print()
{
        for(int i=0; i<m_size; i++)
            std::cout << m_arr[i] <<' ';
    std::cout << std::endl;
}

int size()
{
    return m_size;
}

// Overloads the assignment operator
const Array<T>& operator= (const Array<T>& other)
    {
        for(int i=0; i<m_size; i++)
            {
            m_arr[i] = other.m_arr[i];
            }
	return *this;
    }
    
// Overloads the equality operator
bool operator== (const Array & right) const
    {
        bool flag = true;
        for(int i=0; i<m_size; i++)
        {
        if ( (m_arr[i] != right.m_arr[i]) )
            flag = false;
        }
        return flag;
    }
    
    ~Array()
    {
        delete[] m_arr;
        m_arr = nullptr;
    }
};

int main()
{
    const unsigned int n = 5;
    Array<int> a(n);
    Array<int> b(n);
    a.print();
    b.print();
    
    std::cout<<"\n Operator '==' "<< std::endl;
    if (a==b)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    
    std::cout<<"\n Operator '=' "<< std::endl;
    a=b;
    a.print();
    b.print();

    
    std::cout<<"\n Operator '==' "<< std::endl;
    if (a==b)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return 0;
}
