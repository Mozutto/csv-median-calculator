#include "median_calculator.hpp"

#include <stdexcept>

namespace app {

    void MedianCalculator::add(double value) {
        if (lower_.empty() || value <= lower_.top()) {
            lower_.push(value);
        }
        else {
            upper_.push(value);
        }

        rebalance();
    }

    double MedianCalculator::median() const {
        if (empty()) {
            throw std::runtime_error("Cannot calculate median for empty dataset");
        }

        if (lower_.size() == upper_.size()) {
            return (lower_.top() + upper_.top()) / 2.0;
        }

        return lower_.top();
    }

    bool MedianCalculator::empty() const {
        return lower_.empty() && upper_.empty();
    }

    void MedianCalculator::rebalance() {
        if (lower_.size() > upper_.size() + 1) {
            upper_.push(lower_.top());
            lower_.pop();
        }
        else if (upper_.size() > lower_.size()) {
            lower_.push(upper_.top());
            upper_.pop();
        }
    }

}  // namespace app