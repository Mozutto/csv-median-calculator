#include "csv_reader.hpp"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace app {

    std::vector<PriceRecord> read_csv_file(const std::filesystem::path& file) {
        std::vector<PriceRecord> result{};

        std::ifstream in(file);
        if (!in) {
            return result;
        }

        std::string line;

        // Пропускаем заголовок
        if (!std::getline(in, line)) {
            return result;
        }

        while (std::getline(in, line)) {
            if (line.empty()) {
                continue;
            }

            std::stringstream ss(line);

            std::string receive_ts;
            std::string exchange_ts;
            std::string price;
            std::string quantity;
            std::string side;

            std::getline(ss, receive_ts, ';');
            std::getline(ss, exchange_ts, ';');
            std::getline(ss, price, ';');
            std::getline(ss, quantity, ';');
            std::getline(ss, side, ';');

            if (receive_ts.empty() || price.empty()) {
                continue;
            }

            PriceRecord rec{};
            rec.receive_ts = std::stoll(receive_ts);
            rec.price = std::stod(price);

            result.push_back(rec);
        }

        return result;
    }

}  // namespace app