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
const std::string notprefix("no");
const std::string empty("");

TEST(prefixtest, basic_form) {
    ASSERT_TRUE(startswith(message.begin(), message.end(),
                           prefix1.begin(), prefix1.end()));
    ASSERT_TRUE(startswith(message.begin(), message.end(),
                           prefix2.begin(), prefix2.end()));
    ASSERT_FALSE(startswith(message.begin(), message.end(),
                            notprefix.begin(), notprefix.end()));
}
