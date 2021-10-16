#include <boost/test/unit_test.hpp>
#include <string_view>

#include "number_info.hpp"
#include "tokenize.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;

template<class... Ts> struct overloaded : Ts... {
  using Ts::operator()...;
};

template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

BOOST_AUTO_TEST_CASE(tokenize_1_test) {
  const std::vector<std::string_view> data = { "один"sv };

  std::vector<rp::token> tokens(1);
  rp::tokenize(std::cbegin(data), std::cend(data), std::begin(tokens));


  const auto assert_visitor = overloaded {
    [](const rp::number_info& info) {
      BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
      BOOST_REQUIRE_EQUAL(info.russian, "один"sv);
      BOOST_REQUIRE_EQUAL(info.roman, "I"sv);
    },
    [](const std::string& str) { BOOST_REQUIRE_MESSAGE(false, "token must be rp::number_info"s); },
    [](auto other) { BOOST_REQUIRE_MESSAGE(false, "Unhandled token"); }
  };

  std::visit(assert_visitor, tokens.front());
}

BOOST_AUTO_TEST_CASE(tokenize_unknow_test) {
  const std::vector<std::string_view> data = { "unknow"sv };

  std::vector<rp::token> tokens(1);
  rp::tokenize(std::cbegin(data), std::cend(data), std::begin(tokens));


  const auto assert_visitor = overloaded {
    [](const rp::number_info& info) { BOOST_REQUIRE_MESSAGE(false, "token not must be rp::number_info"); },
    [](const std::string& str) { BOOST_REQUIRE_EQUAL(str, "unknow"sv); },
    [](auto other) { BOOST_REQUIRE_MESSAGE(false, "Unhandled token"); }
  };

  std::visit(assert_visitor, tokens.front());
}

BOOST_AUTO_TEST_CASE(tokenize_1_unknow_test) {
  const std::vector<std::string_view> data = { "один", "unknow"sv };

  std::vector<rp::token> tokens(2);
  rp::tokenize(std::cbegin(data), std::cend(data), std::begin(tokens));


  const auto assert_visitor_front = overloaded {
    [](const rp::number_info& info) {
      BOOST_REQUIRE(info.type == rp::number_type::number_1_9);
      BOOST_REQUIRE_EQUAL(info.russian, "один"sv);
      BOOST_REQUIRE_EQUAL(info.roman, "I"sv);
    },
    [](const std::string& str) { BOOST_REQUIRE_MESSAGE(false, "token must be rp::number_info"s); },
    [](auto other) { BOOST_REQUIRE_MESSAGE(false, "Unhandled token"); }
  };

  const auto assert_visitor_back = overloaded {
    [](const rp::number_info& info) { BOOST_REQUIRE_MESSAGE(false, "token not must be rp::number_info"); },
    [](const std::string& str) { BOOST_REQUIRE_EQUAL(str, "unknow"sv); },
    [](auto other) { BOOST_REQUIRE_MESSAGE(false, "Unhandled token"); }
  };

  std::visit(assert_visitor_front, tokens.front());
  std::visit(assert_visitor_back, tokens.back());
}