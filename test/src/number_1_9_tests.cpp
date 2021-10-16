#include <boost/test/unit_test.hpp>
#include <string_view>

#include "number_info.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;


BOOST_AUTO_TEST_CASE(number_1_test) {
  const auto sv = "один"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "I"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_2_test) {
  const auto sv = "два"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "II"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_3_test) {
  const auto sv = "три"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "III"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_4_test) {
  const auto sv = "четыре"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "IV"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_5_test) {
  const auto sv = "пять"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "V"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_6_test) {
  const auto sv = "шесть"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "VI"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_7_test) {
  const auto sv = "семь"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "VII"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_8_test) {
  const auto sv = "восемь"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "VIII"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_9_test) {
  const auto sv = "девять"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
  BOOST_REQUIRE_EQUAL(info.roman, "IX"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}