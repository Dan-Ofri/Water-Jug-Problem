#pragma once
#include <utility>
#include <functional>

using JugState = std::pair<int, int>;

namespace std {
    template <>
    struct hash<JugState> {
        std::size_t operator()(const JugState& s) const noexcept {
            return std::hash<int>()(s.first) ^ (std::hash<int>()(s.second) << 1);
        }
    };
}