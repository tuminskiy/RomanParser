#pragma once

#include "number_info.hpp"

#include <algorithm>
#include <type_traits>
#include <variant>

namespace rp {

using token = std::variant<number_info, std::string>;

template <class InputIt, class OutputIt>
OutputIt tokenize(InputIt first, InputIt last, OutputIt out_it) {
  {
    using input_value_type = typename InputIt::value_type;
    using output_value_type = typename OutputIt::value_type;

    constexpr bool is_string_or_string_view =
      std::is_same_v<input_value_type, std::string> || std::is_same_v<input_value_type, std::string_view>;

    constexpr bool is_token = std::is_same_v<output_value_type, token>;

    static_assert(is_string_or_string_view, "InputIterator::value_type must be std::string or std::string_view");
    static_assert(is_token, "OutputIterator::value_type must be rp::token");
  }

  const auto transformer = [](std::string_view sv) {
    const auto info = get_number_info_by_russian(sv);

    return info.type != number_type::unknow
      ? token{ info }
      : token{ std::string{ sv } };
  };

  return std::transform(first, last, out_it, transformer);
}


} // namespace rp