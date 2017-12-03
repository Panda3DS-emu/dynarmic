/* This file is part of the dynarmic project.
 * Copyright (c) 2016 MerryMage
 * This software may be used and distributed according to the terms of the GNU
 * General Public License version 2 or any later version.
 */

#pragma once

#include <array>
#include <cstdint>
#include <memory>

namespace Dynarmic {

struct Context {
public:
    Context();
    ~Context();
    Context(const Context&);
    Context(Context&&);
    Context& operator=(const Context&);
    Context& operator=(Context&&);

    /// View and modify registers.
    std::array<std::uint32_t, 16>& Regs();
    const std::array<std::uint32_t, 16>& Regs() const;
    std::array<std::uint32_t, 64>& ExtRegs();
    const std::array<std::uint32_t, 64>& ExtRegs() const;

    /// View and modify CPSR.
    std::uint32_t Cpsr() const;
    void SetCpsr(std::uint32_t value);

    /// View and modify FPSCR.
    std::uint32_t Fpscr() const;
    void SetFpscr(std::uint32_t value);

private:
    friend class Jit;
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace Dynarmic
