#include <boost/test/unit_test.hpp>
#include <string_view>

#include "number_info.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;


BOOST_AUTO_TEST_CASE(number_10_test) {
  const auto sv = "десять"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "X"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_11_test) {
  const auto sv = "одиннадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XI"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_12_test) {
  const auto sv = "двенадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XII"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_13_test) {
  const auto sv = "тринадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XIII"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_14_test) {
  const auto sv = "четырнадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XIV"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_15_test) {
  const auto sv = "пятнадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XV"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_16_test) {
  const auto sv = "шестнадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XVI"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_17_test) {
  const auto sv = "семьнадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XVII"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_18_test) {
  const auto sv = "восемнадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XVIII"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}

BOOST_AUTO_TEST_CASE(number_19_test) {
  const auto sv = "девятнадцать"sv;

  const auto info = rp::get_number_info_by_russian(sv);

  BOOST_REQUIRE(info.type == rp::number_type::number_10_19);
  BOOST_REQUIRE_EQUAL(info.roman, "XIX"s);
  BOOST_REQUIRE_EQUAL(info.russian, sv);
}