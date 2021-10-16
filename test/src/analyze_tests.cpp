#include <boost/test/unit_test.hpp>
#include <string_view>

#include "analyze.hpp"

using namespace std::string_literals;
using namespace std::string_view_literals;


BOOST_AUTO_TEST_CASE(analyze_unknow_test) {
  const std::vector<rp::token> tokens = { rp::token{ "unknow"s } };

  const auto result = rp::analyze(cbegin(tokens), cend(tokens));

  BOOST_REQUIRE(!result.success);
  BOOST_REQUIRE_EQUAL(result.msg, "Неизвестная лексема 'unknow'"sv);
}

BOOST_AUTO_TEST_CASE(analyze_1_10_test) {
  const std::vector<rp::token> tokens = {
    rp::token{
      rp::number_info{ rp::number_type::number_1_9, "один"s, "I"s }
    },
    rp::token{
      rp::number_info{ rp::number_type::number_10_19, "десять"s, "X"s }
    }
  };

  const auto result = rp::analyze(cbegin(tokens), cend(tokens));

  BOOST_REQUIRE(!result.success);
  BOOST_REQUIRE_EQUAL(result.msg, "После единиц не должны идти десятки (10-19)"s);
}

BOOST_AUTO_TEST_CASE(analyze_10_10_test) {
  const std::vector<rp::token> tokens = {
    rp::token{
      rp::number_info{ rp::number_type::number_10_19, "десять"s, "X"s }
    },
    rp::token{
      rp::number_info{ rp::number_type::number_10_19, "десять"s, "X"s }
    }
  };

  const auto result = rp::analyze(cbegin(tokens), cend(tokens));

  BOOST_REQUIRE(!result.success);
  BOOST_REQUIRE_EQUAL(result.msg, "После десяток (10-19) не должны идти десятки (10-19)"s);
}