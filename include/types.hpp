#pragma once

#include <cstdint>

namespace app {

    struct PriceRecord {
        std::int64_t receive_ts{};
        double price{};
    };

}  // namespace app