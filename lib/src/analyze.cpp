#include "analyze.hpp"

namespace rp {

std::string get_error_msg(const number_info& lhs, const number_info& rhs) {
  using namespace std::string_literals;

  std::string msg = "После "s;

  if (lhs.type == number_type::number_1_9) {
    msg += "единиц"s;
  } else if (lhs.type == number_type::number_10_19) {
    msg += "десяток (10-19)"s;
  } else if (lhs.type == number_type::number_20_90) {
    msg += "десяток (20-90)"s;
  } else if (lhs.type == number_type::number_100_900) {
    msg += "сотен"s;
  }

  msg += " не должны идти ";

  if (rhs.type == number_type::number_1_9) {
    msg += "единицы"s;
  } else if (rhs.type == number_type::number_10_19) {
    msg += "десятки (10-19)"s;
  } else if (rhs.type == number_type::number_20_90) {
    msg += "десятки (20-90)"s;
  } else if (rhs.type == number_type::number_100_900) {
    msg += "сотни"s;
  }

  return msg;
}

} // namespace rp