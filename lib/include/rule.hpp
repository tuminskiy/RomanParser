#pragma once

#include "tokenize.hpp"

#include <functional>

namespace rp::rule {

template<class... Ts> struct overloaded : Ts... {
  using Ts::operator()...;
};

template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;


template <class It>
It all_tokens_is_number_info(It first, It last) {
  const auto is_number_info = [](const token& t) {
    const auto visitor = overloaded {
      [](const number_info& info) { return true; },
      [](const std::string& str) { return false; }
    };

    return std::visit(visitor, t);
  };

  return std::find_if_not(first, last, is_number_info);
}

template <class It>
It number_info_sequence_is_valid(It first, It last) {
  const auto is_not_valid = [](const token& lhs, const token& rhs) {
    const auto& lhs_info = std::get<number_info>(lhs);
    const auto& rhs_info = std::get<number_info>(rhs);

    return lhs_info.type <= rhs_info.type
        || lhs_info.type == number_type::number_10_19;
  };

  return std::adjacent_find(first, last, is_not_valid);
}

} // namespace rp::rule