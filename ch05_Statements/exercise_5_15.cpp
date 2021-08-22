/*
 * 说明下列循环的含义并改正其中的错误。
 *
 * (a) for (int ix = 0; ix != sz; ++ix) { ... }
 *        if (ix != sz)
 *            // ...
 *
 * (b) int ix;
 *     for (ix != sz; ++ix) { ... }
 *
 * (c) for (int ix = 0; ix != sz; ++ix, ++sz) { ... }
 */

/*
 * (a) int x
 *     for (ix = 0; ix != sz; ++ix) { ... }
 *        if (ix != sz)
 *            // ...
 *
 * (b) int ix;
 *     for (; ix != sz; ++ix) { ... }
 *
 * (c) for (int ix = 0; ix != sz; ++ix) { ... }    //存在无限循环的可能。
 */

int main(void) {
    return 0;
}
