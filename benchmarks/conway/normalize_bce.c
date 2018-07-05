/* This file was generated by the Titan compiler. Do not edit by hand */
/* Indentation and formatting courtesy of titan-compiler/pretty.lua */

#include <string.h>

#include "tcore.h"

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lfunc.h"
#include "lgc.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "lvm.h"

#include "math.h"

static Table * function_new_canvas_titan(
    lua_State * L,
    lua_Integer x1 /* N */,
    lua_Integer x2 /* M */
){
    lua_checkstack(L, 1);
    CClosure * x3 = clCvalue(s2v(L->ci->func));
    Table * x4 /* upvalue table */ = hvalue(&x3->upvalue[0]);
    TValue * x5 /* upvalue array */ = x4->array;
    (void)x5;
    {
        luaC_condGC(L, {
        }, {
        });
        Table * x6 = luaH_new(L);
        luaH_resizearray(L, x6, 0);
        TValue * x7 = x6->array;
        (void) x7;
        Table * x8 /* t */ = x6;
        lua_Integer x9 /* start */ = 1;
        lua_Integer x10 /* finish */ = x1;
        lua_Integer x11 /* inc */ = 1;

        {
            lua_Unsigned bound = x10 - 1;
            if (bound >= x8->sizearray) {
                titan_renormalize_array(L, x8, bound, 10);
            }
        }

        while (x9 <= x10) {
            lua_Integer x12 /* i */ = x9;
            (void) x12;
            {
                luaC_condGC(L, {
                    StackValue* x13 = L->top;
                    sethvalue(L, s2v(x13), x8); x13++;
                    L->top = x13;
                }, {
                    L->top -= 1;
                });
                Table * x14 = luaH_new(L);
                luaH_resizearray(L, x14, 0);
                TValue * x15 = x14->array;
                (void) x15;
                Table * x16 /* line */ = x14;
                lua_Integer x17 /* start */ = 1;
                lua_Integer x18 /* finish */ = x2;
                lua_Integer x19 /* inc */ = 1;

                {
                    lua_Unsigned bound = x18 - 1;
                    if (bound >= x16->sizearray) {
                        titan_renormalize_array(L, x16, bound, 10);
                    }
                }

                while (x17 <= x18) {
                    lua_Integer x20 /* j */ = x17;
                    (void) x20;
                    {
                        lua_Unsigned x21 /* ui */ = ((lua_Unsigned)x20) - 1;
                        TValue * x22 /* slot */ = &x16->array[x21];
                        setivalue(x22, 0);
                    }
                    x17 = intop(+, x17, x19);
                }
                lua_Unsigned x23 /* ui */ = ((lua_Unsigned)x12) - 1;
                TValue * x24 /* slot */ = &x8->array[x23];
                sethvalue(L, x24, x16);
                if (isblack(obj2gco(x8)) && iswhite(obj2gco(x16))) {
                    luaC_barrierback_(L, obj2gco(x8));
                }
            }
            x9 = intop(+, x9, x11);
        }
        return x8;
    }
}

