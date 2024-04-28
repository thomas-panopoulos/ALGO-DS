#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> result;
    for (char c : numString) {
        result.push_back(c - '0'); // Convert char to int and add to list
    }
    return result;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry = 0;

    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    while (it1 != num1.rend() || it2 != num2.rend() || carry != 0) {
        int sum = carry;
        if (it1 != num1.rend()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.rend()) {
            sum += *it2;
            ++it2;
        }
        result.push_front(sum % 10);
        carry = sum / 10;
    }
    return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int borrow = 0;

    auto it1 = num1.rbegin(), it2 = num2.rbegin();
    while (it1 != num1.rend()) {
        int diff = *it1 - borrow;
        if (it2 != num2.rend()) {
            diff -= *it2;
            ++it2;
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
        ++it1;
    }
    // Remove leading zeros
    while (result.size() > 1 && result.front() == 0) {
        result.pop_front();
    }
    return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    int digit = num2.front();
    num2.pop_front(); // Remove the single digit from num2

    std::list<int> result;
    int carry = 0;

    auto it = num1.rbegin();
    while (it != num1.rend() || carry != 0) {
        int product = carry;
        if (it != num1.rend()) {
            product += *it * digit;
            ++it;
        }
        result.push_front(product % 10);
        carry = product / 10;
    }
    // Add the carry to the result
    while (carry != 0) {
        result.push_front(carry % 10);
        carry /= 10;
    }
    return result;
}