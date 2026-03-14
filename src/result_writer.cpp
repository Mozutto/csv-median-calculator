#include "result_writer.hpp"

#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <stdexcept>

#include "median_calculator.hpp"

namespace app {

    namespace {

        double round_to_8(double value) {
            return std::round(value * 100000000.0) / 100000000.0;
        }

    }  // namespace

    void write_median_result(
        const std::vector<PriceRecord>& records,
        const std::filesystem::path& output_dir
    ) {
        std::filesystem::create_directories(output_dir);

        const auto output_file = output_dir / "median_result.csv";
        std::ofstream out(output_file, std::ios::trunc);

        if (!out) {
            throw std::runtime_error("Failed to open output file: " + output_file.string());
        }

        out << "receive_ts;price_median\n";

        MedianCalculator calculator{};
        bool has_previous_median = false;
        double previous_median = 0.0;

        for (const auto& record : records) {
            calculator.add(record.price);

            const double current_median = round_to_8(calculator.median());

            if (!has_previous_median || round_to_8(previous_median) != current_median) {
                out << record.receive_ts << ';'
                    << std::fixed << std::setprecision(8)
                    << current_median << '\n';

                previous_median = current_median;
                has_previous_median = true;
            }
        }

        out.flush();

        if (!out) {
            throw std::runtime_error("Failed while writing output file: " + output_file.string());
        }
    }

}  // namespace app