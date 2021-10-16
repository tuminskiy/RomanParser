#pragma once

#include "tokenize.hpp"
#include "rule.hpp"

namespace rp {

std::string get_error_msg(const number_info& lhs, const number_info& rhs);

struct analyze_result {
  std::string msg{};
  bool success{};
};


template <class It>
analyze_result analyze(It first, It last) {
  {
    using value_t = typename It::value_type;

    constexpr bool is_token = std::is_same_v<value_t, token>;

    static_assert(is_token, "It::value_type must be rp::token");
  }

  using namespace std::string_literals;

  auto it = rule::all_tokens_is_number_info(first, last);

  if (it != last) {
    const auto msg = "Неизвестная лексема \'"s + std::get<std::string>(*it) + "\'"s;
    return { std::move(msg), false };
  }

  it = rule::number_info_sequence_is_valid(first, last);

  if (it != last) {
    const auto& lhs = std::get<number_info>(*it);
    const auto& rhs = std::get<number_info>(*std::next(it));

    return { get_error_msg(lhs, rhs), false };
  }

  return {""s, true};
}


} // namespace rp