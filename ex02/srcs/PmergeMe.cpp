#include "../includes/PmergeMe.hpp"

#include "../includes/PmergeMe.hpp"

template <typename T>
void print_container(T container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

unsigned long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

std::vector<int> ford_johnson_sort_vector(std::vector<int> list)
{
    // If the list has 1 or 0 elements, it is already sorted
    if (list.size() <= 1) {
        return list;
    }

    // Split the list into two halves
    std::vector<int> left(list.begin(), list.begin() + list.size() / 2);
    std::vector<int> right(list.begin() + list.size() / 2, list.end());

    // Sort each half recursively
    left = ford_johnson_sort_vector(left);
    right = ford_johnson_sort_vector(right);

    // Merge the two halves
    std::vector<int> result;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));

    return result;
}

std::deque<int> ford_johnson_sort_deque(std::deque<int> list)
{
    // If the list has 1 or 0 elements, it is already sorted
    if (list.size() <= 1) {
        return list;
    }

    // Split the list into two halves
    std::deque<int> left(list.begin(), list.begin() + list.size() / 2);
    std::deque<int> right(list.begin() + list.size() / 2, list.end());

    // Sort each half recursively
    left = ford_johnson_sort_deque(left);
    right = ford_johnson_sort_deque(right);

    // Merge the two halves
    std::deque<int> result;
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front())
        {
            result.push_back(left.front());
            left.pop_front();
        }
        else
        {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    // Push the remaining elements of left, if there are any
    while (!left.empty())
    {
        result.push_back(left.front());
        left.pop_front();
    }

    // Push the remaining elements of right, if there are any
    while (!right.empty()) 
    {
        result.push_back(right.front());
        right.pop_front();
    }

    return result;
}

void readInput(std::string &input)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]) && input[i] != ' ')
        {
            std::cout << "Error: invalid input" << std::endl;
            exit(1);
        }
    }

    std::stringstream ss(input);
    std::vector<int> vector((std::istream_iterator<int>(ss)), std::istream_iterator<int>());
    std::deque<int> deque(vector.begin(), vector.end());
    unsigned long long time_vector_before, time_deque_before;
    unsigned long long time_vector, time_deque;
    
    std::cout << "Vector before: ";
    print_container(vector);
    std::cout << "Deque before: ";
    print_container(deque);
    std::cout << std::endl;
    time_vector_before = get_time();
    vector = ford_johnson_sort_vector(vector);
    time_vector = get_time() - time_vector_before;
    time_deque_before = get_time();
    deque = ford_johnson_sort_deque(deque);
    time_deque = get_time() - time_deque_before;
    std::cout << "Vector after: ";
    print_container(vector);
    std::cout << "Deque after: ";
    print_container(deque);
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vector.size() << " elements with vector : " << time_vector << "us" << std::endl;
    std::cout << "Time to process a range of " << deque.size() << " elements with deque : " << time_deque << "us" << std::endl;
}