static int function_new_canvas_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 2)) {
        titan_runtime_arity_error(L, 2, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttisinteger(x6))) {
        titan_runtime_argument_type_error(L, "N", 5, LUA_TNUMINT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (TITAN_UNLIKELY(!ttisinteger(x7))) {
        titan_runtime_argument_type_error(L, "M", 5, LUA_TNUMINT, x7);
    }
    lua_Integer x8 = ivalue(s2v(x4 + 1));
    lua_Integer x9 = ivalue(s2v(x4 + 2));
    Table * x10 /* ret */ = function_new_canvas_titan(L, x8, x9);
    sethvalue(L, s2v(L->top), x10);
    api_incr_top(L);
    return 1;
}

static lua_Integer function_wrap_titan(
    lua_State * L,
    lua_Integer x1 /* i */,
    lua_Integer x2 /* N */
){
    CClosure * x3 = clCvalue(s2v(L->ci->func));
    Table * x4 /* upvalue table */ = hvalue(&x3->upvalue[0]);
    TValue * x5 /* upvalue array */ = x4->array;
    (void)x5;
    {
        lua_Integer x6 = intop(-, x1, 1);
        lua_Integer x7;
        if (l_castS2U(x2) + 1u <= 1u) {
            if (x2 == 0){
                titan_runtime_mod_by_zero_error(L, 19);
            } else {
                x7 = 0;
            }
        } else {
            x7 = x6 % x2;
            if (x7 != 0 && (x6 ^ x2) < 0) {
                x7 += x2;
            }
        }
        lua_Integer x8 = intop(+, x7, 1);
        return x8;
    }
}

static int function_wrap_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 2)) {
        titan_runtime_arity_error(L, 2, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttisinteger(x6))) {
        titan_runtime_argument_type_error(L, "i", 18, LUA_TNUMINT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (TITAN_UNLIKELY(!ttisinteger(x7))) {
        titan_runtime_argument_type_error(L, "N", 18, LUA_TNUMINT, x7);
    }
    lua_Integer x8 = ivalue(s2v(x4 + 1));
    lua_Integer x9 = ivalue(s2v(x4 + 2));
    lua_Integer x10 /* ret */ = function_wrap_titan(L, x8, x9);
    setivalue(s2v(L->top), x10);
    api_incr_top(L);
    return 1;
}

static void function_draw_titan(
    lua_State * L,
    lua_Integer x1 /* N */,
    lua_Integer x2 /* M */,
    Table * x3 /* cells */
){
    lua_checkstack(L, 3);
    CClosure * x4 = clCvalue(s2v(L->ci->func));
    Table * x5 /* upvalue table */ = hvalue(&x4->upvalue[0]);
    TValue * x6 /* upvalue array */ = x5->array;
    (void)x6;
    {
        TValue * x7 =  &x6[4] ;
        TString * x8 = tsvalue(x7);
        TString * x9 /* out */ = x8;
        lua_Integer x10 /* start */ = 1;
        lua_Integer x11 /* finish */ = x1;
        lua_Integer x12 /* inc */ = 1;

        {
            lua_Unsigned bound = x11 - 1;
            if (bound >= x3->sizearray) {
                titan_renormalize_array(L, x3, bound, 26);
            }
        }

        while (x10 <= x11) {
            lua_Integer x13 /* i */ = x10;
            (void) x13;
            {
                lua_Unsigned x14 /* ui */ = ((lua_Unsigned)x13) - 1;
                const TValue * x15 /* arrslot */ = &x3->array[x14];
                if (TITAN_UNLIKELY(!ttistable(x15))) {
                    titan_runtime_array_type_error(L, 26, LUA_TTABLE, rawtt(x15));
                }
                Table * x16 = hvalue(x15);
                Table * x17 /* cellsi */ = x16;
                TString * x21;
                {
                    luaC_condGC(L, {
                        StackValue* x18 = L->top;
                        sethvalue(L, s2v(x18), x3); x18++;
                        setsvalue(L, s2v(x18), x9); x18++;
                        sethvalue(L, s2v(x18), x17); x18++;
                        L->top = x18;
                    }, {
                        L->top -= 3;
                    });
                    TString *ss[2];
                    ss[0] = x9;
                    TValue * x19 =  &x6[5] ;
                    TString * x20 = tsvalue(x19);
                    ss[1] = x20;
                    ;
                    x21 = titan_string_concatN(L, 2, ss);
                }
                x9 = x21;
                lua_Integer x22 /* start */ = 1;
                lua_Integer x23 /* finish */ = x2;
                lua_Integer x24 /* inc */ = 1;

                {
                    lua_Unsigned bound = x23 - 1;
                    if (bound >= x17->sizearray) {
                        titan_renormalize_array(L, x17, bound, 29);
                    }
                }

                while (x22 <= x23) {
                    lua_Integer x25 /* j */ = x22;
                    (void) x25;
                    {
                        {
                            lua_Unsigned x30 /* ui */ = ((lua_Unsigned)x25) - 1;
                            const TValue * x31 /* arrslot */ = &x17->array[x30];
                            if (TITAN_UNLIKELY(!ttisinteger(x31))) {
                                titan_runtime_array_type_error(L, 29, LUA_TNUMINT, rawtt(x31));
                            }
                            lua_Integer x32 = ivalue(x31);
                            int x33 = x32 != 0;
                            if (x33) {
                                TString * x37;
                                {
                                    luaC_condGC(L, {
                                        StackValue* x34 = L->top;
                                        sethvalue(L, s2v(x34), x3); x34++;
                                        setsvalue(L, s2v(x34), x9); x34++;
                                        sethvalue(L, s2v(x34), x17); x34++;
                                        L->top = x34;
                                    }, {
                                        L->top -= 3;
                                    });
                                    TString *ss[2];
                                    ss[0] = x9;
                                    TValue * x35 =  &x6[7] ;
                                    TString * x36 = tsvalue(x35);
                                    ss[1] = x36;
                                    ;
                                    x37 = titan_string_concatN(L, 2, ss);
                                }
                                x9 = x37;
                            } else {
                                TString * x29;
                                {
                                    luaC_condGC(L, {
                                        StackValue* x26 = L->top;
                                        sethvalue(L, s2v(x26), x3); x26++;
                                        setsvalue(L, s2v(x26), x9); x26++;
                                        sethvalue(L, s2v(x26), x17); x26++;
                                        L->top = x26;
                                    }, {
                                        L->top -= 3;
                                    });
                                    TString *ss[2];
                                    ss[0] = x9;
                                    TValue * x27 =  &x6[8] ;
                                    TString * x28 = tsvalue(x27);
                                    ss[1] = x28;
                                    ;
                                    x29 = titan_string_concatN(L, 2, ss);
                                }
                                x9 = x29;
                            }
                        }
                    }
                    x22 = intop(+, x22, x24);
                }
                TString * x41;
                {
                    luaC_condGC(L, {
                        StackValue* x38 = L->top;
                        sethvalue(L, s2v(x38), x3); x38++;
                        setsvalue(L, s2v(x38), x9); x38++;
                        sethvalue(L, s2v(x38), x17); x38++;
                        L->top = x38;
                    }, {
                        L->top -= 3;
                    });
                    TString *ss[2];
                    ss[0] = x9;
                    TValue * x39 =  &x6[6] ;
                    TString * x40 = tsvalue(x39);
                    ss[1] = x40;
                    ;
                    x41 = titan_string_concatN(L, 2, ss);
                }
                x9 = x41;
            }
            x10 = intop(+, x10, x12);
        }
        FILE * x42 = stdout; /* TODO: use Lua output file */
        const char * x43 = getstr(x9);
        size_t x44 = tsslen(x9);
        fwrite(x43, sizeof(char), x44, x42);
    }
}

static int function_draw_lua(lua_State *L)
{
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 3)) {
        titan_runtime_arity_error(L, 3, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttisinteger(x6))) {
        titan_runtime_argument_type_error(L, "N", 23, LUA_TNUMINT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (TITAN_UNLIKELY(!ttisinteger(x7))) {
        titan_runtime_argument_type_error(L, "M", 23, LUA_TNUMINT, x7);
    }
    TValue* x8 = s2v(x4 + 3);
    if (TITAN_UNLIKELY(!ttistable(x8))) {
        titan_runtime_argument_type_error(L, "cells", 23, LUA_TTABLE, x8);
    }
    lua_Integer x9 = ivalue(s2v(x4 + 1));
    lua_Integer x10 = ivalue(s2v(x4 + 2));
    Table * x11 = hvalue(s2v(x4 + 3));
    function_draw_titan(L, x9, x10, x11);
    return 0;
}

static void function_spawn_titan(
    lua_State * L,
    lua_Integer x1 /* N */,
    lua_Integer x2 /* M */,
    Table * x3 /* cells */,
    Table * x4 /* shape */,
    lua_Integer x5 /* top */,
    lua_Integer x6 /* left */
){
    lua_checkstack(L, 4);
    CClosure * x7 = clCvalue(s2v(L->ci->func));
    Table * x8 /* upvalue table */ = hvalue(&x7->upvalue[0]);
    TValue * x9 /* upvalue array */ = x8->array;
    (void)x9;
    {
        lua_Integer x11 = luaH_getn(x4);
        lua_Integer x10 /* start */ = 1;
        lua_Integer x12 /* finish */ = x11;
        lua_Integer x13 /* inc */ = 1;

        {
            lua_Unsigned bound = x12 - 1;
            if (bound >= x4->sizearray) {
                titan_renormalize_array(L, x4, bound, 45);
            }
        }

        while (x10 <= x12) {
            lua_Integer x14 /* i */ = x10;
            (void) x14;
            {
                lua_Integer x15 = intop(+, x14, x5);
                lua_Integer x16 = intop(-, x15, 1);
                StackValue* x17 = L->top;
                sethvalue(L, s2v(x17), x3); x17++;
                sethvalue(L, s2v(x17), x4); x17++;
                L->top = x17;
                lua_Integer x18 = function_wrap_titan(L, x16, x1);
                L->top -= 2;
                lua_Integer x19 /* ci */ = x18;
                lua_Unsigned x20 /* ui */ = ((lua_Unsigned)x14) - 1;
                const TValue * x21 /* arrslot */ = &x4->array[x20];
                if (TITAN_UNLIKELY(!ttistable(x21))) {
                    titan_runtime_array_type_error(L, 45, LUA_TTABLE, rawtt(x21));
                }
                Table * x22 = hvalue(x21);
                Table * x23 /* shape_row */ = x22;
                lua_Unsigned x24 /* ui */ = ((lua_Unsigned)x19) - 1;
                if (TITAN_UNLIKELY(x24 >= x3->sizearray)) {
                    titan_renormalize_array(L, x3, x24, 46);
                }
                const TValue * x25 /* arrslot */ = &x3->array[x24];
                if (TITAN_UNLIKELY(!ttistable(x25))) {
                    titan_runtime_array_type_error(L, 46, LUA_TTABLE, rawtt(x25));
                }
                Table * x26 = hvalue(x25);
                Table * x27 /* cell_row */ = x26;
                lua_Integer x29 = luaH_getn(x23);
                lua_Integer x28 /* start */ = 1;
                lua_Integer x30 /* finish */ = x29;
                lua_Integer x31 /* inc */ = 1;

                {
                    lua_Unsigned bound = x30 - 1;
                    if (bound >= x23->sizearray) {
                        titan_renormalize_array(L, x23, bound, 49);
                    }
                }

                while (x28 <= x30) {
                    lua_Integer x32 /* j */ = x28;
                    (void) x32;
                    {
                        lua_Integer x33 = intop(+, x32, x6);
                        lua_Integer x34 = intop(-, x33, 1);
                        StackValue* x35 = L->top;
                        sethvalue(L, s2v(x35), x3); x35++;
                        sethvalue(L, s2v(x35), x4); x35++;
                        sethvalue(L, s2v(x35), x23); x35++;
                        sethvalue(L, s2v(x35), x27); x35++;
                        L->top = x35;
                        lua_Integer x36 = function_wrap_titan(L, x34, x2);
                        L->top -= 4;
                        lua_Integer x37 /* cj */ = x36;
                        lua_Unsigned x38 /* ui */ = ((lua_Unsigned)x32) - 1;
                        const TValue * x39 /* arrslot */ = &x23->array[x38];
                        if (TITAN_UNLIKELY(!ttisinteger(x39))) {
                            titan_runtime_array_type_error(L, 49, LUA_TNUMINT, rawtt(x39));
                        }
                        lua_Integer x40 = ivalue(x39);
                        lua_Unsigned x41 /* ui */ = ((lua_Unsigned)x37) - 1;
                        if (TITAN_UNLIKELY(x41 >= x27->sizearray)) {
                            titan_renormalize_array(L, x27, x41, 49);
                        }
                        TValue * x42 /* slot */ = &x27->array[x41];
                        setivalue(x42, x40);
                    }
                    x28 = intop(+, x28, x31);
                }
            }
            x10 = intop(+, x10, x13);
        }
    }
}

static int function_spawn_lua(lua_State *L)
{
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 6)) {
        titan_runtime_arity_error(L, 6, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttisinteger(x6))) {
        titan_runtime_argument_type_error(L, "N", 41, LUA_TNUMINT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (TITAN_UNLIKELY(!ttisinteger(x7))) {
        titan_runtime_argument_type_error(L, "M", 41, LUA_TNUMINT, x7);
    }
    TValue* x8 = s2v(x4 + 3);
    if (TITAN_UNLIKELY(!ttistable(x8))) {
        titan_runtime_argument_type_error(L, "cells", 41, LUA_TTABLE, x8);
    }
    TValue* x9 = s2v(x4 + 4);
    if (TITAN_UNLIKELY(!ttistable(x9))) {
        titan_runtime_argument_type_error(L, "shape", 41, LUA_TTABLE, x9);
    }
    TValue* x10 = s2v(x4 + 5);
    if (TITAN_UNLIKELY(!ttisinteger(x10))) {
        titan_runtime_argument_type_error(L, "top", 42, LUA_TNUMINT, x10);
    }
    TValue* x11 = s2v(x4 + 6);
    if (TITAN_UNLIKELY(!ttisinteger(x11))) {
        titan_runtime_argument_type_error(L, "left", 42, LUA_TNUMINT, x11);
    }
    lua_Integer x12 = ivalue(s2v(x4 + 1));
    lua_Integer x13 = ivalue(s2v(x4 + 2));
    Table * x14 = hvalue(s2v(x4 + 3));
    Table * x15 = hvalue(s2v(x4 + 4));
    lua_Integer x16 = ivalue(s2v(x4 + 5));
    lua_Integer x17 = ivalue(s2v(x4 + 6));
    function_spawn_titan(L, x12, x13, x14, x15, x16, x17);
    return 0;
}

static void function_step_titan(
    lua_State * L,
    lua_Integer x1 /* N */,
    lua_Integer x2 /* M */,
    Table * x3 /* curr_cells */,
    Table * x4 /* next_cells */
){
    lua_checkstack(L, 6);
    CClosure * x5 = clCvalue(s2v(L->ci->func));
    Table * x6 /* upvalue table */ = hvalue(&x5->upvalue[0]);
    TValue * x7 /* upvalue array */ = x6->array;
    (void)x7;
    {
        lua_Integer x8 /* start */ = 1;
        lua_Integer x9 /* finish */ = x1;
        lua_Integer x10 /* inc */ = 1;

        {
            lua_Unsigned bound = x9 - 1;
            if (bound >= x4->sizearray) {
                titan_renormalize_array(L, x4, bound, 65);
            }
        }

        while (x8 <= x9) {
            lua_Integer x11 /* i2 */ = x8;
            (void) x11;
            {
                lua_Integer x12 = intop(-, x11, 1);
                StackValue* x13 = L->top;
                sethvalue(L, s2v(x13), x3); x13++;
                sethvalue(L, s2v(x13), x4); x13++;
                L->top = x13;
                lua_Integer x14 = function_wrap_titan(L, x12, x1);
                L->top -= 2;
                lua_Integer x15 /* i1 */ = x14;
                lua_Integer x16 = intop(+, x11, 1);
                StackValue* x17 = L->top;
                sethvalue(L, s2v(x17), x3); x17++;
                sethvalue(L, s2v(x17), x4); x17++;
                L->top = x17;
                lua_Integer x18 = function_wrap_titan(L, x16, x1);
                L->top -= 2;
                lua_Integer x19 /* i3 */ = x18;
                lua_Unsigned x20 /* ui */ = ((lua_Unsigned)x15) - 1;
                if (TITAN_UNLIKELY(x20 >= x3->sizearray)) {
                    titan_renormalize_array(L, x3, x20, 61);
                }
                const TValue * x21 /* arrslot */ = &x3->array[x20];
                if (TITAN_UNLIKELY(!ttistable(x21))) {
                    titan_runtime_array_type_error(L, 61, LUA_TTABLE, rawtt(x21));
                }
                Table * x22 = hvalue(x21);
                Table * x23 /* cells1 */ = x22;
                lua_Unsigned x24 /* ui */ = ((lua_Unsigned)x11) - 1;
                if (TITAN_UNLIKELY(x24 >= x3->sizearray)) {
                    titan_renormalize_array(L, x3, x24, 62);
                }
                const TValue * x25 /* arrslot */ = &x3->array[x24];
                if (TITAN_UNLIKELY(!ttistable(x25))) {
                    titan_runtime_array_type_error(L, 62, LUA_TTABLE, rawtt(x25));
                }
                Table * x26 = hvalue(x25);
                Table * x27 /* cells2 */ = x26;
                lua_Unsigned x28 /* ui */ = ((lua_Unsigned)x19) - 1;
                if (TITAN_UNLIKELY(x28 >= x3->sizearray)) {
                    titan_renormalize_array(L, x3, x28, 63);
                }
                const TValue * x29 /* arrslot */ = &x3->array[x28];
                if (TITAN_UNLIKELY(!ttistable(x29))) {
                    titan_runtime_array_type_error(L, 63, LUA_TTABLE, rawtt(x29));
                }
                Table * x30 = hvalue(x29);
                Table * x31 /* cells3 */ = x30;
                lua_Unsigned x32 /* ui */ = ((lua_Unsigned)x11) - 1;
                const TValue * x33 /* arrslot */ = &x4->array[x32];
                if (TITAN_UNLIKELY(!ttistable(x33))) {
                    titan_runtime_array_type_error(L, 65, LUA_TTABLE, rawtt(x33));
                }
                Table * x34 = hvalue(x33);
                Table * x35 /* next2 */ = x34;
                lua_Integer x36 /* start */ = 1;
                lua_Integer x37 /* finish */ = x2;
                lua_Integer x38 /* inc */ = 1;

                {
                    lua_Unsigned bound = 0;
                    if (bound >= x35->sizearray) {
                        titan_renormalize_array(L, x35, bound, 89);
                    }
                }

                while (x36 <= x37) {
                    lua_Integer x39 /* j2 */ = x36;
                    (void) x39;
                    {
                        lua_Integer x40 = intop(-, x39, 1);
                        StackValue* x41 = L->top;
                        sethvalue(L, s2v(x41), x3); x41++;
                        sethvalue(L, s2v(x41), x4); x41++;
                        sethvalue(L, s2v(x41), x23); x41++;
                        sethvalue(L, s2v(x41), x27); x41++;
                        sethvalue(L, s2v(x41), x31); x41++;
                        sethvalue(L, s2v(x41), x35); x41++;
                        L->top = x41;
                        lua_Integer x42 = function_wrap_titan(L, x40, x2);
                        L->top -= 6;
                        lua_Integer x43 /* j1 */ = x42;
                        lua_Integer x44 = intop(+, x39, 1);
                        StackValue* x45 = L->top;
                        sethvalue(L, s2v(x45), x3); x45++;
                        sethvalue(L, s2v(x45), x4); x45++;
                        sethvalue(L, s2v(x45), x23); x45++;
                        sethvalue(L, s2v(x45), x27); x45++;
                        sethvalue(L, s2v(x45), x31); x45++;
                        sethvalue(L, s2v(x45), x35); x45++;
                        L->top = x45;
                        lua_Integer x46 = function_wrap_titan(L, x44, x2);
                        L->top -= 6;
                        lua_Integer x47 /* j3 */ = x46;
                        lua_Unsigned x48 /* ui */ = ((lua_Unsigned)x43) - 1;
                        if (TITAN_UNLIKELY(x48 >= x23->sizearray)) {
                            titan_renormalize_array(L, x23, x48, 71);
                        }
                        const TValue * x49 /* arrslot */ = &x23->array[x48];
                        if (TITAN_UNLIKELY(!ttisinteger(x49))) {
                            titan_runtime_array_type_error(L, 71, LUA_TNUMINT, rawtt(x49));
                        }
                        lua_Integer x50 = ivalue(x49);
                        lua_Integer x51 /* c11 */ = x50;
                        lua_Unsigned x52 /* ui */ = ((lua_Unsigned)x39) - 1;
                        if (TITAN_UNLIKELY(x52 >= x23->sizearray)) {
                            titan_renormalize_array(L, x23, x52, 72);
                        }
                        const TValue * x53 /* arrslot */ = &x23->array[x52];
                        if (TITAN_UNLIKELY(!ttisinteger(x53))) {
                            titan_runtime_array_type_error(L, 72, LUA_TNUMINT, rawtt(x53));
                        }
                        lua_Integer x54 = ivalue(x53);
                        lua_Integer x55 /* c12 */ = x54;
                        lua_Unsigned x56 /* ui */ = ((lua_Unsigned)x47) - 1;
                        if (TITAN_UNLIKELY(x56 >= x23->sizearray)) {
                            titan_renormalize_array(L, x23, x56, 73);
                        }
                        const TValue * x57 /* arrslot */ = &x23->array[x56];
                        if (TITAN_UNLIKELY(!ttisinteger(x57))) {
                            titan_runtime_array_type_error(L, 73, LUA_TNUMINT, rawtt(x57));
                        }
                        lua_Integer x58 = ivalue(x57);
                        lua_Integer x59 /* c13 */ = x58;
                        lua_Unsigned x60 /* ui */ = ((lua_Unsigned)x43) - 1;
                        if (TITAN_UNLIKELY(x60 >= x27->sizearray)) {
                            titan_renormalize_array(L, x27, x60, 75);
                        }
                        const TValue * x61 /* arrslot */ = &x27->array[x60];
                        if (TITAN_UNLIKELY(!ttisinteger(x61))) {
                            titan_runtime_array_type_error(L, 75, LUA_TNUMINT, rawtt(x61));
                        }
                        lua_Integer x62 = ivalue(x61);
                        lua_Integer x63 /* c21 */ = x62;
                        lua_Unsigned x64 /* ui */ = ((lua_Unsigned)x39) - 1;
                        if (TITAN_UNLIKELY(x64 >= x27->sizearray)) {
                            titan_renormalize_array(L, x27, x64, 76);
                        }
                        const TValue * x65 /* arrslot */ = &x27->array[x64];
                        if (TITAN_UNLIKELY(!ttisinteger(x65))) {
                            titan_runtime_array_type_error(L, 76, LUA_TNUMINT, rawtt(x65));
                        }
                        lua_Integer x66 = ivalue(x65);
                        lua_Integer x67 /* c22 */ = x66;
                        lua_Unsigned x68 /* ui */ = ((lua_Unsigned)x47) - 1;
                        if (TITAN_UNLIKELY(x68 >= x27->sizearray)) {
                            titan_renormalize_array(L, x27, x68, 77);
                        }
                        const TValue * x69 /* arrslot */ = &x27->array[x68];
                        if (TITAN_UNLIKELY(!ttisinteger(x69))) {
                            titan_runtime_array_type_error(L, 77, LUA_TNUMINT, rawtt(x69));
                        }
                        lua_Integer x70 = ivalue(x69);
                        lua_Integer x71 /* c23 */ = x70;
                        lua_Unsigned x72 /* ui */ = ((lua_Unsigned)x43) - 1;
                        if (TITAN_UNLIKELY(x72 >= x31->sizearray)) {
                            titan_renormalize_array(L, x31, x72, 79);
                        }
                        const TValue * x73 /* arrslot */ = &x31->array[x72];
                        if (TITAN_UNLIKELY(!ttisinteger(x73))) {
                            titan_runtime_array_type_error(L, 79, LUA_TNUMINT, rawtt(x73));
                        }
                        lua_Integer x74 = ivalue(x73);
                        lua_Integer x75 /* c31 */ = x74;
                        lua_Unsigned x76 /* ui */ = ((lua_Unsigned)x39) - 1;
                        if (TITAN_UNLIKELY(x76 >= x31->sizearray)) {
                            titan_renormalize_array(L, x31, x76, 80);
                        }
                        const TValue * x77 /* arrslot */ = &x31->array[x76];
                        if (TITAN_UNLIKELY(!ttisinteger(x77))) {
                            titan_runtime_array_type_error(L, 80, LUA_TNUMINT, rawtt(x77));
                        }
                        lua_Integer x78 = ivalue(x77);
                        lua_Integer x79 /* c32 */ = x78;
                        lua_Unsigned x80 /* ui */ = ((lua_Unsigned)x47) - 1;
                        if (TITAN_UNLIKELY(x80 >= x31->sizearray)) {
                            titan_renormalize_array(L, x31, x80, 81);
                        }
                        const TValue * x81 /* arrslot */ = &x31->array[x80];
                        if (TITAN_UNLIKELY(!ttisinteger(x81))) {
                            titan_runtime_array_type_error(L, 81, LUA_TNUMINT, rawtt(x81));
                        }
                        lua_Integer x82 = ivalue(x81);
                        lua_Integer x83 /* c33 */ = x82;
                        lua_Integer x84 = intop(+, x51, x55);
                        lua_Integer x85 = intop(+, x84, x59);
                        lua_Integer x86 = intop(+, x85, x63);
                        lua_Integer x87 = intop(+, x86, x71);
                        lua_Integer x88 = intop(+, x87, x75);
                        lua_Integer x89 = intop(+, x88, x79);
                        lua_Integer x90 = intop(+, x89, x83);
                        lua_Integer x91 /* sum */ = x90;
                        {
                            int x94 = x91 == 3;
                            int x95 = x94;
                            if (!x95) {
                                int x96 = x91 == 2;
                                int x97 = x96;
                                if (x97) {
                                    int x98 = x67 == 1;
                                    x97 = x98;
                                }
                                x95 = x97;
                            }
                            if (x95) {
                                lua_Unsigned x99 /* ui */ = ((lua_Unsigned)x39) - 1;
                                TValue * x100 /* slot */ = &x35->array[x99];
                                setivalue(x100, 1);
                            } else {
                                lua_Unsigned x92 /* ui */ = ((lua_Unsigned)x39) - 1;
                                TValue * x93 /* slot */ = &x35->array[x92];
                                setivalue(x93, 0);
                            }
                        }
                    }
                    x36 = intop(+, x36, x38);
                }
            }
            x8 = intop(+, x8, x10);
        }
    }
}

static int function_step_lua(lua_State *L)
{
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 4)) {
        titan_runtime_arity_error(L, 4, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttisinteger(x6))) {
        titan_runtime_argument_type_error(L, "N", 55, LUA_TNUMINT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (TITAN_UNLIKELY(!ttisinteger(x7))) {
        titan_runtime_argument_type_error(L, "M", 55, LUA_TNUMINT, x7);
    }
    TValue* x8 = s2v(x4 + 3);
    if (TITAN_UNLIKELY(!ttistable(x8))) {
        titan_runtime_argument_type_error(L, "curr_cells", 55, LUA_TTABLE, x8);
    }
    TValue* x9 = s2v(x4 + 4);
    if (TITAN_UNLIKELY(!ttistable(x9))) {
        titan_runtime_argument_type_error(L, "next_cells", 56, LUA_TTABLE, x9);
    }
    lua_Integer x10 = ivalue(s2v(x4 + 1));
    lua_Integer x11 = ivalue(s2v(x4 + 2));
    Table * x12 = hvalue(s2v(x4 + 3));
    Table * x13 = hvalue(s2v(x4 + 4));
    function_step_titan(L, x10, x11, x12, x13);
    return 0;
}

int luaopen_benchmarks_conway_normalize_bce(lua_State *L)
{
    lua_checkstack(L, 4);
    /* Allocate upvalue table */
    /* ---------------------- */
    Table * x1 = luaH_new(L);
    luaH_resizearray(L, x1, 14);
    TValue * x2 = x1->array;
    /* Initialize upvalues */
    /* ------------------- */
    TString * x3 = luaS_new(L, "__index");
    setsvalue(L,  &x2[0] , x3);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x3))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x4 = luaS_new(L, "__metatable");
    setsvalue(L,  &x2[1] , x4);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x4))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x5 = luaS_new(L, "*");
    setsvalue(L,  &x2[2] , x5);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x5))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x6 = luaS_new(L, " ");
    setsvalue(L,  &x2[3] , x6);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x6))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x7 = luaS_new(L, "");
    setsvalue(L,  &x2[4] , x7);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x7))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x8 = luaS_new(L, "|");
    setsvalue(L,  &x2[5] , x8);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x8))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x9 = luaS_new(L, "|\n");
    setsvalue(L,  &x2[6] , x9);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x9))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* ALIVE */
    TValue * x10 =  &x2[2] ;
    TString * x11 = tsvalue(x10);
    setsvalue(L,  &x2[7] , x11);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x11))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* DEAD */
    TValue * x12 =  &x2[3] ;
    TString * x13 = tsvalue(x12);
    setsvalue(L,  &x2[8] , x13);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x13))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* new_canvas */
    CClosure* x14 = luaF_newCclosure(L, 1);
    x14->f = function_new_canvas_lua;
    sethvalue(L, &x14->upvalue[0], x1);
    TValue x15; setclCvalue(L, &x15, x14);
    setobj(L,  &x2[9] , &x15);
    if (iscollectable(&x15) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x15))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* wrap */
    CClosure* x16 = luaF_newCclosure(L, 1);
    x16->f = function_wrap_lua;
    sethvalue(L, &x16->upvalue[0], x1);
    TValue x17; setclCvalue(L, &x17, x16);
    setobj(L,  &x2[10] , &x17);
    if (iscollectable(&x17) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x17))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* draw */
    CClosure* x18 = luaF_newCclosure(L, 1);
    x18->f = function_draw_lua;
    sethvalue(L, &x18->upvalue[0], x1);
    TValue x19; setclCvalue(L, &x19, x18);
    setobj(L,  &x2[11] , &x19);
    if (iscollectable(&x19) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x19))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* spawn */
    CClosure* x20 = luaF_newCclosure(L, 1);
    x20->f = function_spawn_lua;
    sethvalue(L, &x20->upvalue[0], x1);
    TValue x21; setclCvalue(L, &x21, x20);
    setobj(L,  &x2[12] , &x21);
    if (iscollectable(&x21) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x21))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* step */
    CClosure* x22 = luaF_newCclosure(L, 1);
    x22->f = function_step_lua;
    sethvalue(L, &x22->upvalue[0], x1);
    TValue x23; setclCvalue(L, &x23, x22);
    setobj(L,  &x2[13] , &x23);
    if (iscollectable(&x23) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x23))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* Create exports table */
    /* -------------------- */
    StackValue* x24 = L->top;
    sethvalue(L, s2v(x24), x1); x24++;
    L->top = x24;
    lua_createtable(L, 0, 5);
    lua_pushstring(L, "new_canvas");
    setobj(L, s2v(L->top),  &x2[9] ); api_incr_top(L);
    lua_settable(L, -3);
    lua_pushstring(L, "wrap");
    setobj(L, s2v(L->top),  &x2[10] ); api_incr_top(L);
    lua_settable(L, -3);
    lua_pushstring(L, "draw");
    setobj(L, s2v(L->top),  &x2[11] ); api_incr_top(L);
    lua_settable(L, -3);
    lua_pushstring(L, "spawn");
    setobj(L, s2v(L->top),  &x2[12] ); api_incr_top(L);
    lua_settable(L, -3);
    lua_pushstring(L, "step");
    setobj(L, s2v(L->top),  &x2[13] ); api_incr_top(L);
    lua_settable(L, -3);
    return 1;
}

