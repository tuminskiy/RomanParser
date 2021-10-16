#include "number_info.hpp"

#include <array>
#include <algorithm>

namespace rp {

using namespace std::string_literals;

static const std::array<const number_info, 36> NUMERS_INFO_TABLE {
  number_info{ number_type::number_1_9, "I"s,     "один"s },
  number_info{ number_type::number_1_9, "II"s,    "два"s },
  number_info{ number_type::number_1_9, "III"s,   "три"s },
  number_info{ number_type::number_1_9, "IV"s,    "четыре"s },
  number_info{ number_type::number_1_9, "V"s,     "пять"s },
  number_info{ number_type::number_1_9, "VI"s,    "шесть"s },
  number_info{ number_type::number_1_9, "VII"s,   "семь"s },
  number_info{ number_type::number_1_9, "VIII"s,  "восемь"s },
  number_info{ number_type::number_1_9, "IX"s,    "девять"s },

  number_info{ number_type::number_10_19, "X"s,     "десять"s },
  number_info{ number_type::number_10_19, "XI"s,    "одиннадцать"s },
  number_info{ number_type::number_10_19, "XII"s,   "двенадцать"s },
  number_info{ number_type::number_10_19, "XIII"s,  "тринадцать"s },
  number_info{ number_type::number_10_19, "XIV"s,   "четырнадцать"s },
  number_info{ number_type::number_10_19, "XV"s,    "пятнадцать"s },
  number_info{ number_type::number_10_19, "XVI"s,   "шестнадцать"s },
  number_info{ number_type::number_10_19, "XVII"s,  "семьнадцать"s },
  number_info{ number_type::number_10_19, "XVIII"s, "восемнадцать"s },
  number_info{ number_type::number_10_19, "XIX"s,   "девятнадцать"s },

  number_info{ number_type::number_20_90, "XX"s,    "двадцать"s },
  number_info{ number_type::number_20_90, "XXX"s,   "тридцать"s },
  number_info{ number_type::number_20_90, "XL"s,    "сорок"s },
  number_info{ number_type::number_20_90, "L"s,     "пятьдесят"s },
  number_info{ number_type::number_20_90, "LX"s,    "шестьдесят"s },
  number_info{ number_type::number_20_90, "LXX"s,   "семьдесят"s },
  number_info{ number_type::number_20_90, "LXXX"s,  "восемьдесят"s },
  number_info{ number_type::number_20_90, "XC"s,    "девяносто"s },

  number_info{ number_type::number_100_900, "C"s,     "сто"s },
  number_info{ number_type::number_100_900, "CC"s,    "двести"s },
  number_info{ number_type::number_100_900, "CCC"s,   "триста"s },
  number_info{ number_type::number_100_900, "CD"s,    "четыреста"s },
  number_info{ number_type::number_100_900, "D"s,     "пятьсот"s },
  number_info{ number_type::number_100_900, "DC"s,    "шестьсот"s },
  number_info{ number_type::number_100_900, "DCC"s,   "семьсот"s },
  number_info{ number_type::number_100_900, "DCCC"s,  "восемьсот"s },
  number_info{ number_type::number_100_900, "CM"s,    "девятьсот"s }
};

number_info get_number_info_by_russian(std::string_view sv) {
  const auto by_rus = [&sv](const number_info& info) { return info.russian == sv; };

  const auto it = std::find_if(std::cbegin(NUMERS_INFO_TABLE), std::cend(NUMERS_INFO_TABLE), by_rus);

  return it != std::cend(NUMERS_INFO_TABLE) ? *it : number_info{};
}

} // namespace rp