/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/static_assert.hpp>
#include <boost/hana/ext/std/integral_constant.hpp>
#include <boost/hana/functional.hpp>
#include <boost/hana/type.hpp>

#include <type_traits>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_LAMBDA auto safe_make_unsigned = [](auto t) {
        return eval_if(trait<std::is_integral>(t),
            [=](auto id) { return id(template_<std::make_unsigned_t>)(t); },
            always(t)
        );
    };

    BOOST_HANA_STATIC_ASSERT(safe_make_unsigned(type<void>) == type<void>);
    BOOST_HANA_STATIC_ASSERT(safe_make_unsigned(type<int>) == type<unsigned int>);
    //! [main]
}
