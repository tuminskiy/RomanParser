#include <boost/test/unit_test.hpp>
#include <string_view>

#include "number_info.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;


BOOST_AUTO_TEST_CASE(number_20_test) {
  const auto sv = "двадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_20_90);
  BOOST_REQUIRE_EQUAL(info.roman, "XX"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_30_test) {
  const auto sv = "тридцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_20_90);
  BOOST_REQUIRE_EQUAL(info.roman, "XXX"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_40_test) {
  const auto sv = "сорок"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_20_90);
  BOOST_REQUIRE_EQUAL(info.roman, "XL"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_50_test) {
  const auto sv = "пятьдесят"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_20_90);
  BOOST_REQUIRE_EQUAL(info.roman, "L"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_60_test) {
  const auto sv = "шестьдесят"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_20_90);
  BOOST_REQUIRE_EQUAL(info.roman, "LX"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_70_test) {
  const auto sv = "семьдесят"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_20_90);
  BOOST_REQUIRE_EQUAL(info.roman, "LXX"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_80_test) {
  const auto sv = "восемьдесят"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_20_90);
  BOOST_REQUIRE_EQUAL(info.roman, "LXXX"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_90_test) {
  const auto sv = "девяносто"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_20_90);
  BOOST_REQUIRE_EQUAL(info.roman, "XC"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}
