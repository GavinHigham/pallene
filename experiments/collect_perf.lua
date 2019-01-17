#!/usr/bin/env lua

local benchlib = require "benchmarks.benchlib"
local mode = benchlib.modes.perf

local nrep = tonumber(arg[1]) or 1

local bench = "matmul"
for __ = 1, nrep do
    for _, NM in ipairs({
        { 100, 1024 },
        { 200,  128 },
        { 400,   16 },
        { 800,    2 },
    }) do
        local N = NM[1]
        local M = NM[2]

        for _, impl in ipairs({
            "pallene",
            "luajit",
        }) do
            local data = benchlib.run_with_impl_name("perf", bench, impl, NM)
            print(table.concat({N, M,  impl, data.time, data.IPC, data.llc_miss_pct}, ","))
        end
    end
end
