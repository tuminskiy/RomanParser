#include <boost/test/unit_test.hpp>
#include <string_view>

#include "number_info.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;


BOOST_AUTO_TEST_CASE(number_100_test) {
  const auto sv = "сто"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "C"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_200_test) {
  const auto sv = "двести"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "CC"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_300_test) {
  const auto sv = "триста"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "CCC"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_400_test) {
  const auto sv = "четыреста"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "CD"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_500_test) {
  const auto sv = "пятьсот"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "D"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_600_test) {
  const auto sv = "шестьсот"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "DC"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_700_test) {
  const auto sv = "семьсот"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "DCC"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_800_test) {
  const auto sv = "восемьсот"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "DCCC"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_900_test) {
  const auto sv = "девятьсот"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_100_900);
  BOOST_REQUIRE_EQUAL(info.roman, "CM"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}