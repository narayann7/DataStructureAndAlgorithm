#include <iostream>
#include <iterator>
#include <utility>
#include <algorithm>
#include <vector>
#include <type_traits>

template<typename I>
void bubble(I begin, I end)
{
    --end;
    for (; begin != end; --end) {
        bool swap = false;
        I last = end - 1;
        for (I loop = begin; loop != last; ++loop) {
            if ( *loop > *(loop + 1)) {
                std::iter_swap(loop, loop + 1);
                swap = true;
            }
        }
        if (!swap) {
            break;
        }
    }
}

template<typename I>
void insert(I begin, I end)
{
    for (I loop = begin + 1; loop != end; ++loop) {
        for (I test = loop; test != begin; --test) {
            if (*(test - 1) <= *test) {
                break;
            }
            std::iter_swap(test - 1, test);
        }
    }
}

template<typename I>
void select(I begin, I end)
{
    for (I loop = begin; loop != end; ++loop) {
        I smallest = loop;
        I select   = loop + 1;
        for (; select != end; ++select) {
            if (*select < *smallest) {
                smallest = select;
            }
        }
        std::iter_swap(smallest, loop);
    }
}

template<typename I>
I partition(I begin, I end)
{
    I pivot = end - 1;
    I insertPoint = begin;

    for (I loop = begin; loop != pivot; ++loop) {
        if (*loop <= *pivot) {
            std::iter_swap(insertPoint, loop);
            ++insertPoint;
        }
    }

    std::iter_swap(insertPoint, pivot);
    return insertPoint;
}

template<typename I>
void quick(I begin, I end)
{
    if (begin != end) {
        I mid = partition(begin, end);
        quick(begin, mid);
        quick(mid + 1, end);
    }
}

template<typename I>
void mergeRange(I begin, I mid, I end)
{
    using ValueType = typename std::iterator_traits<I>::value_type;
    using Container = std::vector<ValueType>;
    using Iterator  = typename Container::iterator;

    Container   lower(std::make_move_iterator(begin), std::make_move_iterator(mid));
    Container   upper(std::make_move_iterator(mid),   std::make_move_iterator(end));

    Iterator  lloop = std::begin(lower);
    Iterator  lend  = std::end(lower);
    Iterator  uloop = std::begin(upper);
    Iterator  uend  = std::end(upper);
    I   loop = begin;

    while (lloop != lend && uloop != uend)
    {
        ValueType& lowerValue = *lloop;
        ValueType& upperValue = *uloop;

        *loop = std::move( lowerValue <= upperValue ? *lloop++ : *uloop++ );
        ++loop;
    }
    loop = std::move(lloop, lend, loop);
    loop = std::move(uloop, uend, loop);
}

template<typename I>
void merge(I begin, I end)
{
    std::size_t size = std::distance(begin, end);
    if(size > 1) {
        I mid = std::next(begin, size/2);
        merge(begin, mid);
        merge(mid,   end);
        mergeRange(begin, mid, end);
    }
}

template<typename I>
void count(I begin, I end)
{
    using ValueType = typename std::iterator_traits<I>::value_type;
    static_assert(std::is_integral_v<ValueType>);

    auto minmax = std::minmax_element(begin, end);
    std::size_t range  = *minmax.second - *minmax.first + 1;
    std::size_t offset = *minmax.first;
    std::vector<std::size_t>    countData(range);

    for (I loop = begin; loop != end; ++loop) {
        ++countData[*loop - offset];
    }

    I insertPoint = begin;
    for (std::size_t loop = 0; loop < countData.size(); ++loop) {
        std::size_t& valueCount = countData[loop];
        for (;valueCount; --valueCount) {
            *insertPoint++ = static_cast<ValueType>(loop + offset);
        }
    }
}

int main() 
{
    int choice = 1;
    while (choice) {

        std::cout << "\nenter the size of the array\n";
        int n;
        if (!(std::cin >> n)) {
            std::cerr << "Bad Value\n";
            return 1;
        }

        std::vector<int>    data(n);

        printf("enter the elements of array\n");
        for (int loop = 0; loop < n; ++loop) {
            if (!(std::cin >> data[loop])) {
                std::cerr << "Bad Array Value\n";
                return 1;
            }
        }

        printf("enter 1 for bubble sort\n");
        printf("enter 2 for insetion sort\n");
        printf("enter 3 for slection sort\n");
        printf("enter 4 for quicksort\n");
        printf("enter 5 for mergesort\n");
        printf("enter 6 for countsort\n");

        if ((!(std::cin >> choice)) || (choice < 0 || choice > 6)) {
            std::cerr << "Bad Choice\n";
            return 1;
        }

        auto begin = std::begin(data);
        auto end   = std::end(data);

        switch(choice)
        {
            case 1: bubble(begin, end);  break;
            case 2: insert(begin, end);  break;
            case 3: select(begin, end); break;
            case 4: quick(begin, end);   break;
            case 5: merge(begin, end);   break;
            case 6: count(begin, end);   break;
        }
        std::copy(begin, end, std::ostream_iterator<int>(std::cout, ", "));
    }
}

