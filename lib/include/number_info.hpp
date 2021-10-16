#pragma once

#include <string>
#include <optional>

#include "number_type.hpp"

namespace rp {

struct number_info {
  number_type type{};
  std::string roman{};
  std::string russian{};
};

number_info get_number_info_by_russian(std::string_view sv);

} // namespace rp

