#pragma once

#include <functional>
#include <queue>
#include <vector>

namespace app {

    class MedianCalculator {
    public:
        void add(double value);
        [[nodiscard]] double median() const;
        [[nodiscard]] bool empty() const;

    private:
        std::priority_queue<double> lower_;
        std::priority_queue<double, std::vector<double>, std::greater<>> upper_;

        void rebalance();
    };

}  // namespace app