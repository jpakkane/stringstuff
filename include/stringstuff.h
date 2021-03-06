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

#pragma once

template<class T1, class T2>
bool startswith(T1 messagestart, const T1 messageend, T2 prefixstart, const T2 prefixend) {
    while(messagestart != messageend && prefixstart != prefixend) {
        if(*messagestart != *prefixstart) {
            return false;
        }
        messagestart++;
        prefixstart++;
    }
    return prefixstart == prefixend;
}

template<class T1, class T2>
bool startswith(const T1& message, const T2& prefix) {
    return startswith(message.cbegin(), message.cend(), prefix.cbegin(), prefix.cend());
}

template<class T1, class T2>
bool endswith(const T1& message, const T2& suffix) {
    return startswith(message.crbegin(), message.crend(), suffix.crbegin(), suffix.crend());
}

// Sequence splitter.

template<typename T>
static bool is_whitespace_internal(T c) {
    if(c == ' ' or c == '\n' or c == '\t' or c == '\r')
        return true;
    return false;
}

template<class T1, class T2>
void split(T1 sstart, T1 send, T2 inserter) {
    while(sstart != send) {
        auto curchar = *sstart;
        if(is_whitespace_internal(curchar)) {
            do {
                sstart++;
            } while(sstart != send and is_whitespace_internal(*sstart));
        } else {
            auto curstart = sstart;
            do {
                sstart++;
            } while(sstart != send and not is_whitespace_internal(*sstart));
            *inserter = typename T2::container_type::value_type(curstart, sstart);
            inserter++;
        }
    }
}

template<class T1, class T2>
void split(const T1 &sequence, T2 inserter) {
    split(sequence.cbegin(), sequence.cend(), inserter);
}
