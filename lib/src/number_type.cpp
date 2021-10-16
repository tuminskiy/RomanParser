#include "number_type.hpp"

#include <unordered_map>

namespace rp {

using namespace std::string_view_literals;

static const std::unordered_map<number_type, std::string_view> NUMBER_TYPE_TABLE = {
  { number_type::unknow,         "unknow"sv },
  { number_type::number_1_9,     "numbers 1-9"sv },
  { number_type::number_10_19,   "numbers 10-19"sv },
  { number_type::number_20_90,   "numbers 20-90"sv },
  { number_type::number_100_900, "numbers 100-900"sv }
};

std::string_view to_str(number_type type) { return NUMBER_TYPE_TABLE.at(type); }

} // namespace rp