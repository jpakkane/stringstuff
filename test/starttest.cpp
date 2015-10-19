/*
 * Copyright 2015 Jussi Pakkanen
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include<string>
#include<gtest/gtest.h>
#include<stringstuff.h>

const std::string message("this is some message");
const std::string prefix1("this");
const std::string prefix2("this is");
const std::string suffix1("message");
const std::string suffix2("some message");
const std::string notprefix("iht");
const std::string notsuffix("egassem");
const std::string empty("");

TEST(prefixtest, basic_form) {
    ASSERT_TRUE(startswith(message.begin(), message.end(),
                           prefix1.begin(), prefix1.end()));
    ASSERT_TRUE(startswith(message.begin(), message.end(),
                           prefix2.begin(), prefix2.end()));
    ASSERT_FALSE(startswith(message.begin(), message.end(),
                            notprefix.begin(), notprefix.end()));
}

TEST(prefixtest, string_adaptor) {
    ASSERT_TRUE(startswith(message, prefix1));
    ASSERT_TRUE(startswith(message, prefix2));
    ASSERT_TRUE(startswith(message, empty));
    ASSERT_FALSE(startswith(message, notprefix));
    ASSERT_FALSE(startswith(prefix1, message));
    ASSERT_TRUE(startswith(empty, empty));
}

TEST(suffixtest, basic) {
    ASSERT_TRUE(endswith(message, suffix1));
    ASSERT_TRUE(endswith(message, suffix2));
    ASSERT_TRUE(endswith(message, empty));
    ASSERT_FALSE(endswith(message, notsuffix));
    ASSERT_FALSE(endswith(suffix1, message));
    ASSERT_TRUE(endswith(empty, empty));
}

TEST(prefixtest, vector) {
    std::vector<char> fulltext{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> little{'a', 'b'};
    std::vector<char> ending{'d', 'e'};
    std::vector<char> fail{'d'};
    std::vector<char> nothing;
    std::string strprefix{"abc"};
    std::string strnotprefix{"cba"};

    ASSERT_TRUE(startswith(fulltext, little));
    ASSERT_FALSE(startswith(little, fulltext));
    ASSERT_FALSE(startswith(fulltext, fail));
    ASSERT_TRUE(startswith(fulltext, nothing));

    ASSERT_TRUE(endswith(fulltext, ending));
    ASSERT_FALSE(endswith(ending, fulltext));
    ASSERT_FALSE(endswith(fulltext, fail));
    ASSERT_TRUE(endswith(fulltext, nothing));

    ASSERT_TRUE(endswith(nothing, nothing));

    // Test mixed.
    ASSERT_TRUE(startswith(fulltext, strprefix));
    ASSERT_FALSE(startswith(fulltext, strnotprefix));
}
