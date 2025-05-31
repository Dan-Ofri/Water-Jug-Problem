#pragma once
#include <utility>
#include <functional>

// Represents the state of the two jugs: (amount in large jug, amount in small jug)
using JugState = std::pair<int, int>;

namespace std {
    // Hash for JugState to allow use in unordered map and set
    template <>
    struct hash<JugState> {
        std::size_t operator()(const JugState& s) const noexcept {
            return std::hash<int>()(s.first) ^ (std::hash<int>()(s.second) << 1);
        }
    };
}