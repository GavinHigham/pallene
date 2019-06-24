local types = require "pallene.types"

describe("Pallene types", function()

    it("pretty-prints types", function()
        assert.same("{ integer }", types.tostring(types.T.Array(types.T.Integer())))
    end)

    it("is_gc works", function()
        assert.falsy(types.is_gc(types.T.Integer()))
        assert.truthy(types.is_gc(types.T.String()))
        assert.truthy(types.is_gc(types.T.Array(types.T.Integer())))
        assert.truthy(types.is_gc(types.T.Function({}, {})))
    end)

    describe("equality", function()

        it("works for primitive types", function()
            assert.truthy(types.equals(types.T.Integer(), types.T.Integer()))
            assert.falsy(types.equals(types.T.Integer(), types.T.String()))
        end)

        it("is true for identical functions", function()
            local f1 = types.T.Function({types.T.String(), types.T.Integer()}, {types.T.Boolean()})
            local f2 = types.T.Function({types.T.String(), types.T.Integer()}, {types.T.Boolean()})
            assert.truthy(types.equals(f1, f2))
        end)

        it("is false for functions with different input types", function()
            local f1 = types.T.Function({types.T.String(), types.T.Boolean()}, {types.T.Boolean()})
            local f2 = types.T.Function({types.T.Integer(), types.T.Integer()}, {types.T.Boolean()})
            assert.falsy(types.equals(f1, f2))
        end)

        it("is false for functions with different output types", function()
            local f1 = types.T.Function({types.T.String(), types.T.Integer()}, {types.T.Boolean()})
            local f2 = types.T.Function({types.T.String(), types.T.Integer()}, {types.T.Integer()})
            assert.falsy(types.equals(f1, f2))
        end)

        it("is false for functions with different input arity", function()
            local s = types.T.String()
            local f1 = types.T.Function({}, {s})
            local f2 = types.T.Function({s}, {s})
            local f3 = types.T.Function({s, s}, {s})
            assert.falsy(types.equals(f1, f2))
            assert.falsy(types.equals(f1, f3))
            assert.falsy(types.equals(f2, f1))
            assert.falsy(types.equals(f2, f3))
            assert.falsy(types.equals(f3, f1))
            assert.falsy(types.equals(f3, f2))
        end)

        it("is false for functions with different output arity", function()
            local s = types.T.String()
            local f1 = types.T.Function({s}, {})
            local f2 = types.T.Function({s}, {s})
            local f3 = types.T.Function({s}, {s, s})
            assert.falsy(types.equals(f1, f2))
            assert.falsy(types.equals(f1, f3))
            assert.falsy(types.equals(f2, f1))
            assert.falsy(types.equals(f2, f3))
            assert.falsy(types.equals(f3, f1))
            assert.falsy(types.equals(f3, f2))
        end)

        it("is true for identical record types", function()
            local t = types.T.Record("P", {}, {})
            assert.truthy(types.equals(t, t))
        end)

        it("is false for different record types", function()
            local t1 = types.T.Record("P", {}, {})
            local t2 = types.T.Record("P", {}, {})
            assert.falsy(types.equals(t1, t2))
        end)
    end)

    describe("consistency", function()
        it("it always true for value", function()
            assert.truthy(types.consistent(types.T.Value(), types.T.Value()))
            assert.truthy(types.consistent(types.T.Value(), types.T.Integer()))
            assert.truthy(types.consistent(types.T.Integer(), types.T.Value()))
        end)

        it("works for arrays", function()
            local t1 = types.T.Array(types.T.Value())
            local t2 = types.T.Array(types.T.Integer())
            local t3 = types.T.Array(types.T.Array(types.T.Integer))
            assert.truthy(types.consistent(t1, t2))
            assert.truthy(types.consistent(t1, t3))
            assert.falsy(types.consistent(t2, t3))
        end)

        it("works for functions with same arity", function()
            local v = types.T.Value()
            local i = types.T.Integer()
            local s = types.T.String()
            local f1 = types.T.Function({v, v}, {v})
            local f2 = types.T.Function({i, i}, {i})
            local f3 = types.T.Function({s, s}, {s})
            assert.truthy(types.consistent(f1, f2))
            assert.truthy(types.consistent(f1, f3))
            assert.falsy(types.consistent(f2, f3))
        end)
    end)
end)
