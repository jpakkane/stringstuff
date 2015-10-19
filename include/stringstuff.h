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
bool startswith(T1 messagestart, T1 messageend, T2 prefixstart, T2 prefixend) {
    while(messagestart != messageend && prefixstart != prefixend) {
        if(*messagestart != *prefixstart) {
            return false;
        }
        messagestart++;
        prefixstart++;
    }
    return prefixstart == prefixend;
}

template<class T>
bool startswith(const T& message, const T& prefix) {
    return startswith(message.begin(), message.end(), prefix.begin(), prefix.end());
}

template<class T>
bool endswith(const T& message, const T& suffix) {
    return startswith(message.rbegin(), message.rend(), suffix.rbegin(), suffix.rend());
}
