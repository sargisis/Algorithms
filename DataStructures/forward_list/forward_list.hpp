#include "../DataStructures/forward_list.h"

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::forward_list() 
    : m_head{nullptr}
    , m_size{0}
{}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::forward_list(const forward_list& rhv) 
    : m_head{rhv.m_head}
    , m_size{0}
{
    Node* current = this->m_head
    while (current->next != nullptr){
        push_back(current->val);
        current = current->next; 
    }
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::forward_list(forward_list&& rhv ) noexcept
    : m_head{std::move(rhv.m_head)}
    , m_size{std::move(rhv.m_size)}

{
    m_head = nullptr;
    m_size = 0; 
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::forward_list(std::initializer_list<T> init) 
    : forward_list()
{
    for (const auto& it : init) {
        push_back(it);
    }
}

template<typename T, typename Allocator>
template<typename InputIt>
g3::forward_list<T,Allocator>::forward_list(InputIt first , InputIt last) 
    : forward_list()
{
    for (auto it = first; it != last; ++it) {
        push_back(*it);
    }
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::~forward_list() {
    clear();
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>& g3::forward_list<T,Allocator>::operator=(const forward_list& rhv) 
{
    if (this != &rhv) {
        this->clear();
        m_size = rhv.m_size; 
        for (size_t i = 0; i < rhv.m_size; ++i) {
            m_head[i] = rhv.m_head[i];
        }
    }
    return *this; 
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>& g3::forward_list<T,Allocator>::operator=(forward_list&& rhv) noexcept
{
    if (this != &rhv) {
        this->clear();
        m_size = std::move(rhv.m_size);
        m_head = std::move(rhv.m_head);

        m_size = 0; 
        m_head = nullptr;
       
    }
    return *this; 
}

template<typename T, typename Allocator>
g3::forward_list<T,Allocator>::allocator_type g3::forward_list<T,Allocator>::get_allocator() const 
{
    return m_alloc;
}

template<typename T, typename Allocator>
void g3::forward_list<T,Allocator>::assign(size_type count , const_reference value) 
{
    for (size_t i = 0; i < count; ++i) {
        m_head[i] = value;
    }
}

template<typename T, typename Allocator>
template<typename InputIt>
void g3::forward_list<T,Allocator>::assign(InputIt first , InputIt last) {
    for (auto it = first , it != last; ++it ) {
        push_back(*it);
    }
}

template<typename T
